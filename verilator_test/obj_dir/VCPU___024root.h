// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"


class VCPU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCPU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_IN8(i_nreset,0,0);
    VL_OUT8(o_memread,0,0);
    CData/*0:0*/ cpu__DOT__nreset;
    CData/*4:0*/ cpu__DOT__rs1;
    CData/*1:0*/ cpu__DOT__jump;
    CData/*0:0*/ cpu__DOT__fetch;
    CData/*0:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6;
    CData/*0:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_12;
    CData/*0:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_13;
    CData/*0:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_15;
    CData/*0:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_2;
    SData/*11:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_3;
    VL_INOUT(b_membus,31,0);
    VL_OUT(o_memaddr,31,0);
    IData/*31:0*/ cpu__DOT__pc;
    IData/*31:0*/ cpu__DOT__next_pc;
    IData/*31:0*/ cpu__DOT__memdata_read;
    IData/*31:0*/ cpu__DOT__insn;
    IData/*31:0*/ cpu__DOT__rs2data;
    IData/*31:0*/ cpu__DOT__jump_addr;
    IData/*31:0*/ cpu__DOT__alu_result;
    IData/*31:0*/ cpu__DOT__reg_wdata;
    IData/*31:0*/ cpu__DOT__decoder__DOT__I_immediate;
    IData/*19:0*/ cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> cpu__DOT__reg_file__DOT__register;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU___024root(VCPU__Syms* symsp, const char* v__name);
    ~VCPU___024root();
    VL_UNCOPYABLE(VCPU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
