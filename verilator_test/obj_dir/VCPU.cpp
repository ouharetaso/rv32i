// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCPU__pch.h"

//============================================================
// Constructors

VCPU::VCPU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VCPU__Syms(contextp(), _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , i_nreset{vlSymsp->TOP.i_nreset}
    , o_memread{vlSymsp->TOP.o_memread}
    , b_membus{vlSymsp->TOP.b_membus}
    , o_memaddr{vlSymsp->TOP.o_memaddr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VCPU::VCPU(const char* _vcname__)
    : VCPU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VCPU::~VCPU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCPU___024root___eval_debug_assertions(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
void VCPU___024root___eval_static(VCPU___024root* vlSelf);
void VCPU___024root___eval_initial(VCPU___024root* vlSelf);
void VCPU___024root___eval_settle(VCPU___024root* vlSelf);
void VCPU___024root___eval(VCPU___024root* vlSelf);

void VCPU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCPU::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCPU___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCPU___024root___eval_static(&(vlSymsp->TOP));
        VCPU___024root___eval_initial(&(vlSymsp->TOP));
        VCPU___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCPU___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCPU::eventsPending() { return false; }

uint64_t VCPU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VCPU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VCPU___024root___eval_final(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU::final() {
    VCPU___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCPU::hierName() const { return vlSymsp->name(); }
const char* VCPU::modelName() const { return "VCPU"; }
unsigned VCPU::threads() const { return 1; }
void VCPU::prepareClone() const { contextp()->prepareClone(); }
void VCPU::atClone() const {
    contextp()->threadPoolpOnClone();
}
