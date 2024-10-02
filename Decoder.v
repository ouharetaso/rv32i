


module Decoder (
    input   wire    [31:0]  i_opcode,
    input   wire    [31:0]  i_pc,
    output  reg     [4:0]   o_rd,
    output  reg     [4:0]   o_rs1,
    output  reg     [4:0]   o_rs2,
    output  reg             o_en_imm,
    output  reg     [31:0]  o_imm,
    output  reg             o_en_jump,
    output  reg     [31:0]  o_jump_addr,
    output  reg     [3:0]   o_alu_op,
    output  reg     [1:0]   o_jump,
    output  reg             o_illegal_instruction
);
    wire    [6:0]   opcode;
    wire    [4:0]   rd;
    wire    [2:0]   funct3;
    wire    [4:0]   rs1;
    wire    [4:0]   rs2;
    wire    [6:0]   funct7;
    wire    [31:0]  I_immediate;
    wire    [31:0]  U_immediate;
    wire    [31:0]  J_immediate;
    wire    [31:0]  B_immediate;
    wire    [31:0]  S_immediate;
    
    

    initial begin
        o_rd                    = 0;
        o_rs1                   = 0;
        o_rs2                   = 0;
        o_en_imm                = 0;
        o_imm                   = 0;
        o_en_jump               = 0;
        o_jump_addr             = 0;
        o_alu_op                = 0;
        o_jump                  = 0;
        o_illegal_instruction   = 1;
    end

    assign opcode       = i_opcode[6:0];
    assign rd           = i_opcode[11:7];
    assign funct3       = i_opcode[14:12];
    assign rs1          = i_opcode[19:15];
    assign rs2          = i_opcode[24:20];
    assign funct7       = i_opcode[31:25];
    assign I_immediate  = i_opcode[31] ? {{20{1'b1}},i_opcode[31:20]} : {{20{1'b0}},i_opcode[31:20]};
    assign U_immediate  = {i_opcode[31:12],{12{1'b0}}};
    assign J_immediate  = i_opcode[31] ? {{12{1'b1}},i_opcode[19:12],i_opcode[20],i_opcode[30:25],i_opcode[24:21],1'b0}
                                       : {{12{1'b0}},i_opcode[19:12],i_opcode[20],i_opcode[30:25],i_opcode[24:21],1'b0};
    assign B_immediate  = i_opcode[31] ? {{20{1'b1}},i_opcode[7],i_opcode[30:25],i_opcode[11:8],1'b0}
                                       : {{20{1'b0}},i_opcode[7],i_opcode[30:25],i_opcode[11:8],1'b0};
    assign S_immediate  = i_opcode[31] ? {{20{1'b1}},i_opcode[31:25],i_opcode[11:8],i_opcode[7]}
                                       : {{20{1'b0}},i_opcode[31:25],i_opcode[11:8],i_opcode[7]};

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

    always @(*) begin
        case(opcode)
            opcode_OP: begin
                o_rd                    <= rd;
                o_rs1                   <= rs1;
                o_rs2                   <= rs2;
                o_en_imm                <= 0;
                o_alu_op                <= {funct7[5],funct3};
                o_en_jump               <= 0;
                o_jump                  <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_OP_IMM: begin
                o_rd                    <= rd;
                o_rs1                   <= rs1;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= (funct3 == 3'b001 || funct3 == 3'b101) ? 
                                           {{27{1'b0}},rs2} :                                     // for shift 
                                           I_immediate;
                o_alu_op                <= (funct3 == 3'b001 || funct3 == 3'b101) ? 
                                           {funct7[5],funct3} :                                   // for shift
                                           funct3;
                o_en_jump               <= 0;
                o_jump                  <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_AUIPC: begin
                o_rd                    <= rd;
                o_rs1                   <= 0;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= U_immediate;
                o_en_jump               <= 1;
                o_jump_addr             <= i_pc;
                o_alu_op                <= 4'b0000; // add
                o_jump                  <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_LUI: begin
                o_rd                    <= rd;
                o_rs1                   <= 0;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= U_immediate;
                o_en_jump               <= 0;
                o_jump_addr             <= 0;
                o_alu_op                <= 4'b0000; // add
                o_jump                  <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_JAL: begin
                o_rd                    <= rd;
                o_rs1                   <= 0;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= i_pc + 4;
                o_en_jump               <= 1;
                o_jump_addr             <= i_pc + J_immediate;
                o_alu_op                <= 4'b0000; // add
                o_jump                  <= 1;
                o_illegal_instruction   <= 0;
            end
            opcode_JALR: begin
                o_rd                    <= rd;
                o_rs1                   <= rs1;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= I_immediate;
                o_en_jump               <= 1;
                o_jump_addr             <= i_pc + 4;
                o_alu_op                <= 4'b0000; // add
                o_jump                  <= 2;
                o_illegal_instruction   <= 0;
            end
            opcode_BRANCH: begin
                o_rd                    <= 0;
                o_rs1                   <= rs1;
                o_rs2                   <= rs2;
                o_en_imm                <= 1;
                o_alu_op                <= {1'b1,-funct3};
                o_en_jump               <= 1;
                o_jump                  <= 3;
                o_illegal_instruction   <= 0;
            end
            default: begin
                o_rd                    <= 0;
                o_rs1                   <= 0;
                o_rs2                   <= 0;
                o_en_imm                <= 0;
                o_illegal_instruction   <= 1;
            end
        endcase
    end

endmodule