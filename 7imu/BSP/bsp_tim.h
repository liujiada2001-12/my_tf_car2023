#ifndef _BSP_TIM_H
#define _BSP_TIM_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

void HAL_TIM_PeriodElapasedCallback(TIM_HandleTypeDef *htim);
#endif