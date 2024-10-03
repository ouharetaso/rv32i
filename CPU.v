`include "ALU.v"
`include "Decoder.v"
`include "RegFile.v"


module cpu (
    input   wire            i_clk,
    input   wire            i_nreset,
    input   wire    [31:0]  i_membus,
    output  reg             o_memwrite,
    output  reg             o_memread,
    output  reg     [31:0]  o_memaddr
);
    reg     [31:0]  pc = 32'h80000000;    

    reg     [31:0]  insn = 32'h00000000;
    wire    [4:0]   rd;
    wire    [4:0]   rs1;
    wire    [31:0]  rs1data;
    wire    [4:0]   rs2;
    wire    [31:0]  rs2data;
    wire            en_imm;
    wire    [31:0]  imm;
    wire            en_jump;
    wire    [31:0]  jump_addr;
    wire    [3:0]   alu_op;
    wire    [1:0]   jump;
    wire            illegal_instruction;
    wire    [31:0]  alu_result;
    reg     [31:0]  reg_wdata   = 32'h00000000;
    wire    [31:0]  alu_input_a;
    wire    [31:0]  alu_input_b;
    wire            cond;
    reg             fetch = 1'b1;

    initial begin
        o_memwrite = 1'b0;
        o_memread  = 1'b1;
        o_memaddr  = 32'h00000000;
    end

    assign alu_input_a = rs1data;
    assign alu_input_b = en_imm ? imm : rs2data;

    RegFile reg_file (
        .i_clk      (i_clk),
        .i_wdata    (reg_wdata),
        .i_waddr    (rd),
        .o_r1data   (rs1data),
        .i_r1addr   (rs1),
        .o_r2data   (rs2data),
        .i_r2addr   (rs2)
    );

    Decoder decoder (
        .i_opcode               (insn),
        .i_pc                   (pc),
        .o_rd                   (rd),
        .o_rs1                  (rs1),
        .o_rs2                  (rs2),
        .o_en_imm               (en_imm),
        .o_imm                  (imm),
        .o_en_jump              (en_jump),
        .o_jump_addr            (jump_addr),
        .o_alu_op               (alu_op),
        .o_jump                 (jump),
        .o_illegal_instruction  (illegal_instruction)
    );

    ALU alu (
        .i_clk      (i_clk),
        .i_alu_op   (alu_op),
        .i_input_a  (rs1data),
        .i_input_b  (alu_input_b),
        .o_result   (alu_result),
        .o_zero     (cond)
    );

    always @(*) begin
        o_memaddr = fetch ? pc : 32'h00000000;
    end

    always @(posedge i_clk) begin
        if (!i_nreset) begin
            pc <= 32'h80000000;
        end
        else begin
            insn <= i_membus;
        end
    end

    always @(negedge i_clk) begin
        if (!i_nreset) begin
            pc <= 32'h80000000;
        end
        else begin
            case (jump)
                2'b00: begin
                    reg_wdata <= alu_result;        // no jump
                    pc        <= pc + 4;
                end
                2'b01: begin
                    reg_wdata <= alu_result;        // jal
                    pc        <= jump_addr;
                end
                2'b10: begin
                    reg_wdata <= jump_addr;         // jalr
                    pc        <= alu_result;
                end
                2'b11: begin
                    reg_wdata <= alu_result;        // branch
                    if (cond) begin
                        pc <= jump_addr;
                    end else begin
                        pc <= pc + 4;
                    end
                end
            endcase
        end
    end

    /*
    always @(posedge i_clk or negedge i_nreset) begin
        if (!i_nreset) begin
            pc <= 32'h80000000;
        end
        else begin
            case (jump)
                2'b00: begin
                    reg_wdata <= alu_result;        // no jump
                    pc        <= pc + 4;
                end
                2'b01: begin
                    reg_wdata <= alu_result;        // jal
                    pc        <= jump_addr;
                end
                2'b10: begin
                    reg_wdata <= jump_addr;         // jalr
                    pc        <= alu_result;
                end
                2'b11: begin
                    reg_wdata <= alu_result;        // branch
                    if (cond) begin
                        pc <= jump_addr;
                    end else begin
                        pc <= pc + 4;
                    end
                end
            endcase
            o_memaddr = pc;
            insn      = i_membus;
        end
    end
    */


endmodule