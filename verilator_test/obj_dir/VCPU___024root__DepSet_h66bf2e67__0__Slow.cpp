// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "VCPU__pch.h"
#include "VCPU___024root.h"

VL_ATTR_COLD void VCPU___024root___eval_static__TOP(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_static(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCPU___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void VCPU___024root___eval_static__TOP(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__pc = 0x80000000U;
    vlSelfRef.cpu__DOT__next_pc = 0x80000000U;
    vlSelfRef.cpu__DOT__nreset = 0U;
    vlSelfRef.cpu__DOT__insn = 0U;
    vlSelfRef.cpu__DOT__reg_wdata = 0U;
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_initial(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCPU___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__i_clk__0 = vlSelfRef.i_clk;
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.o_memaddr = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[1U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[2U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[3U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[4U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[5U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[6U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[7U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[8U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[9U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xaU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xbU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xcU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xdU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xeU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0xfU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x10U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x11U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x12U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x13U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x14U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x15U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x16U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x17U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x18U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x19U] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1aU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1bU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1cU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1dU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1eU] = 0U;
    vlSelfRef.cpu__DOT__reg_file__DOT__register[0x1fU] = 0U;
}

VL_ATTR_COLD void VCPU___024root___eval_final(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VCPU___024root___eval_phase__stl(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_settle(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VCPU___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../CPU.v", 6, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VCPU___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___stl_sequent__TOP__0(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VCPU___024root___stl_sequent__TOP__0(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ cpu__DOT__memread;
    cpu__DOT__memread = 0;
    CData/*4:0*/ cpu__DOT__rs2;
    cpu__DOT__rs2 = 0;
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a = 0;
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b = 0;
    CData/*3:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op = 0;
    // Body
    vlSelfRef.cpu__DOT__jump = ((0x6fU == (0x7fU & vlSelfRef.cpu__DOT__insn))
                                 ? 1U : ((0x67U == 
                                          (0x7fU & vlSelfRef.cpu__DOT__insn))
                                          ? 2U : ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.cpu__DOT__insn))
                                                   ? 3U
                                                   : 0U)));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_1 
        = ((0xff000U & vlSelfRef.cpu__DOT__insn) | 
           ((0x800U & (vlSelfRef.cpu__DOT__insn >> 9U)) 
            | (0x7feU & (vlSelfRef.cpu__DOT__insn >> 0x14U))));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_2 
        = ((0x800U & (vlSelfRef.cpu__DOT__insn << 4U)) 
           | ((0x7e0U & (vlSelfRef.cpu__DOT__insn >> 0x14U)) 
              | (0x1eU & (vlSelfRef.cpu__DOT__insn 
                          >> 7U))));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_12 
        = ((0x17U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
           | (0x37U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    vlSelfRef.cpu__DOT__decoder__DOT__I_immediate = 
        ((vlSelfRef.cpu__DOT__insn >> 0x1fU) ? (0xfffff000U 
                                                | (vlSelfRef.cpu__DOT__insn 
                                                   >> 0x14U))
          : VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__insn, 0x14U));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_13 
        = ((1U == (7U & (vlSelfRef.cpu__DOT__insn >> 0xcU))) 
           | (5U == (7U & (vlSelfRef.cpu__DOT__insn 
                           >> 0xcU))));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_3 
        = ((0xfe0U & (vlSelfRef.cpu__DOT__insn >> 0x14U)) 
           | (0x1fU & (vlSelfRef.cpu__DOT__insn >> 7U)));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_15 
        = ((0x6fU == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
           | (0x67U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    cpu__DOT__rs2 = (((0x33U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                      | ((0x63U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                         | (0x23U == (0x7fU & vlSelfRef.cpu__DOT__insn))))
                      ? (0x1fU & (vlSelfRef.cpu__DOT__insn 
                                  >> 0x14U)) : 0U);
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6 
        = ((0x33U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
           | (0x13U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16 
        = ((3U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
           | (0x23U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    vlSelfRef.cpu__DOT__jump_addr = (((0x17U == (0x7fU 
                                                 & vlSelfRef.cpu__DOT__insn)) 
                                      | (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_15))
                                      ? ((0x6fU == 
                                          (0x7fU & vlSelfRef.cpu__DOT__insn))
                                          ? (vlSelfRef.cpu__DOT__pc 
                                             + ((vlSelfRef.cpu__DOT__insn 
                                                 >> 0x1fU)
                                                 ? 
                                                (0xfff00000U 
                                                 | vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_1)
                                                 : vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_1))
                                          : vlSelfRef.cpu__DOT__pc)
                                      : (vlSelfRef.cpu__DOT__pc 
                                         + ((vlSelfRef.cpu__DOT__insn 
                                             >> 0x1fU)
                                             ? (0xfffff000U 
                                                | (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_2))
                                             : (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_2))));
    vlSelfRef.cpu__DOT__rs2data = ((0U == (IData)(cpu__DOT__rs2))
                                    ? 0U : vlSelfRef.cpu__DOT__reg_file__DOT__register
                                   [cpu__DOT__rs2]);
    vlSelfRef.cpu__DOT__fetch = (1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16) 
                                          & (IData)(vlSelfRef.i_clk))));
    vlSelfRef.cpu__DOT__rs1 = (((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6) 
                                | ((0x67U == (0x7fU 
                                              & vlSelfRef.cpu__DOT__insn)) 
                                   | ((0x63U == (0x7fU 
                                                 & vlSelfRef.cpu__DOT__insn)) 
                                      | (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16))))
                                ? (0x1fU & (vlSelfRef.cpu__DOT__insn 
                                            >> 0xfU))
                                : 0U);
    cpu__DOT__memread = ((IData)(vlSelfRef.cpu__DOT__fetch) 
                         | (3U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op 
        = ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6)
            ? ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_13)
                ? ((8U & (vlSelfRef.cpu__DOT__insn 
                          >> 0x1bU)) | (7U & (vlSelfRef.cpu__DOT__insn 
                                              >> 0xcU)))
                : (7U & (vlSelfRef.cpu__DOT__insn >> 0xcU)))
            : ((0x63U == (0x7fU & vlSelfRef.cpu__DOT__insn))
                ? (8U | (7U & (- (vlSelfRef.cpu__DOT__insn 
                                  >> 0xcU)))) : 0U));
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b 
        = (((0x13U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
            | ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_12) 
               | ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_15) 
                  | (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16))))
            ? ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_12)
                ? (0xfffff000U & vlSelfRef.cpu__DOT__insn)
                : (((0x67U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                    | (3U == (0x7fU & vlSelfRef.cpu__DOT__insn)))
                    ? vlSelfRef.cpu__DOT__decoder__DOT__I_immediate
                    : ((0x13U == (0x7fU & vlSelfRef.cpu__DOT__insn))
                        ? ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_13)
                            ? (0x1fU & (vlSelfRef.cpu__DOT__insn 
                                        >> 0x14U)) : vlSelfRef.cpu__DOT__decoder__DOT__I_immediate)
                        : ((0x6fU == (0x7fU & vlSelfRef.cpu__DOT__insn))
                            ? ((IData)(4U) + vlSelfRef.cpu__DOT__pc)
                            : ((0x23U == (0x7fU & vlSelfRef.cpu__DOT__insn))
                                ? ((vlSelfRef.cpu__DOT__insn 
                                    >> 0x1fU) ? (0xfffff000U 
                                                 | (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_3))
                                    : (IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_3))
                                : 0U))))) : vlSelfRef.cpu__DOT__rs2data);
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__rs1))
            ? 0U : vlSelfRef.cpu__DOT__reg_file__DOT__register
           [vlSelfRef.cpu__DOT__rs1]);
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout 
        = ((8U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
            ? ((4U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                ? ((2U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                    ? ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? ((__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                            != __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                            ? 0U : 1U) : 0U) : ((1U 
                                                 & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                                                 ? 
                                                VL_SHIFTRS_III(32,32,5, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a, 
                                                               (0x1fU 
                                                                & __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b))
                                                 : 
                                                (VL_LTS_III(32, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                                                  ? 0U
                                                  : 1U)))
                : ((2U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                    ? ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? (VL_GTES_III(32, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                            ? 0U : 1U) : ((__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                                           < __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                                           ? 0U : 1U))
                    : ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? ((__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                            >= __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                            ? 0U : 1U) : (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                                          - __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b))))
            : ((4U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                ? ((2U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                    ? ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           & __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                        : (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           | __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b))
                    : ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           >> (0x1fU & __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b))
                        : (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           ^ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)))
                : ((2U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                    ? ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? ((__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                            < __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                            ? 1U : 0U) : (VL_LTS_III(32, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a, __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)
                                           ? 1U : 0U))
                    : ((1U & (IData)(__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op))
                        ? (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           << (0x1fU & __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b))
                        : (__Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a 
                           + __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b)))));
    vlSelfRef.cpu__DOT__alu_result = __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout;
    vlSelfRef.o_memread = cpu__DOT__memread;
    vlSelfRef.b_membus = (((IData)(cpu__DOT__memread)
                            ? 0U : 0xffffffffU) & (
                                                   ((IData)(cpu__DOT__memread)
                                                     ? 0U
                                                     : vlSelfRef.cpu__DOT__rs2data) 
                                                   & ((IData)(cpu__DOT__memread)
                                                       ? 0U
                                                       : 0xffffffffU)));
    vlSelfRef.o_memaddr = ((IData)(vlSelfRef.cpu__DOT__fetch)
                            ? vlSelfRef.cpu__DOT__pc
                            : vlSelfRef.cpu__DOT__alu_result);
    vlSelfRef.cpu__DOT__memdata_read = ((IData)(cpu__DOT__memread)
                                         ? vlSelfRef.b_membus
                                         : 0U);
}

VL_ATTR_COLD void VCPU___024root___eval_triggers__stl(VCPU___024root* vlSelf);

VL_ATTR_COLD bool VCPU___024root___eval_phase__stl(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VCPU___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VCPU___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge i_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge i_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge i_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge i_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___ctor_var_reset(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->i_nreset = VL_RAND_RESET_I(1);
    vlSelf->b_membus = VL_RAND_RESET_I(32);
    vlSelf->o_memread = VL_RAND_RESET_I(1);
    vlSelf->o_memaddr = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__nreset = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__memdata_read = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__insn = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__rs2data = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__jump_addr = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__jump = VL_RAND_RESET_I(2);
    vlSelf->cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__reg_wdata = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__fetch = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->cpu__DOT__reg_file__DOT__register[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->cpu__DOT__decoder__DOT__I_immediate = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_1 = VL_RAND_RESET_I(20);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_2 = VL_RAND_RESET_I(12);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_3 = VL_RAND_RESET_I(12);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_12 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_13 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_15 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = VL_RAND_RESET_I(1);
}
