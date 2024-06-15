


module Decoder (
    input   wire            i_clk,
    input   wire    [31:0]  i_opcode,
    output  reg             o_en_rd,
    output  reg     [4:0]   o_rd,
    output  reg             o_en_rs1,
    output  reg     [4:0]   o_rs1,
    output  reg             o_en_rs2,
    output  reg     [4:0]   o_rs2,
    output  reg             o_en_imm,
    output  reg     [31:0]  o_imm,
    output  reg             o_illegal_instruction
);
    reg     [6:0]   opcode;
    reg     [4:0]   rd;
    reg     [2:0]   funct3;
    reg     [4:0]   rs1;
    reg     [4:0]   rs2;
    reg     [6:0]   funct7;
    reg     [31:0]  imm;

    assign opcode   = i_opcode[6:0];
    assign rd       = i_opcode[11:7];
    assign funct3   = i_opcode[14:12];
    assign rs1      = i_opcode[19:15];
    assign rs2      = i_opcode[24:20];
    assign funct7   = i_opcode[31:25];

    parameter opcode_OP         = 7'b0110011;
    parameter opcode_OP_IMM     = 7'b0010011;
    parameter opcode_SYSTEM     = 7'b1110011;
    parameter opcode_AUIPC      = 7'b0010111;
    parameter opcode_LUI        = 7'b0110111;
    parameter opcode_JAL        = 7'b1101111;
    parameter opcode_JALR       = 7'b1100111;
    parameter opcode_BRANCH     = 7'b1100011;
    parameter opcode_LOAD       = 7'b0000011;
    parameter opcode_STORE      = 7'b0100011;


    function [31:0] signextend_imm12;
        input [11:0] imm12;
        input        sign;
    begin
        if (sign == 1) begin
            signextend_imm12 = {20'b11111111111111111111, imm12};
        end else begin
            signextend_imm12 = {20'b00000000000000000000, imm12};
        end
    end
    endfunction

    function [31:0] signextend_imm20;
        input [19:0] imm20;
        input        sign;
    begin
        if (sign == 1) begin
            signextend_imm20 = {12'b111111111111, imm20};
        end else begin
            signextend_imm20 = {12'b000000000000, imm20};
        end
    end
    endfunction

    always @(*) begin
        case(opcode)
            opcode_OP: begin
                o_en_rd             <= 1;
                o_rd                <= rd;
                o_en_rs1            <= 1;
                o_rs1               <= rs1;
                o_en_rs2            <= 1;
                o_rs2               <= rs2;
                o_en_imm            <= 0;
                o_illegal_instruction <= 0;
            end
            opcode_OP_IMM: begin
                o_en_rd             <= 1;
                o_rd                <= rd;
                o_en_rs1            <= 1;
                o_rs1               <= rs1;
                o_en_rs2            <= 0;
                o_en_imm            <= 1;
                o_imm               <= signextend_imm12(i_opcode[31:20], i_opcode[31]);
                o_illegal_instruction <= 0;
            end
            default: begin
                o_en_rd             <= 0;
                o_en_rs1            <= 0;
                o_en_rs2            <= 0;
                o_en_imm            <= 0;
                o_illegal_instruction <= 1;
            end
        endcase
    end

endmodule