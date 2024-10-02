module Memory (
    input   wire            i_clk,
    input   wire            i_memread,
    input   wire    [31:0]  i_memaddr,
    output  reg     [31:0]  o_membus
);

    reg [31:0] memory [0:255];
    wire [31:0] addr;

    initial begin
        $readmemh("test.hex", memory);
    end

    always @(*) begin
        o_membus = memory[addr];
    end


    assign addr = (32'h80000000 <= i_memaddr && i_memaddr <= 32'h800003fc) ? (i_memaddr - 32'h80000000) >> 2 : 32'h00000000;
                                 

endmodule



module CPU_tb;
    reg             clk = 1'b0;
    wire            memwrite = 1'b0;
    wire            memread = 1'b1;
    wire    [31:0]  memaddr;
    wire    [31:0]  membus;
    reg             nreset = 1'b0;

    Memory mem (
        .i_clk      (clk),
        .i_memread  (memread),
        .i_memaddr  (memaddr),
        .o_membus   (membus)
    );

    cpu DUT (
        .i_clk      (clk),
        .i_nreset   (nreset),
        .o_memaddr  (memaddr),
        .o_memwrite (memwrite),
        .o_memread  (memread),
        .i_membus   (membus)
    );


    initial begin
        $dumpfile("CPU.vcd");
        $dumpvars(0);
    end

    always #1 begin
        clk = ~clk;
    end


    initial begin
        #2
        nreset = 1'b1;
        #16
        $finish;
    end


endmodule