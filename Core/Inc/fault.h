#ifndef FAULT_H
#define FAULT_H

#include <stdint.h>

typedef enum
{
    FAULT_NONE = 0,
    FAULT_DRV_NFAULT,
    FAULT_VBUS_RANGE,
    FAULT_OVERTEMP,
    FAULT_CAN_TIMEOUT,
    FAULT_SW_OVERCURRENT
} FaultCode_t;

void Fault_Init(void);
void Fault_Set(FaultCode_t code);
FaultCode_t Fault_Get(void);
uint8_t Fault_Active(void);
void Fault_Clear(void);

#endif
