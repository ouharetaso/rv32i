// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "VCPU__pch.h"
#include "VCPU___024root.h"

void VCPU___024root___ico_sequent__TOP__0(VCPU___024root* vlSelf);

void VCPU___024root___eval_ico(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VCPU___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VCPU___024root___ico_sequent__TOP__0(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ cpu__DOT__memread;
    cpu__DOT__memread = 0;
    // Body
    vlSelfRef.cpu__DOT__fetch = (1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_16) 
                                          & (IData)(vlSelfRef.i_clk))));
    vlSelfRef.o_memaddr = ((IData)(vlSelfRef.cpu__DOT__fetch)
                            ? vlSelfRef.cpu__DOT__pc
                            : vlSelfRef.cpu__DOT__alu_result);
    cpu__DOT__memread = ((IData)(vlSelfRef.cpu__DOT__fetch) 
                         | (3U == (0x7fU & vlSelfRef.cpu__DOT__insn)));
    vlSelfRef.o_memread = cpu__DOT__memread;
    vlSelfRef.b_membus = (((IData)(cpu__DOT__memread)
                            ? 0U : 0xffffffffU) & (
                                                   ((IData)(cpu__DOT__memread)
                                                     ? 0U
                                                     : vlSelfRef.cpu__DOT__rs2data) 
                                                   & ((IData)(cpu__DOT__memread)
                                                       ? 0U
                                                       : 0xffffffffU)));
    vlSelfRef.cpu__DOT__memdata_read = ((IData)(cpu__DOT__memread)
                                         ? vlSelfRef.b_membus
                                         : 0U);
}

void VCPU___024root___eval_triggers__ico(VCPU___024root* vlSelf);

