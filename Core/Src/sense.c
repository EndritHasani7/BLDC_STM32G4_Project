#include "main.h"
#include "sense.h"

/* Example constants —  */
#define ADC_MAX     4095.0f
#define VREF        3.3f

/* vlerat per shunt, amp, vbus  */
#define RSHUNT_OHM  0.002f     /* 2 mΩ  */
#define AMP_GAIN    20.0f
#define VBUS_SCALE  11.0f      /*  ADC->VBUS */

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

static uint16_t offset_u = 0;
static uint16_t offset_v = 0;

/* --- method to read adc is not e kjarte for me, me vet arlindin??? --- */
static uint16_t ReadADC1_Blocking(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
    return (uint16_t)HAL_ADC_GetValue(&hadc1);
}
static uint16_t ReadADC2_Blocking(void)
{
    HAL_ADC_Start(&hadc2);
    HAL_ADC_PollForConversion(&hadc2, 10);
    return (uint16_t)HAL_ADC_GetValue(&hadc2);
}

void Sense_Init(void)
{
	// me kalkulu offset values kur current = 0,
    offset_u = 0;
    offset_v = 0;
}


// calculation of average adc divided by 300, just guessing we will check later
void Sense_CalibrateOffsets(void)
{
    uint32_t su = 0, sv = 0;
    const int N = 300;

    for (int i = 0; i < N; i++)
    {
        su += ReadADC1_Blocking(); /* shunt U channel on ADC1 */
        sv += ReadADC2_Blocking(); /* shunt V channel on ADC2 */
    }

    offset_u = (uint16_t)(su / N);
    offset_v = (uint16_t)(sv / N);
}

//  e kthejme adc ne real voltage value
static float ADC_to_Volts(uint16_t adc)
{
    return ((float)adc * VREF) / ADC_MAX;
}

void Sense_GetCurrentsFast(Measurements_t *m)
{
    uint16_t raw_u = ReadADC1_Blocking();
    uint16_t raw_v = ReadADC2_Blocking();

    // ternary operator so offest does not go in zero... eg 900 - 1000 = 100, because of unsigned
    float vu = ADC_to_Volts((raw_u > offset_u) ? (raw_u - offset_u) : 0);
    float vv = ADC_to_Volts((raw_v > offset_v) ? (raw_v - offset_v) : 0);

    /* I = V / (Gain * Rshunt) kalkulimi me amp gain */
    m->iu = vu / (AMP_GAIN * RSHUNT_OHM);
    m->iv = vv / (AMP_GAIN * RSHUNT_OHM);
    m->iw = -m->iu - m->iv;   // ligji i kirkofit
}

void Sense_UpdateSlow(Measurements_t *m)
{
    /* Replace with your DMA channels / reads for VBUS and TEMP */
    m->vbus = 0.0f;
    m->temp = 0.0f;

    // if we take values from dma, dma should be a buffer like:
    /*
    	adc_dma_buffer[0] = VBUS raw
		adc_dma_buffer[1] = TEMP raw
     * */
}
