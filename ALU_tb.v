module alu_tb;
    reg             clk         = 1'b0;
    reg     [31:0]  input_a     = 32'h00000000;
    reg     [31:0]  input_b     = 32'h00000000;
    reg     [3:0]   opcode      = 4'b0000;
    wire    [31:0]  out;
    wire            zero;


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
        .i_alu_op   (opcode),
        .o_result   (out),
        .o_zero     (zero)
    );

    initial begin
        // ADD
        input_a = 32'h0000adde;
        input_b = 32'hefbe0000;
        opcode  = 4'b0000;
        #2
        // SLL
        input_a = 32'h0000ffff;
        input_b = 32'hffffff0c;
        opcode = 4'b0001;
        #2
        // SLT
        input_a = 32'hfffc0000;
        input_b = 32'h7fffffff;
        opcode = 4'b0010;
        #2
        // SLTU
        input_a = 32'hfffc0000;
        input_b = 32'h7fffffff;
        opcode = 4'b0011;
        #2
        // XOR
        input_a = 32'h5555aaaa;
        input_b = 32'haaaaffff;
        opcode = 4'b0100;
        #2
        // SRL
        input_a = 32'hffff0000;
        input_b = 32'hffffff0c;
        opcode = 4'b0101;
        #2
        // OR
        input_a = 32'h5555001c;
        input_b = 32'haaaa007f;
        opcode = 4'b0110;
        #2
        // AND
        input_a = 32'h5555001c;
        input_b = 32'haaaa007f;
        opcode = 4'b0111;
        #2
        // SUB
        input_a = 32'haaaa007f;
        input_b = 32'h5555001c;
        opcode = 4'b1000;
        #2
        // SRA
        input_a = 32'hffff0000;
        input_b = 32'hffffff0c;
        opcode = 4'b1101;
        #2
        #1
        $finish;
    end


endmodule