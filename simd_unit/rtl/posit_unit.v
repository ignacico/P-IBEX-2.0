// Copyright Ignacio.
// Licensed under BSD 3-Clause License, see LICENSE for details.

module posit_unit
#()
(
	input clk,
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

    wire [31:0] out_add, out_mul, out_div;
    wire start_add, start_mul, start_div;
    wire zero_add, zero_mul, zero_div;
    wire inf_add, inf_mul, inf_div;
	reg [31:0] out_wire;

    assign start_add = (start & op_code == 1) ? 1 : 0;
    assign start_mul = (start & op_code == 2) ? 1 : 0;
    assign start_div = (start & op_code == 3) ? 1 : 0;

    assign done = done_add | done_mul | done_div;
    assign zero = zero_add | zero_mul | zero_div;
    assign inf = inf_add | inf_mul | inf_div;
	assign out = out_wire;

    add_N32_ES6_PIPE5 #() adder
	(.clk 	(clk), 
	 .in1 	(in1), 
	 .in2 	(in2), 
	 .start (start_add), 
	 .out 	(out_add), 
	 .inf 	(inf_add), 
	 .zero 	(zero_add), 
	 .done	(done_add)
	);

	mult_N32_ES6_PIPE6 #() mutlier
	(.clk 	(clk), 
	 .in1 	(in1), 
	 .in2 	(in2), 
	 .start (start_mul), 
	 .out 	(out_mul), 
	 .inf 	(inf_mul), 
	 .zero 	(zero_mul), 
	 .done	(done_mul)
	);

	div_N32_ES6_PIPE12 #() divisor
	(.clk 	(clk), 
	 .in1 	(in1), 
	 .in2 	(in2), 
	 .start (start_div), 
	 .out 	(out_div), 
	 .inf 	(inf_div), 
	 .zero 	(zero_div), 
	 .done	(done_div)
	);

    always @*
    begin
        if     (done_add) out_wire <= out_add;
        else if(done_mul) out_wire <= out_mul;
        else if(done_div) out_wire <= out_div;
        else out_wire <= 0;
    end
endmodule