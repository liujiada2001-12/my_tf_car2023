#ifndef _CMD_H
#define _CMD_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>
void track(void);
float myabs(float x);
void gofoward(float diatance,float direct);
void gocontinue(float diatance,float direct);
void turn(float direct);
void motor_stop(void);
void act1(uint8_t action_cnt);
void Leftgo(void);
void Left(void);
void Right(void);
void throw1(uint8_t wt);
void cross1(void);
void motor_speed_set(int a,int b,int c,int d);
#endif