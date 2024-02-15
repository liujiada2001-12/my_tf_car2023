#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
void motor1(int MotorOutput);
void motor2(int MotorOutput);
void motor3(int MotorOutput);
void motor4(int MotorOutput);
int myabs(int a);

#ifdef __cplusplus
}
#endif

#endif 
