`include "ALU.v"
`include "Decoder.v"
`include "RegFile.v"


module cpu (
    input   wire            i_clk,
    input   wire            i_nreset,
    inout   wire    [31:0]  b_membus,
    output  reg             o_memread,
    output  reg     [31:0]  o_memaddr
);
    reg     [31:0]  pc = 32'h80000000;
    reg     [31:0]  next_pc = 32'h80000000;
    reg             nreset = 1'b0;
    wire    [31:0]  data_addr;
    wire            memread;
    wire    [31:0]  memdata_write;
    wire    [31:0]  memdata_read;

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
    wire            load;
    wire            store;
    //reg           fetch = 1'b1;
    wire            fetch;

    initial begin
        o_memaddr  = 32'h00000000;
    end

    assign fetch        = ((load | store) & i_clk) ? 0 : 1;
    assign memread      = (fetch | load) ? 1 : 0;
    assign b_membus     = memread ? 'bz : memdata_write;
    assign memdata_read = memread ? b_membus : 32'h00000000;

    assign alu_input_a  = rs1data;
    assign alu_input_b  = en_imm ? imm : rs2data;
    assign data_addr    = alu_result;
    assign memdata_write= rs2data;

    // sw
    // - rising edge
    //   - alu_out  = store address
    //   - rs2      = store to be stored
    //   - store    = 1
    // - falling edge
    //   - 

    // lw
    // - rising edge 
    //   - rd       = register address to be stored
    //   - alu_out  = load address
    //   - load     = 1

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
        .o_load                 (load),
        .o_store                (store),
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
        o_memaddr = fetch ? pc : data_addr;
        o_memread = memread;
    end

    always @(posedge i_clk) begin
        if (!nreset) begin
        end
        else begin
            insn <= memdata_read;
        end
    end

    always @(negedge i_clk ) begin
        nreset = i_nreset;
        if (!nreset) begin
            pc <= 32'h80000000;
        end
        else if (illegal_instruction) begin
        end
        else begin
            case (jump)
                2'b00: begin
                    reg_wdata <= load ? memdata_read : alu_result;        // no jump
                    next_pc   <= pc + 4;
                end
                2'b01: begin
                    reg_wdata <= alu_result;        // jal
                    next_pc   <= jump_addr;
                end
                2'b10: begin
                    reg_wdata <= jump_addr;         // jalr
                    next_pc   <= alu_result;
                end
                2'b11: begin
                    reg_wdata <= alu_result;        // branch
                    if (cond) begin
                        next_pc <= jump_addr;
                    end else begin
                        next_pc <= pc + 4;
                    end
                end
            endcase
            pc <= next_pc;
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