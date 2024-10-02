module decoder_tb;
    reg             clk        = 1'b0;
    reg     [31:0]  opcode     = 32'h00000000;
    reg     [31:0]  pc         = 32'h80000000;
    wire    [4:0]   rd;
    wire    [4:0]   rs1;
    wire    [4:0]   rs2;
    wire            en_imm;
    wire    [31:0]  imm;
    wire            en_jump;
    wire    [31:0]  jump_addr;
    wire    [3:0]   alu_op;
    wire    [1:0]   jump;
    wire            illegal_instruction;


    initial begin
        $dumpfile("Decoder.vcd");
        $dumpvars(0, DUT);
    end

    always #1 begin
        clk <= ~clk;
    end


    Decoder DUT (
        .i_opcode               (opcode),
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

    initial begin
        // addi x0, x0, 0 (nop)
        opcode = 32'h00000013; 
        #2
        // slli x1, x15, 0xc
        opcode = 32'h00c79093;
        #2
        // slti x2, x15, -768
        opcode = 32'hd007a113;
        #2
        // sltiu x3, x15, 0x800
        opcode = 32'h8007b193;
        #2
        // xori x4, x15, 0x800
        opcode = 32'h8007c213;
        #2
        // srli x5, x15, 0xc
        opcode = 32'h00c7d293;
        #2
        // ori x6, x15, 0x800
        opcode = 32'h8007e313;
        #2
        // andi x7, x15, 0x800
        opcode = 32'h8007f393;
        #2
        // srai x13, x15, 0xc
        opcode = 32'h40c7d693;
        #2
        // add x8, x31, x16
        opcode = 32'h010f8433;
        #2
        // sll x9, x31, x17
        opcode = 32'h011f94b3;
        #2
        // slt x10, x31, x18
        opcode = 32'h012fa533;
        #2
        // sltu x11, x31, x19
        opcode = 32'h013fb5b3;
        #2
        // xor x12, x31, x20
        opcode = 32'h014fc633;
        #2
        // srl x13, x31, x21
        opcode = 32'h015fd6b3;
        #2
        // or x14, x31, x22
        opcode = 32'h016fe733;
        #2
        // and x15, x31, x23
        opcode = 32'h017ff7b3;
        #2
        // sub x16, x31, x24
        opcode = 32'h418f8833;
        #2
        // auipc x27, 0
        opcode = 32'h00000d97;
        #2
        // addi x1, x1, 0x678
        opcode = 32'h67808093;
        #2
        #1
        $finish;
    end




endmodule

