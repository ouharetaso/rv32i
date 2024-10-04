module Memory (
    input   wire            i_clk,
    input   wire            i_memread,
    input   wire    [31:0]  i_memaddr,
    inout   wire    [31:0]  b_membus
);

    reg [31:0] memory [0:255];
    wire [31:0] addr;
    wire [31:0] data_0x40;

    
    assign data_0x40 = memory[8'h40];

    initial begin
        $readmemh("test.hex", memory);
    end

    always @(negedge i_memread) begin
        if (!i_memread) begin
            memory[addr] = b_membus;
        end
    end

    assign b_membus = i_memread ? memory[addr] : 'bz;
    assign addr = (32'h80000000 <= i_memaddr && i_memaddr <= 32'h800003fc) ? (i_memaddr - 32'h80000000) >> 2 : 32'h00000000;
                                 

endmodule



module CPU_tb;
    reg             clk = 1'b0;
    wire            memwrite;
    wire            memread;
    wire    [31:0]  memaddr;
    wire    [31:0]  membus;
    reg             nreset = 1'b0;

    Memory mem (
        .i_clk      (clk),
        .i_memread  (memread),
        .i_memaddr  (memaddr),
        .b_membus   (membus)
    );

    cpu DUT (
        .i_clk      (clk),
        .i_nreset   (nreset),
        .o_memaddr  (memaddr),
        .o_memread  (memread),
        .b_membus   (membus)
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
        //#1
        nreset = 1'b1;
        #160
        $finish;
    end


endmodule