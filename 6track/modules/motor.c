#include "motor.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
void motor_pwm_init()
{
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}
void motor_pwm_set(int v1,int v2,int v3,int v4)
{
	if(abs(v1)<15) v1=0;
	if(abs(v2)<15) v2=0;
	if(abs(v3)<15) v3=0;
	if(abs(v4)<15) v4=0;
	if(v1>=0)//方向
	{
		if(v1>99) v1=99;//限幅
		motor1_IN1_0;
		motor1_IN2_1;
	}
	else if(v1==0)//方向
	{
		motor1_IN1_0;
		motor1_IN2_0;
	}
	else
	{
		if(v1<-99) v1=-99;
		motor1_IN1_1;
		motor1_IN2_0;
	}
	__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,abs(v1));//设置占空比
	
	if(v2>0)
	{
		if(v2>99) v2=99;
		motor2_IN1_0;
		motor2_IN2_1;
	}
		else if(v2==0)//方向
	{
		motor2_IN1_0;
		motor2_IN2_0;
	}
	else
	{
		if(v2<-99) v2=-99;
		motor2_IN1_1;
		motor2_IN2_0;
	}
	__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,abs(v2));
	
	if(v3>0)
	{
		if(v3>99) v3=99;
		motor3_IN1_1;
		motor3_IN2_0;
	}
		else if(v3==0)//方向
	{
		motor3_IN1_0;
		motor3_IN2_0;
	}
	else
	{
		if(v3<-99) v3=-99;
		motor3_IN1_0;
		motor3_IN2_1;
	}
	__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,abs(v3));
	
	if(v4>0)
	{
		if(v4>99) v4=99;
		motor4_IN1_1;
		motor4_IN2_0;
	}
		else if(v4==0)//方向
	{
		motor4_IN1_0;
		motor4_IN2_0;
	}
	else
	{
		if(v4<-99) v4=-99;
		motor4_IN1_0;
		motor4_IN2_1;
	}
	__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,abs(v4));
	
}