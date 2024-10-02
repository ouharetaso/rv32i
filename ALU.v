

module ALU (
    input   wire            i_clk,
    input   wire    [31:0]  i_input_a,
    input   wire    [31:0]  i_input_b,
    input   wire    [3:0]   i_alu_op,
    output  reg     [31:0]  o_result,
    output  reg             o_zero
);
    initial begin
        o_result = 32'h00000000;
        o_zero = 1'b0;
    end
    
    always @(posedge i_clk) begin
        case(i_alu_op[3:0])
            // ADD
            4'b0000: o_result <= i_input_a + i_input_b ;
            // SLL
            4'b0001: o_result <= i_input_a << i_input_b[4:0];
            // SLT
            4'b0010: o_result <= $signed(i_input_a) < $signed(i_input_b) ? 1 : 0;
            // SLTU
            4'b0011: o_result <= i_input_a < i_input_b ? 1 : 0;
            // XOR
            4'b0100: o_result <= i_input_a ^ i_input_b;
            // SRL
            4'b0101: o_result <= i_input_a >> i_input_b[4:0];
            // OR
            4'b0110: o_result <= i_input_a | i_input_b;
            // AND
            4'b0111: o_result <= i_input_a & i_input_b;
            // SUB
            4'b1000: o_result <= i_input_a - i_input_b ;
            // SRA
            4'b1101: o_result <= $signed(i_input_a) >>> i_input_b[4:0];
            // BNE
            4'b1111: o_result <= i_input_a != i_input_b ? 0 : 1;
            // BLT
            4'b1100: o_result <= $signed(i_input_a) < $signed(i_input_b) ? 0 : 1;
            // BGE
            4'b1011: o_result <= $signed(i_input_a) >= $signed(i_input_b) ? 0 : 1;
            // BLTU
            4'b1010: o_result <= i_input_a < i_input_b ? 0 : 1;
            // BGEU
            4'b1001: o_result <= i_input_a >= i_input_b ? 0 : 1;
            default: o_result <= 32'h00000000;
        endcase
        o_zero <= o_result == 32'h00000000;
    end

endmodule