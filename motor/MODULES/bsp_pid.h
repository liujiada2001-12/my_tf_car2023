#ifndef __BSP_PID_H
#define __BSP_PID_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  float aim;     //Ŀ��ֵ
	float now;     //ʵ��ֵ
	float sum;
	float err;            //���嵱ǰƫ��ֵ
	float err_last;       //�������һ��ƫ��ֵ
	float out;
	float Kp, Ki, Kd;     //������������֡�΢��ϵ��
}_pid;


//void ResetMotorEn(void);
//void SetMotorEn(void);
void speed_pid_calculate(_pid *pid);
//void location_pid_calculate(void);
//void motor_pid_control(void);
//void set_target(int e,float cha,float chb,float bili);
//void Pid_Wz_target(float A,float B);
//void Pid_turn_target(float A,float B);
//void Pid_Count_clear(void);
void Pid_sum_clear(_pid *pid);//����Pid�Ļ���ֵ�����ֵ
void Pid_Set(_pid *pid, float p, float i, float d);
void PID_param_init(void);


#endif

