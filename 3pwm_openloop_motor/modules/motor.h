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

#define motor1_IN1 PEout(0)
#define motor1_IN2 PEout(1)
#define motor2_IN1 PEout(2)
#define motor2_IN2 PEout(3)
#define motor3_IN1 PEout(4)
#define motor3_IN2 PEout(5)
#define motor4_IN1 PEout(6)
#define motor4_IN2 PEout(7)


void motor_pwm_init(void);
void motor_pwm_set(int v1,int v2,int v3,int v4);
#endif