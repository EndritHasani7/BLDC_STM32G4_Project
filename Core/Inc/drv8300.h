#ifndef DRV8300_H
#define DRV8300_H

#include <stdint.h>

void DRV_Init(void);
void DRV_Enable(void);
void DRV_Disable(void);

/* nFAULT is active low */
uint8_t DRV_FaultActive(void);

#endif
