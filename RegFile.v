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

    integer i;

    initial begin
        for (i = 0; i < 32; i = i + 1) begin
            register[i] = 32'h00000000;
        end
    end

    always @(posedge i_clk) begin
        register[i_waddr] <= i_wdata;
    end

    assign o_r1data = i_r1addr == 5'b00000 ? 32'h00000000 : register[i_r1addr];
    assign o_r2data = i_r2addr == 5'b00000 ? 32'h00000000 : register[i_r2addr];


endmodule