#ifndef __BSP_PID_H
#define __BSP_PID_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  float aim;     //目标值
	float now;     //实际值
	float sum;
	float err;            //定义当前偏差值
	float err_last;       //定义最后一个偏差值
	float out;
	float Kp, Ki, Kd;     //定义比例、积分、微分系数
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
void Pid_sum_clear(_pid *pid);//清零Pid的积分值和误差值
void Pid_Set(_pid *pid, float p, float i, float d);
void PID_param_init(void);


#endif

