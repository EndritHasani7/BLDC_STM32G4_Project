#ifndef BLDC_SM_H
#define BLDC_SM_H

#include <stdint.h>

typedef enum
{
    BLDC_BOOT = 0,
    BLDC_IDLE,
    BLDC_READY,
    BLDC_RUN,
    BLDC_FAULT
} BLDC_State_t;

void BLDC_Init(void);
void BLDC_Task(void);   /* ne while(1) */

BLDC_State_t BLDC_GetState(void);

#endif
