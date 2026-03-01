#include "main.h"
#include "drv8300.h"

/* Change these if you move pins */
#define DRV_EN_PORT   GPIOC
#define DRV_EN_PIN    GPIO_PIN_13

#define NFAULT_PORT   GPIOB
#define NFAULT_PIN    GPIO_PIN_12

void DRV_Init(void)
{
    /* Keep driver disabled by default */
    DRV_Disable();
}

void DRV_Enable(void)
{
    HAL_GPIO_WritePin(DRV_EN_PORT, DRV_EN_PIN, GPIO_PIN_SET);
}

void DRV_Disable(void)
{
    HAL_GPIO_WritePin(DRV_EN_PORT, DRV_EN_PIN, GPIO_PIN_RESET);
}

uint8_t DRV_FaultActive(void)
{
    return (HAL_GPIO_ReadPin(NFAULT_PORT, NFAULT_PIN) == GPIO_PIN_RESET);
}
