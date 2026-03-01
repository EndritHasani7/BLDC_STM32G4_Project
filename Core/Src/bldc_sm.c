#include "bldc_sm.h"
#include "pwm.h"
#include "drv8300.h"
#include "fault.h"
#include "sense.h"

static BLDC_State_t st = BLDC_BOOT;
static Measurements_t meas;

// vlerat max edhe min te operimit per voltage edhe temp
#define VBUS_MIN  10.0f
#define VBUS_MAX  60.0f
#define TEMP_MAX  90.0f

BLDC_State_t BLDC_GetState(void) { return st; }

void BLDC_Init(void)
{
    Fault_Init();
    DRV_Init();
    PWM_Init();
    Sense_Init();

    st = BLDC_BOOT;
}

static void EnterFault(FaultCode_t code)
{
    Fault_Set(code);
    PWM_Stop();
    DRV_Disable();
    st = BLDC_FAULT;
}

void BLDC_Task(void)
{
    switch (st)
    {
        case BLDC_BOOT:
            /* Safe defaults */
            DRV_Disable();
            PWM_Stop();

            /* Offsets with power stage disabled */
            Sense_CalibrateOffsets();

            /* Slow measurements check */
            Sense_UpdateSlow(&meas);

            // values for voltage bus and for the temperature on heatsink
            if (DRV_FaultActive()) { EnterFault(FAULT_DRV_NFAULT); break; }
            if (meas.vbus < VBUS_MIN || meas.vbus > VBUS_MAX) { EnterFault(FAULT_VBUS_RANGE); break; }
            if (meas.temp > TEMP_MAX) { EnterFault(FAULT_OVERTEMP); break; }

            st = BLDC_READY;
            break;

        case BLDC_READY:

            PWM_Start();
            DRV_Enable();
            st = BLDC_RUN;
            break;

        case BLDC_RUN:
            if (DRV_FaultActive()) { EnterFault(FAULT_DRV_NFAULT); break; }

            /*  fixed duty test, se nuk po di cka mi bo */
            PWM_SetDutyPercent(0.10f, 0.10f, 0.10f);

            break;

        case BLDC_FAULT:
            PWM_Stop();
            DRV_Disable();
            /* Stay until clear fault command */
            break;

        default:
            EnterFault(FAULT_DRV_NFAULT);
            break;
    }
}
