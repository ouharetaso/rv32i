module RegFile (
    input   wire            i_clk,
    input   wire    [31:0]  i_wdata,
    input   wire    [4:0]   i_waddr,
    input   wire            i_wen,
    output  wire    [31:0]  o_r1data,
    input   wire    [4:0]   i_r1addr,
    output  wire    [31:0]  o_r2data,
    input   wire    [4:0]   i_r2addr
);

    reg [31:0] register [31:0];

    reg [31:0] r1data;
    reg [31:0] r2data;

    always @(posedge i_clk) begin
        if (i_wen) begin
            register[i_waddr] = i_wdata;
            r1data <= 32'h00000000;
            r2data <= 32'h00000000;
        end
        else begin
            case (i_r1addr)
                5'h00: r1data <= 32'h00000000;
                default: r1data <= register[i_r1addr];
            endcase

            case (i_r2addr)
                5'h00: r2data <= 32'h00000000;
                default: r2data <= register[i_r2addr];
            endcase
        end
    end

    assign o_r1data = r1data;
    assign o_r2data = r2data;


endmodule