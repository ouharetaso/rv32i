module RegFile_tb;
    reg             clk         = 1'b0;
    reg     [31:0]  wdata       = 32'h00000000;
    reg     [4:0]   waddr       = 32'h00000000;
    wire    [31:0]  r1data;
    reg     [4:0]   r1addr      = 32'h00000000;
    wire    [31:0]  r2data;
    reg     [4:0]   r2addr      = 32'h00000000;


    initial begin
        $dumpfile("RegFile.vcd");
        $dumpvars(0, DUT);
    end

    always #1 begin
        clk <= ~clk;
    end


    RegFile DUT (
        .i_clk      (clk),
        .i_wdata    (wdata),
        .i_waddr    (waddr),
        .o_r1data   (r1data),
        .i_r1addr   (r1addr),
        .o_r2data   (r2data),
        .i_r2addr   (r2addr)       
    );

    initial begin
        waddr = 5'h12;
        wdata = 32'hdeadbeef;
        r1addr = 5'h12;
        r2addr = 5'h12;
        #2
        waddr = 5'h13;
        wdata = 32'hbabecafe;
        #2
        r1addr = 5'h12;
        r2addr = 5'h13;        
        #2
        waddr = 5'h00;
        wdata = 32'hbbc0ffee;
        #2
        waddr = 5'h01;
        wdata = 32'hefbeadde;
        #2
        r1addr = 5'h00;
        r2addr = 5'h01;
        #2
        $finish;
    end


endmodule