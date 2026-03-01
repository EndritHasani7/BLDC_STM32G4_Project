#ifndef PWM_H
#define PWM_H

#include <stdint.h>

void PWM_Init(void);
void PWM_Start(void);
void PWM_Stop(void);

/* duty in timer counts (0..ARR) */
void PWM_SetDuty(uint16_t du, uint16_t dv, uint16_t dw);

/* helper */
void PWM_SetDutyPercent(float du, float dv, float dw);

#endif
