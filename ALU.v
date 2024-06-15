

module ALU (
    input   wire            i_clk,
    input   wire    [31:0]  i_input_a,
    input   wire    [31:0]  i_input_b,
    input   wire    [2:0]   i_opcode,
    output  reg     [31:0]  o_result
);

    always @(posedge i_clk) begin
        case(i_opcode)
            // ADD
            3'b000: o_result <= i_input_a + i_input_b;
            // SLT
            3'b010: o_result <= $signed(i_input_a) < $signed(i_input_b) ? 1 : 0;
            // SLTU
            3'b011: o_result <= i_input_a < i_input_b ? 1 : 0;
            // XOR
            3'b100: o_result <= i_input_a ^ i_input_b;
            // SRL
            3'b101: o_result <= i_input_a >> i_input_b;
            // OR
            3'b110: o_result <= i_input_a | i_input_b;
            // AND
            3'b111: o_result <= i_input_a & i_input_b;
            default: o_result <= 32'h00000000;
        endcase
    end


endmodule