bool VCPU___024root___eval_phase__ico(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VCPU___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VCPU___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VCPU___024root___eval_act(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VCPU___024root___nba_sequent__TOP__0(VCPU___024root* vlSelf);
void VCPU___024root___nba_sequent__TOP__1(VCPU___024root* vlSelf);
void VCPU___024root___nba_comb__TOP__0(VCPU___024root* vlSelf);

void VCPU___024root___eval_nba(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__0(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__cpu__DOT__pc;
    __Vdly__cpu__DOT__pc = 0;
    // Body
    __Vdly__cpu__DOT__pc = vlSelfRef.cpu__DOT__pc;
    vlSelfRef.cpu__DOT__nreset = vlSelfRef.i_nreset;
    if (vlSelfRef.cpu__DOT__nreset) {
        if (((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6) 
             | ((0x73U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                | ((0x17U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                   | ((0x37U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                      | ((0x6fU == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                         | ((0x67U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                            | ((0x63U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                               | ((3U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                                  | ((0x23U == (0x7fU 
                                                & vlSelfRef.cpu__DOT__insn)) 
                                     | ((0x73U == (0x7fU 
                                                   & vlSelfRef.cpu__DOT__insn)) 
                                        | (0xfU == 
                                           (0x7fU & vlSelfRef.cpu__DOT__insn))))))))))))) {
            __Vdly__cpu__DOT__pc = vlSelfRef.cpu__DOT__next_pc;
            if ((2U & (IData)(vlSelfRef.cpu__DOT__jump))) {
                if ((1U & (IData)(vlSelfRef.cpu__DOT__jump))) {
                    vlSelfRef.cpu__DOT__reg_wdata = vlSelfRef.cpu__DOT__alu_result;
                    vlSelfRef.cpu__DOT__next_pc = (
                                                   (0U 
                                                    == vlSelfRef.cpu__DOT__alu_result)
                                                    ? vlSelfRef.cpu__DOT__jump_addr
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.cpu__DOT__pc));
                } else {
                    vlSelfRef.cpu__DOT__reg_wdata = vlSelfRef.cpu__DOT__jump_addr;
                    vlSelfRef.cpu__DOT__next_pc = vlSelfRef.cpu__DOT__alu_result;
                }
            } else if ((1U & (IData)(vlSelfRef.cpu__DOT__jump))) {
                vlSelfRef.cpu__DOT__reg_wdata = vlSelfRef.cpu__DOT__alu_result;
                vlSelfRef.cpu__DOT__next_pc = vlSelfRef.cpu__DOT__jump_addr;
            } else {
                vlSelfRef.cpu__DOT__reg_wdata = ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.cpu__DOT__insn))
                                                  ? vlSelfRef.cpu__DOT__memdata_read
                                                  : vlSelfRef.cpu__DOT__alu_result);
                vlSelfRef.cpu__DOT__next_pc = ((IData)(4U) 
                                               + vlSelfRef.cpu__DOT__pc);
            }
        }
    } else {
        __Vdly__cpu__DOT__pc = 0x80000000U;
    }
    vlSelfRef.cpu__DOT__pc = __Vdly__cpu__DOT__pc;
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__1(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ cpu__DOT__memread;
    cpu__DOT__memread = 0;
    CData/*4:0*/ cpu__DOT__rs2;
    cpu__DOT__rs2 = 0;
    IData/*31:0*/ __VdlyVal__cpu__DOT__reg_file__DOT__register__v0;
    __VdlyVal__cpu__DOT__reg_file__DOT__register__v0 = 0;
    CData/*4:0*/ __VdlyDim0__cpu__DOT__reg_file__DOT__register__v0;
    __VdlyDim0__cpu__DOT__reg_file__DOT__register__v0 = 0;
    // Body
    __VdlyVal__cpu__DOT__reg_file__DOT__register__v0 
        = vlSelfRef.cpu__DOT__reg_wdata;
    __VdlyDim0__cpu__DOT__reg_file__DOT__register__v0 
        = (((IData)(vlSelfRef.cpu__DOT__decoder__DOT____VdfgRegularize_hafbf1f90_0_6) 
            | ((0x37U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
               | ((3U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                  | ((0x67U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                     | ((0x17U == (0x7fU & vlSelfRef.cpu__DOT__insn)) 
                        | (0x6fU == (0x7fU & vlSelfRef.cpu__DOT__insn)))))))
            ? (0x1fU & (vlSelfRef.cpu__DOT__insn >> 7U))
            : 0U);
    vlSelfRef.cpu__DOT__reg_file__DOT__register[__VdlyDim0__cpu__DOT__reg_file__DOT__register__v0] 
        = __VdlyVal__cpu__DOT__reg_file__DOT__register__v0;
    if (vlSelfRef.cpu__DOT__nreset) {
        vlSelfRef.cpu__DOT__insn = vlSelfRef.cpu__DOT__memdata_read;
    }
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
    vlSelfRef.o_memread = cpu__DOT__memread;
    vlSelfRef.b_membus = (((IData)(cpu__DOT__memread)
                            ? 0U : 0xffffffffU) & (
                                                   ((IData)(cpu__DOT__memread)
                                                     ? 0U
                                                     : vlSelfRef.cpu__DOT__rs2data) 
                                                   & ((IData)(cpu__DOT__memread)
                                                       ? 0U
                                                       : 0xffffffffU)));
    vlSelfRef.cpu__DOT__memdata_read = ((IData)(cpu__DOT__memread)
                                         ? vlSelfRef.b_membus
                                         : 0U);
}

VL_INLINE_OPT void VCPU___024root___nba_comb__TOP__0(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_a = 0;
    IData/*31:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_input_b = 0;
    CData/*3:0*/ __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op;
    __Vfunc_cpu__DOT__alu__DOT__calc_alu__0__i_alu_op = 0;
    // Body
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
    vlSelfRef.o_memaddr = ((IData)(vlSelfRef.cpu__DOT__fetch)
                            ? vlSelfRef.cpu__DOT__pc
                            : vlSelfRef.cpu__DOT__alu_result);
}

void VCPU___024root___eval_triggers__act(VCPU___024root* vlSelf);

bool VCPU___024root___eval_phase__act(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VCPU___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VCPU___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VCPU___024root___eval_phase__nba(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VCPU___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU___024root___eval(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VCPU___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../CPU.v", 6, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VCPU___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VCPU___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../CPU.v", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../CPU.v", 6, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VCPU___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VCPU___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VCPU___024root___eval_debug_assertions(VCPU___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((vlSelfRef.i_nreset & 0xfeU))) {
        Verilated::overWidthError("i_nreset");}
}
#endif  // VL_DEBUG
