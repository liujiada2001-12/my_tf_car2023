#ifndef _ENCODER_H
#define _ENCODER_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

void motor_encoder_init(void);
void motor_encoder_getdata(void);
#endif