// Copyright Ignacio.
// Licensed under BSD 3-Clause License, see LICENSE for details.

module posit_coprocessor
#( ) 
(
	input				clk_i,
	input				rst_ni,

	input [3:0]			conv_be_i,     // byte enable signal

	input				conv_req_i,    // instruction request control
	input [31:0]		conv_addr_i,   // destiny of bus signal

	input				conv_we_i,     // write enable signal
	input [31:0]		conv_wdata_i,  // data serie bus
	
	output logic		conv_rvalid_o, // signal data valid, up to confirm in next step of request
	output logic [31:0]	conv_rdata_o   // output data serie bus 
);

assign conv_rvalid_o = correct_load | correct_read;

localparam dir_void = 0;

/// params to load
localparam dir_a = 4;
localparam dir_b = 8;
localparam dir_op_code = 12;
localparam dir_add = 16;
localparam dir_mul = 20;
localparam dir_div = 24;

wire write_req, read_req;

assign write_req = conv_req_i & conv_we_i;
assign read_req = conv_req_i & ~conv_we_i;

reg start;
reg [31:0] in1, in2;
reg [1:0] op_code;
reg [2:0] wait_cycles;
reg correct_load;

wire [31:0] out_add, out_mul, out_div;
wire start_add, start_mul, start_div;
wire zero_add, zero_mul, zero_div;
wire inf_add, inf_mul, inf_div;

assign start_add = (start & op_code == 1) ? 1 : 0;
assign start_mul = (start & op_code == 2) ? 1 : 0;
assign start_div = (start & op_code == 3) ? 1 : 0;

always @(posedge clk_i or negedge rst_ni) begin
    if(~rst_ni)
    begin
        
    end
    else
    begin
        if(write_req)
        begin
            if(conv_addr_i[15:0] == dir_op_code)
            begin
                op_code <= conv_wdata_i[1:0];
                correct_load <= 1;
                start <= 0;
            end
            else if(conv_addr_i[15:0] == dir_a)
            begin
                in1 <= conv_wdata_i;
                correct_load <= 1;
                start <= 0;
            end
            else if(conv_addr_i[15:0] == dir_b)
            begin
                in2 <= conv_wdata_i;
                correct_load <= 1;
                start <= 1;
            end
            else
            begin
                correct_load <= 0;
                start <= 0;
            end
        end
        else
        begin
            correct_load <= 0;
            start <= 0;
        end
    end
end


integer first_add=0, next_add=0;
integer first_mul=0, next_mul=0;
integer first_div=0, next_div=0;

reg [31:0] mem_result_add [32:0];
reg [31:0] mem_result_mul [32:0];
reg [31:0] mem_result_div [32:0];


always @(posedge clk_i or negedge rst_ni) begin
    if(~rst_ni)
    begin
        
    end
    else
    begin
        if(done_add)
        begin
            mem_result_add[next_add] <= out_add;
            if(next_add >= 32) next_add <= 0;
            else next_add <= next_add + 1;
        end
        else 
        begin
            mem_result_add[next_add] <= 0;
            next_add <= next_add;
        end

        if(done_mul)
        begin
            mem_result_mul[next_mul] <= out_mul;
            next_mul <= next_mul + 1;
            if(next_mul >= 32) next_mul <= 0;
            else next_mul <= next_mul + 1;
        end
        else 
        begin
            mem_result_mul[next_mul] <= 0;
            next_mul <= next_mul;
        end

        if(done_div)
        begin
            mem_result_div[next_div] <= out_div;
            next_div <= next_div + 1;
            if(next_div >= 32) next_div <= 0;
            else next_div <= next_div + 1;
        end
        else 
        begin
            mem_result_div[next_div] <= 0;
            next_div <= next_div;
        end

    end
end

reg correct_read, correct_read_add, correct_read_mul, correct_read_div ;
reg req_add_pending, req_mul_pending, req_div_pending;
reg [31:0] add_read,mul_read,div_read;
assign correct_read = correct_read_add | correct_read_mul | correct_read_div;
always @(posedge clk_i or negedge rst_ni) begin
    if(~rst_ni)
    begin
        
    end
    else
    begin
        if(read_req & dir_add == conv_addr_i[15:0] & first_add == next_add)
        begin
            req_add_pending <= 1;
            add_read <= 0;
            correct_read_add <= 0;
            first_add <= first_add;
        end
        else if( (req_add_pending & first_add != next_add) | 
                 (read_req & dir_add == conv_addr_i[15:0] & first_add != next_add) )
        begin
            req_add_pending <= 0;
            add_read <= mem_result_add[first_add];
            correct_read_add <= 1;
            if(first_add >= 32) first_add <= 0;
            else first_add <= first_add + 1;
        end
        else
        begin
            add_read <= 0;
            correct_read_add <= 0;
            first_add <= first_add;
        end


        if(read_req & dir_mul == conv_addr_i[15:0] & first_mul == next_mul)
        begin
            req_mul_pending <= 1;
            mul_read <= 0;
            correct_read_mul <= 0;
            first_mul <= first_mul;
        end
        else if( (req_mul_pending & first_mul != next_mul) | 
                 (read_req & dir_mul == conv_addr_i[15:0] & first_mul != next_mul) )
        begin
            req_mul_pending <= 0;
            mul_read <= mem_result_mul[first_mul];
            correct_read_mul <= 1;
            first_mul <= first_mul + 1;
            if(first_mul >= 32) first_mul <= 0;
            else first_mul <= first_mul + 1;
        end
        else
        begin
            mul_read <= 0;
            correct_read_mul <= 0;
            first_mul <= first_mul;
        end


        if(read_req & dir_div == conv_addr_i[15:0] & first_div == next_div)
        begin
            req_div_pending <= 1;
            div_read <= 0;
            correct_read_div <= 0;
            first_div <= first_div;
        end
        else if( (req_div_pending & first_div != next_div) | 
                 (read_req & dir_div == conv_addr_i[15:0] & first_div != next_div) )
        begin
            req_div_pending <= 0;
            div_read <= mem_result_div[first_div];
            correct_read_div <= 1;
            first_div <= first_div + 1;
            if(first_div >= 32) first_div <= 0;
            else first_div <= first_div + 1;
        end
        else
        begin
            div_read <= 0;
            correct_read_div <= 0;
            first_div <= first_div;
        end
    end
end
always @(*) begin
    if(correct_read_add)
        conv_rdata_o <= add_read;
    else if(correct_read_mul)
        conv_rdata_o <= mul_read;
    else if(correct_read_div)
        conv_rdata_o <= div_read;
    else 
        conv_rdata_o <= 0;
end


add_N32_ES6_PIPE5 #() adder
(   .clk 	(clk_i), 
    .in1 	(in1), 
    .in2 	(in2), 
    .start (start_add), 
    .out 	(out_add), 
    .inf 	(inf_add), 
    .zero 	(zero_add), 
    .done	(done_add)
);

mult_N32_ES6_PIPE6 #() mutlier
(   .clk 	(clk_i), 
    .in1 	(in1), 
    .in2 	(in2), 
    .start (start_mul), 
    .out 	(out_mul), 
    .inf 	(inf_mul), 
    .zero 	(zero_mul), 
    .done	(done_mul)
);

div_N32_ES6_PIPE12 #() divisor
(   .clk 	(clk_i), 
    .in1 	(in1), 
    .in2 	(in2), 
    .start (start_div), 
    .out 	(out_div), 
    .inf 	(inf_div), 
    .zero 	(zero_div), 
    .done	(done_div)
);
endmodule

