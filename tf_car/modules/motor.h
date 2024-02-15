#ifndef _MOTOR_H
#define _MOTOR_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

#ifndef abs
#define abs(x) ((x > 0) ? x : -x)
#endif

#define motor1_IN1_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,0)
#define motor1_IN1_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,1)
#define motor1_IN2_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,0)
#define motor1_IN2_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,1)

#define motor2_IN1_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,0)
#define motor2_IN1_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,1)

#define motor2_IN2_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,0)
#define motor2_IN2_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,1)

#define motor3_IN1_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,0)
#define motor3_IN1_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,1)

#define motor3_IN2_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,0)
#define motor3_IN2_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,1)

#define motor4_IN1_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0)
#define motor4_IN1_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1)

#define motor4_IN2_0 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,0)
#define motor4_IN2_1 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,1)

void motor_pwm_init(void);
void motor_pwm_set(int v1,int v2,int v3,int v4);
#endif