#include "fault.h"

static volatile FaultCode_t g_fault = FAULT_NONE;

void Fault_Init(void)
{
    g_fault = FAULT_NONE;
}

void Fault_Set(FaultCode_t code)
{
    if (g_fault == FAULT_NONE)
        g_fault = code;   /* latch first fault */
}

FaultCode_t Fault_Get(void)
{
    return g_fault;
}

uint8_t Fault_Active(void)
{
    return (g_fault != FAULT_NONE);
}

void Fault_Clear(void)
{
    g_fault = FAULT_NONE;
}
