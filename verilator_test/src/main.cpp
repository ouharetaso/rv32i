#include "verilated.h"
#include "VCPU.h"


int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VCPU* top = new VCPU;

    top->clk = 0;
    top->rst = 1;
    top->eval();
    top->rst = 0;

    while (!Verilated::gotFinish()) {
        top->clk = !top->clk;
        top->eval();
    }

    delete top;
    return 0;
}