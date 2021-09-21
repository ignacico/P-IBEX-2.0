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
	
	output logic		conv_rvalid_o, // signal data valid
	output logic [31:0]	conv_rdata_o   // output data serie bus 
);
	parameter N = 32; 
	parameter es = 6;

	localparam bit [9:0] code_op_a = 0; 	
	localparam bit [9:0] code_op_b = 8;	
	localparam bit [9:0] code_op_output = 16; 

	localparam bit [1:0] code_add = 1;
	localparam bit [1:0] code_mul = 2;
	localparam bit [1:0] code_div = 3;

	reg start_add, start_mul, start_div;
	wire inf_add, inf_mul, inf_div;
	wire zero_add, zero_mul, zero_div;
	wire done_add, done_mul, done_div;

	wire [N-1:0] out_add, out_mul, out_div;
	
	reg to_process, processing;
	reg valid_read, valid_write;
	//assign conv_rvalid_o = rvalid;

	reg [N-1:0] op_a;
	reg [N-1:0] op_b;
	// reg [N-1:0] op_output;
	reg [1:0] op_code;


	// control signals
	always_ff @(posedge clk_i or negedge rst_ni) 
	begin
		if(~rst_ni) 
		begin
			op_a 		<= 0;
			op_b 		<= 0;
			op_code		<= 0;
			to_process 	<= 0;
			processing 	<= 0;
			valid_write <= 0;
		end 
		else if (conv_we_i & conv_req_i)
		begin
			if (conv_addr_i[4:0] == code_op_a)
			begin
				op_a <= conv_wdata_i;
				valid_write <= 1;
			end
			else if (conv_addr_i[4:0] == code_op_b)
			begin
				op_b <= conv_wdata_i;
				valid_write <= 1;
			end
			else if (conv_addr_i[4:0] == code_op_output)
			begin
				if(~processing)
				begin
					op_code 		<= conv_wdata_i[1:0];
					valid_write 	<= 1; 
					to_process 		<= 1;
				end
			end
			else 
			begin
				valid_write <= 0; 
			end
		end
		else 
		begin
			valid_write <= 0; 
			if(to_process) processing <= 1;
			if(done_add | done_div | done_mul) processing <= 0; 
			to_process <= 0;
		end
	end

	// start calculus
	always_comb
	begin 
		if(~rst_ni)
		begin
			start_add <= 0;
			start_mul <= 0;
			start_div <= 0;
		end
		else 
		begin
			if(to_process)
			begin
				unique case(op_code)
				code_add: 
				begin 
					start_add <= 1; 
					start_mul <= 0;
					start_div <= 0;
				end
				code_mul: 
				begin 
					start_mul <= 1; 
					start_add <= 0;
					start_div <= 0;
				end 
				code_div: 
				begin 
					start_div <= 1; 
					start_add <= 0;
					start_mul <= 0;
				end 
				default: 
				begin
					start_add <= 0;
					start_mul <= 0;
					start_div <= 0;
				end
				endcase
			end
			else
			begin
				start_add <= 0;
				start_mul <= 0;
				start_div <= 0;
			end
		end
	end

	// get output
	always_comb
	begin
		if(!rst_ni) 
		begin
			conv_rvalid_o <= 0;
			conv_rdata_o <= 0;
			valid_read <= 0;
		end 
		else
		begin
			conv_rvalid_o <= valid_read | valid_write;

			if(processing)
			begin
				unique case(op_code)
				code_add: 
				begin 
					if(done_add)
					begin
						conv_rdata_o <= out_add;
						valid_read <= 1;
					end
					else 
					begin
						conv_rdata_o <= 0;
						valid_read <= 0;
					end
				end 
				code_mul: 
				begin 
					if(done_mul)
					begin
						conv_rdata_o <= out_mul;
						valid_read <= 1;
					end
					else 
					begin
						conv_rdata_o <= 0;
						valid_read <= 0;
					end
				end 
				code_div: 
				begin 
					if(done_div)
					begin
						conv_rdata_o <= out_div;
						valid_read <= 1;
					end
					else 
					begin
						conv_rdata_o <= 0;
						valid_read <= 0;
					end
				end 
				default: 
				begin
					conv_rdata_o <= 0;
					valid_read <= 0;
				end
				endcase
			end
			else 
			begin
				conv_rdata_o <= 0;
				valid_read <= 0;
			end
		end
	end

	add_N32_ES6_PIPE5 #() adder
	(.clk 	(clk_i), 
	 .in1 	(op_a), 
	 .in2 	(op_b), 
	 .start (start_add), 
	 .out 	(out_add), 
	 .inf 	(inf_add), 
	 .zero 	(zero_add), 
	 .done	(done_add)
	);

	mult_N32_ES6_PIPE6 #() mutlier
	(.clk 	(clk_i), 
	 .in1 	(op_a), 
	 .in2 	(op_b), 
	 .start (start_mul), 
	 .out 	(out_mul), 
	 .inf 	(inf_mul), 
	 .zero 	(zero_mul), 
	 .done	(done_mul)
	);

	div_N32_ES6_PIPE12 #() divisor
	(.clk 	(clk_i), 
	 .in1 	(op_a), 
	 .in2 	(op_b), 
	 .start (start_div), 
	 .out 	(out_div), 
	 .inf 	(inf_div), 
	 .zero 	(zero_div), 
	 .done	(done_div)
	);

endmodule