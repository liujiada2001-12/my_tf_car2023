/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define motor2_in2_Pin GPIO_PIN_2
#define motor2_in2_GPIO_Port GPIOE
#define motor2_in1_Pin GPIO_PIN_3
#define motor2_in1_GPIO_Port GPIOE
#define motor3_in2_Pin GPIO_PIN_4
#define motor3_in2_GPIO_Port GPIOE
#define motor3_in1_Pin GPIO_PIN_5
#define motor3_in1_GPIO_Port GPIOE
#define motor4_in2_Pin GPIO_PIN_6
#define motor4_in2_GPIO_Port GPIOE
#define motor4_c2_Pin GPIO_PIN_0
#define motor4_c2_GPIO_Port GPIOA
#define motor4_c1_Pin GPIO_PIN_1
#define motor4_c1_GPIO_Port GPIOA
#define motor2_c2_Pin GPIO_PIN_6
#define motor2_c2_GPIO_Port GPIOA
#define motor2_c1_Pin GPIO_PIN_7
#define motor2_c1_GPIO_Port GPIOA
#define motor4_in1_Pin GPIO_PIN_7
#define motor4_in1_GPIO_Port GPIOE
#define motor1_pwm_Pin GPIO_PIN_9
#define motor1_pwm_GPIO_Port GPIOE
#define motor2_pwm_Pin GPIO_PIN_11
#define motor2_pwm_GPIO_Port GPIOE
#define motor3_pwm_Pin GPIO_PIN_13
#define motor3_pwm_GPIO_Port GPIOE
#define motor4_pwm_Pin GPIO_PIN_14
#define motor4_pwm_GPIO_Port GPIOE
#define motor1_c1_Pin GPIO_PIN_15
#define motor1_c1_GPIO_Port GPIOA
#define motor1_c2_Pin GPIO_PIN_3
#define motor1_c2_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOB
#define motor3_c1_Pin GPIO_PIN_6
#define motor3_c1_GPIO_Port GPIOB
#define motor3_c2_Pin GPIO_PIN_7
#define motor3_c2_GPIO_Port GPIOB
#define motor1_in1_Pin GPIO_PIN_0
#define motor1_in1_GPIO_Port GPIOE
#define motor1_in2_Pin GPIO_PIN_1
#define motor1_in2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
