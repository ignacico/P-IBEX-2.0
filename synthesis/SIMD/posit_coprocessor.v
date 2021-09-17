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
	
	output 		conv_rvalid_o, // signal data valid, up to confirm in next step of request
	output [31:0]	conv_rdata_o   // output data serie bus 
);

assign conv_rvalid_o = correct_load | initialice_signal | correct_read;

// reg registro;
// wire cable;

localparam dir_void = 0;

/// params to load
localparam dir_a = 4;
localparam dir_b = 8;
localparam dir_op_code = 12;
localparam dir_start = 16;


wire write_req, read_req;

assign write_req = conv_req_i & conv_we_i;
assign read_req = conv_req_i & ~conv_we_i;

reg[1:0] state;
parameter stop = 0, load = 1, processing = 2, processed = 3;
reg initialice_signal;

// processed 
integer n_readed;
reg read_req_pending;
reg correct_read;
reg [31:0] output_temp;

// processing and result params
integer n_result;
reg [31:0] mem_result [4:0];

// load params
reg [1:0] op_code;

integer ops1;
integer results1;
wire [1:0] op_code_units;
reg start1, start2, start3, start4;
reg done1, done2, done3, done4;
reg [31:0] out1, out2, out3, out4;
reg [31:0] unit1_a, unit1_b, unit2_a, unit2_b, unit3_a, unit3_b, unit4_a, unit4_b; 

assign op_code_units = op_code;

wire i1,i2,i3,i4,z1,z2,z3,z4;

always @ (posedge clk_i or negedge rst_ni) 
begin
    if(~rst_ni)
    begin
    end
    else
    begin
        if(state != processed & read_req)
        begin
            read_req_pending <= 1;
            conv_rdata_o <= 0;
        end
        else if(state == processed & read_req_pending)
        begin
            read_req_pending <= 0;
            conv_rdata_o <= mem_result[n_readed];
            correct_read <= 1;
            n_readed <= n_readed+1;
        end
        else if(state == processed & read_req)
        begin
            conv_rdata_o <= mem_result[n_readed];
            n_readed <= n_readed+1;
            correct_read <= 1;
        end
        else 
        begin
            conv_rdata_o <= 0;
            conv_rdata_o <= 0;
            correct_read <= 0;
        end
    end
end


reg[1:0] next_mem_a, next_mem_b;
reg [31:0] mem1_opa [1:0];
reg [31:0] mem2_opa [1:0];
reg [31:0] mem3_opa [1:0];
reg [31:0] mem4_opa [1:0];
reg [31:0] mem1_opb [1:0];
reg [31:0] mem2_opb [1:0];
reg [31:0] mem3_opb [1:0];
reg [31:0] mem4_opb [1:0];
integer n1_a = 0, n2_a = 0, n3_a = 0, n4_a = 0;
integer n1_b = 0, n2_b = 0, n3_b = 0, n4_b = 0;
reg dummy;
reg correct_load;
// load process
always @ (posedge clk_i or negedge rst_ni) 
begin
    if(~rst_ni)
    begin
        n1_a <= 0;
        n2_a <= 0;
        n3_a <= 0;
        n4_a <= 0;
        n1_b <= 0;
        n2_b <= 0;
        n3_b <= 0;
        n4_b <= 0;
        op_code <= 0;
        next_mem_a <= 0;
        next_mem_b <= 0;
    end
    else
    begin
        if(state==load & write_req)
        begin
            if(conv_addr_i[15:0] == dir_op_code)begin
                op_code <= conv_wdata_i[1:0];
                correct_load <= 1;
            end
            else if (conv_addr_i[15:0] == dir_start)
            begin
                state <= processing;
                correct_load <= 1;
            end
            else if (conv_addr_i[15:0] == dir_a)begin
                case (next_mem_a)
                    0: begin
                        mem1_opa[n1_a] <= conv_wdata_i;
                        n1_a <= n1_a + 1;
                    end
                    1: begin
                        mem2_opa[n2_a] <= conv_wdata_i;
                        n2_a <= n2_a + 1;
                    end
                    2: begin
                        mem3_opa[n3_a] <= conv_wdata_i;
                        n3_a <= n3_a + 1;
                    end
                    3: begin
                        mem4_opa[n4_a] <= conv_wdata_i;
                        n4_a <= n4_a + 1;
                    end
                endcase
                next_mem_a <= next_mem_a + 1;
                correct_load <= 1;
            end
            else if (conv_addr_i[15:0] == dir_b)begin
                case (next_mem_b)
                    0: begin
                        mem1_opb[n1_b] <= conv_wdata_i;
                        n1_b <= n1_b + 1;
                    end
                    1: begin
                        mem2_opb[n2_b] <= conv_wdata_i;
                        n2_b <= n2_b + 1;
                    end
                    2: begin
                        mem3_opb[n3_b] <= conv_wdata_i;
                        n3_b <= n3_b + 1;
                    end
                    3: begin
                        mem4_opb[n4_b] <= conv_wdata_i;
                        n4_b <= n4_b + 1;
                    end
                endcase
                next_mem_b <= next_mem_b + 1;
                correct_load <= 1;
            end
        end
        else correct_load <= 0;
    end
end

// state process
always @(posedge clk_i or negedge rst_ni) begin
    if(~rst_ni) begin
        
    end
    else 
    if(state == stop & write_req & conv_addr_i[15:0] == dir_void) begin
        state <= load;
        n1_a <= 0;
        n2_a <= 0;
        n3_a <= 0;
        n4_a <= 0;
        n1_b <= 0;
        n2_b <= 0;
        n3_b <= 0;
        n4_b <= 0;
        op_code <= 0;
        next_mem_a <= 0;
        next_mem_b <= 0;
        initialice_signal <= 1;
        n_readed <= 0;
        n_result <= 0;
    end 
    else 
        initialice_signal <= 0;
