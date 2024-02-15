#ifndef _PID_H
#define _PID_H

#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "gpio.h"
#include <math.h>

typedef struct{
	float target_val;//Ŀ��ֵ
	float actual_val;//ʵ��ֵ
	float err;//��ǰ���
	float err_last;//�ϴ����
	float err_sum;//����ۻ�
	float kp,ki,kd;//������΢�֣�����ϵ��
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