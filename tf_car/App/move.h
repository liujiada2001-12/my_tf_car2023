#ifndef _MOVE_H
#define _MOVE_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

#define FR_LIGHT HAL_GPIO_ReadPin(FR_light_GPIO_Port,FR_light_Pin)
#define FL_LIGHT HAL_GPIO_ReadPin(FL_light_GPIO_Port,FL_light_Pin)
#define MR_LIGHT HAL_GPIO_ReadPin(MR_light_GPIO_Port,MR_light_Pin)
#define ML_LIGHT HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)
#define LIGHT HAL_GPIO_ReadPin(Light_GPIO_Port,Light_Pin)

void motor_init(void);
void motor_speedpid_conrol(int v1,int v2,int v3,int v4);
void motor_speedopenloop_conrol(int v1,int v2,int v3,int v4);
#endif