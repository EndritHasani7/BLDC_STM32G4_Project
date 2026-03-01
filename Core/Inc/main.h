/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GDRV_EN_Pin GPIO_PIN_13
#define GDRV_EN_GPIO_Port GPIOC
#define PWM_U_H_Pin GPIO_PIN_0
#define PWM_U_H_GPIO_Port GPIOC
#define PWM_V_H_Pin GPIO_PIN_1
#define PWM_V_H_GPIO_Port GPIOC
#define PWM_W_H_Pin GPIO_PIN_2
#define PWM_W_H_GPIO_Port GPIOC
#define ADC_PWM_TRIG_Pin GPIO_PIN_3
#define ADC_PWM_TRIG_GPIO_Port GPIOC
#define I_SHUNT_U_Pin GPIO_PIN_0
#define I_SHUNT_U_GPIO_Port GPIOA
#define I_SHUNT_V_Pin GPIO_PIN_1
#define I_SHUNT_V_GPIO_Port GPIOA
#define V_BUS_Pin GPIO_PIN_2
#define V_BUS_GPIO_Port GPIOA
#define NTC_HS_Pin GPIO_PIN_3
#define NTC_HS_GPIO_Port GPIOA
#define DRV_FAULT_BKIN_Pin GPIO_PIN_12
#define DRV_FAULT_BKIN_GPIO_Port GPIOB
#define PWM_W_L_Pin GPIO_PIN_15
#define PWM_W_L_GPIO_Port GPIOB
#define PWM_U_L_Pin GPIO_PIN_11
#define PWM_U_L_GPIO_Port GPIOA
#define PWM_V_L_Pin GPIO_PIN_12
#define PWM_V_L_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
