#ifndef _PID_H
#define _PID_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

typedef struct{
	float target_val;//目标值
	float actual_val;//实际值
	float err;//当前误差
	float err_last;//上次误差
	float err_sum;//误差累积
	float kp,ki,kd;//比例，微分，积分系数
	float out;
}tpid;

float p_realize(tpid *pid,float actual_val);
void pid_init(void);
void pid_set(tpid *pid,float kp,float ki,float kd);
float pi_realize(tpid *pid,float actual_val);
float pid_realize(tpid *pid,float actual_val);
float pid_realize_s(tpid *pid,float actual_val);
float pid_realize_turn(tpid *pid,float actual_angle);
#endif