


module Decoder (
    input   wire    [31:0]  i_opcode,
    input   wire    [31:0]  i_pc,
    output  wire    [4:0]   o_rd,
    output  wire    [4:0]   o_rs1,
    output  wire    [4:0]   o_rs2,
    output  wire            o_en_imm,
    output  wire    [31:0]  o_imm,
    output  wire            o_en_jump,
    output  wire    [31:0]  o_jump_addr,
    output  wire    [3:0]   o_alu_op,
    output  wire    [1:0]   o_jump,
    output  wire            o_load,
    output  wire            o_store,
    output  wire            o_illegal_instruction
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
    
    /*
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
        o_load                  = 0;
        o_store                 = 0;
        o_illegal_instruction   = 1;
    end
    */

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

    assign o_rd                 = (opcode == opcode_OP      || opcode == opcode_OP_IMM  || opcode == opcode_LUI || opcode == opcode_JAL ||
                                   opcode == opcode_JALR    || opcode == opcode_AUIPC   || opcode == opcode_JAL) ? rd : 0;

    assign o_rs1                = (opcode == opcode_OP      || opcode == opcode_OP_IMM  || opcode == opcode_JALR || opcode == opcode_BRANCH ||
                                   opcode == opcode_LOAD    || opcode == opcode_STORE) ? rs1 : 0;

    assign o_rs2                = (opcode == opcode_OP      || opcode == opcode_BRANCH  || opcode == opcode_STORE) ? rs2 : 0;

    assign o_en_imm             = (opcode == opcode_OP_IMM  || opcode == opcode_AUIPC   || opcode == opcode_LUI || opcode == opcode_JAL ||
                                   opcode == opcode_JALR    || opcode == opcode_LOAD    || opcode == opcode_STORE) ? 1 : 0;

    assign o_imm                = (opcode == opcode_AUIPC   || opcode == opcode_LUI) ? U_immediate :
                                  (opcode == opcode_JALR    || opcode == opcode_LOAD) ? I_immediate : 
                                  (opcode == opcode_OP_IMM) ? ((funct3 == 3'b001 || funct3 == 3'b101) ? {{27{1'b0}},rs2} : I_immediate) :
                                  (opcode == opcode_JAL) ? i_pc + 4 : 
                                  (opcode == opcode_STORE) ? S_immediate : 0;
    
    assign o_en_jump            = (opcode == opcode_AUIPC   || opcode == opcode_BRANCH  || opcode == opcode_JAL || opcode == opcode_JALR)
                                ? 1 : 0;
    
    assign o_jump_addr          = (opcode == opcode_AUIPC   || opcode == opcode_JAL || opcode == opcode_JALR) ? 
                                  ((opcode == opcode_JAL) ? i_pc + J_immediate : i_pc) : i_pc + B_immediate;
    
    assign o_alu_op             = (opcode == opcode_OP      || opcode == opcode_OP_IMM) ? 
                                  ((funct3 == 3'b001 || funct3 == 3'b101) ? {funct7[5],funct3} : funct3) : 
                                  (opcode == opcode_BRANCH) ? {1'b1,-funct3} : 4'b0000;

    assign o_jump               = (opcode == opcode_JAL) ? 1 : 
                                  (opcode == opcode_JALR) ? 2 : 
                                  (opcode == opcode_BRANCH) ? 3 : 0;
    
    assign o_load               = (opcode == opcode_LOAD) ? 1 : 0;

    assign o_store              = (opcode == opcode_STORE) ? 1 : 0;
    
    assign o_illegal_instruction= (opcode == opcode_OP || opcode == opcode_OP_IMM || opcode == opcode_SYSTEM || opcode == opcode_AUIPC ||
                                   opcode == opcode_LUI || opcode == opcode_JAL || opcode == opcode_JALR || opcode == opcode_BRANCH ||
                                   opcode == opcode_LOAD || opcode == opcode_STORE) ? 0 : 1;
    
    /*
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
                o_load                  <= 0;
                o_store                 <= 0;
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
                o_load                  <= 0;
                o_store                 <= 0;
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
                o_load                  <= 0;
                o_store                 <= 0;
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
                o_load                  <= 0;
                o_store                 <= 0;
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
                o_load                  <= 0;
                o_store                 <= 0;
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
                o_load                  <= 0;
                o_store                 <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_BRANCH: begin
                o_rd                    <= 0;
                o_rs1                   <= rs1;
                o_rs2                   <= rs2;
                o_en_imm                <= 0;
                o_alu_op                <= {1'b1,-funct3};
                o_en_jump               <= 1;
                o_jump_addr             <= i_pc + B_immediate;
                o_jump                  <= 3;
                o_load                  <= 0;
                o_store                 <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_LOAD: begin
                o_rd                    <= rd;
                o_rs1                   <= rs1;
                o_rs2                   <= 0;
                o_en_imm                <= 1;
                o_imm                   <= I_immediate;
                o_alu_op                <= 4'b0000; // add
                o_en_jump               <= 0;
                o_jump_addr             <= 0;
                o_jump                  <= 0;
                o_load                  <= 1;
                o_store                 <= 0;
                o_illegal_instruction   <= 0;
            end
            opcode_STORE: begin
                o_rd                    <= 0;
                o_rs1                   <= rs1;
                o_rs2                   <= rs2;
                o_en_imm                <= 1;
                o_imm                   <= S_immediate;
                o_alu_op                <= 4'b0000; // add
                o_en_jump               <= 0;
                o_jump_addr             <= 0;
                o_jump                  <= 0;
                o_load                  <= 0;
                o_store                 <= 1;
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
    */

endmodule