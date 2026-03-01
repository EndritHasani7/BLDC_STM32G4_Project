#ifndef SENSE_H
#define SENSE_H

#include <stdint.h>

typedef struct
{
    float iu;    // shunt 1
    float iv;    // shunt 2
    float iw;    // we can remove or add later
    float vbus;  // vlerat per vbus
    float temp;
} Measurements_t;

void Sense_Init(void);
void Sense_CalibrateOffsets(void);
void Sense_UpdateSlow(Measurements_t *m);   /* vbus, temp */
void Sense_GetCurrentsFast(Measurements_t *m); /* iu iv iw */

#endif