end
always @ (posedge clk_i or negedge rst_ni) begin
    if(~rst_ni) begin
        state <= stop;
    end
    else 
    begin
        case(state)
            load: 
            begin
                if(write_req & conv_addr_i[15:0] == dir_void) begin
                    state <= processing;
                end
            end
            processing: 
            begin
                if(n1_a == 0 & ops1 == results1)
                begin
                    state <= processed;
                end
            end
            processed:
            begin
                if(n_readed == n_result)
                begin
                    state <= stop;
                end
            end
        endcase
    end
end

always @ (posedge clk_i or negedge rst_ni) begin
    if(~rst_ni) begin

    end
    else 
    begin
        if(done4) begin
            mem_result[n_result] <= out1;
            mem_result[n_result+1] <= out2;
            mem_result[n_result+2] <= out3;
            mem_result[n_result+3] <= out4;
            n_result <= n_result + 4;
        end
        else if(done3) begin
            mem_result[n_result] <= out1;
            mem_result[n_result+1] <= out2;
            mem_result[n_result+2] <= out3;
            n_result <= n_result + 3;
        end
        else if(done2) begin
            mem_result[n_result] <= out1;
            mem_result[n_result+1] <= out2;
            n_result <= n_result + 2;
        end
        else if(done1) begin
            mem_result[n_result] <= out1;
            n_result <= n_result + 1;
        end
        if(done1) begin
            results1 <= results1 + 1;
        end
    end
end

always @ (posedge clk_i or negedge rst_ni) begin
    if(~rst_ni) begin
        state <= stop;
    end
    else 
    begin
        if(state == processing) begin
            if(n1_a > 0 & n1_b > 0) begin
                start1 <= 1;
                unit1_a <= mem1_opa[n1_a-1];
                unit1_b <= mem1_opb[n1_b-1];
                n1_a <= n1_a - 1; 
                n1_b <= n1_b - 1;
                ops1 <= ops1 + 1;
            end
            else
            begin
                start1 <= 0;
                unit1_a <= 0;
                unit1_b <= 0;
            end
            if(n2_a > 0 & n2_b > 0) begin
                start2 <= 1;
                unit2_a <= mem2_opa[n2_a-1];
                unit2_b <= mem2_opb[n2_b-1];
                n2_a <= n2_a - 1; 
                n2_b <= n2_b - 1;
            end
            else 
            begin
                start2 <= 0;
                unit2_a <= 0;
                unit2_b <= 0;
            end
            if(n3_a > 0 & n3_b > 0) begin
                start3 <= 1;
                unit3_a <= mem3_opa[n3_a-1];
                unit3_b <= mem3_opb[n3_b-1];
                n3_a <= n3_a - 1; 
                n3_b <= n3_b - 1;
            end
            else 
            begin
                start3 <= 0;
                unit3_a <= 0;
                unit3_b <= 0;
            end
            if(n4_a > 0 & n4_b > 0) begin
                start4 <= 1;
                unit4_a <= mem4_opa[n4_a-1];
                unit4_b <= mem4_opb[n4_b-1];
                n4_a <= n4_a - 1; 
                n4_b <= n4_b - 1;
            end
            else 
            begin
                start4 <= 0;
                unit4_a <= 0;
                unit4_b <= 0;
            end
        end
        else 
        begin
            start1 <= 0; unit1_a <= 0; unit1_b <= 0;
            start2 <= 0; unit2_a <= 0; unit2_b <= 0;
            start3 <= 0; unit3_a <= 0; unit3_b <= 0;
            start4 <= 0; unit4_a <= 0; unit4_b <= 0;
        end
    end
end

posit_unit #() unit1
(
    .clk(clk_i),
    .rst_n(rst_ni),
    .op_code(op_code_units),
    .start (start1),
    .in1(unit1_a),
    .in2(unit1_b),

    .inf(i1),
    .zero(z1),
    .done (done1),
    .out (out1)
);
posit_unit #() unit2
(
    .clk(clk_i),
    .rst_n(rst_ni),
    .op_code(op_code_units),
    .start (start2),
    .in1(unit2_a),
    .in2(unit2_b),

    .inf(i2),
    .zero(z2),
    .done (done2),
    .out (out2)
);
posit_unit #() unit3
(
    .clk(clk_i),
    .rst_n(rst_ni),
    .op_code(op_code_units),
    .start (start3),
    .in1(unit3_a),
    .in2(unit3_b),

    .inf(i3),
    .zero(z3),
    .done (done3),
    .out (out3)
);
posit_unit #() unit4
(
    .clk(clk_i),
    .rst_n(rst_ni),
    .op_code(op_code_units),
    .start (start4),
    .in1(unit4_a),
    .in2(unit4_b),

    .inf(i4),
    .zero(z4),
    .done (done4),
    .out (out4)
);
endmodule

/*
always @ (posedge clk or posedge reset) begin
if (reset)
state <= S0;
else
case (state)
   S0:
      state <= S1;
   S1:
      if (in)
         state <= S2;
      else
         state <= S1;
   S2:
      if (in)
         state <= S0;
      else
         state <= S1;
endcase
end
endmodule
*/

/*
 posit_unit
(	input clk,
	input rst_n,
    input [1:0] op_code,
    input start,
    input [31:0] in1,
    input [31:0] in2,

    output inf,
    output zero,
    output done,
    output [31:0] out
);
*/
