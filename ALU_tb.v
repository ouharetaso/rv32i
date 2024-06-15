module alu_tb;
    reg             clk         = 1'b0;
    reg     [31:0]  input_a     = 32'h00000000;
    reg     [31:0]  input_b     = 32'h00000000;
    reg     [2:0]   opcode      = 1'b0;
    wire    [31:0]  out;

    initial begin
        $dumpfile("ALU.vcd");
        $dumpvars(0, DUT);
    end

    always #1 begin
        clk <= ~clk;
    end


    ALU DUT (
        .i_clk      (clk),
        .i_input_a  (input_a),
        .i_input_b  (input_b),
        .i_opcode   (opcode),
        .o_result   (out)
    );

    initial begin
        #2
        input_a = 32'h0000adde;
        input_b = 32'hefbe0000;
        opcode  = 3'b000;
        #2
        input_a = 32'h0000adde;
        input_b = 32'hefbe0000;
        opcode  = 3'b000;
        #2
        $finish;
    end


endmodule