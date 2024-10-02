module RegFile (
    input   wire            i_clk,
    input   wire    [31:0]  i_wdata,
    input   wire    [4:0]   i_waddr,
    output  wire    [31:0]  o_r1data,
    input   wire    [4:0]   i_r1addr,
    output  wire    [31:0]  o_r2data,
    input   wire    [4:0]   i_r2addr
);

    reg [31:0] register [31:0];

    reg [31:0] r1data;
    reg [31:0] r2data;

    integer i;

    initial begin
        for (i = 0; i < 32; i = i + 1) begin
            register[i] = 32'h00000000;
        end

        r1data = 32'h00000000;
        r2data = 32'h00000000;
    end

    always @(negedge i_clk) begin
        register[i_waddr] <= i_wdata;
        case (i_r1addr)
            5'h00: r1data <= 32'h00000000;
            default: r1data <= register[i_r1addr];
        endcase

        case (i_r2addr)
            5'h00: r2data <= 32'h00000000;
            default: r2data <= register[i_r2addr];
        endcase
    end

    assign o_r1data = r1data;
    assign o_r2data = r2data;


endmodule