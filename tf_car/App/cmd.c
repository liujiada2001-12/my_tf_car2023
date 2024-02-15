#include "move.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "gpio.h"
#include "main.h"
#include "cmd.h"
#include "arm.h"
#include "vision.h"
#include "imu.h"
#include "usart.h"
#include "distance.h"
extern int v1,v2,v3,v4;

extern tpid pid1,pid2,pid3,pid4,pid1s,pidturn;
extern int position_control_flag;



extern float motor1mileage;
extern float motor2mileage;
extern float motor3mileage;
extern float motor4mileage;
extern float mileage;

extern User_USART JY901_data;
extern float direction0;



float myabs(float x)
{
	if(x>=0) return x;
	else return -x;
}


void gofoward(float diatance,float direct)//以当前为起点往前走
{
	mileage=0;
	if(direct>180) direct-=360;
	if(direct<-180) direct+=360;
	pid1s.target_val=diatance;
	position_control_flag=1;
	pidturn.target_val=direct;
	
		while(1)
	{
		if(myabs(pid1s.out)<10) break;
	}
		while(1)
	{
		if(myabs(pidturn.err)<1) break;
	}
	HAL_Delay(1000);
	position_control_flag=0;
}

void gocontinue(float diatance,float direct)//继续往前走，以上次清0地点为起点
{
	if(direct>180) direct-=360;
	if(direct<-180) direct+=360;
	pid1s.target_val=diatance;
	position_control_flag=1;
	pidturn.target_val=direct;
			while(1)
	{
		if(myabs(pid1s.out)<10) break;
	}
		while(1)
	{
		if(myabs(pidturn.err)<1) break;
	}
	HAL_Delay(1000);
	position_control_flag=0;
}

void turn(float direct)
{
	v1=0;
	v2=0;
	v3=0;
	v4=0;
	if(direct>180) direct-=360;
	if(direct<-180) direct+=360;
	position_control_flag=0;
	pidturn.target_val=direct;
	while(1)
	{
		if(myabs(pidturn.err)<1) break;
	}
	HAL_Delay(500);
}

void goslowly(float direct)
{
	if(direct>180) direct-=360;
	if(direct<-180) direct+=360;
	position_control_flag=0;
	pidturn.target_val=direct;
	while(abs(pidturn.err)>10) ;
}

void motor_stop(void)
{
	v1=0;
	v2=0;
	v3=0;
	v4=0;
}



void Leftgo(void)
{
while(1)
{
	v1=50;
	v3=50;
	v2=50;
	v4=50;
	
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
			Left();
			break;
		}
	
	}
}
}
void Left()
{
		//左转
		v1=40;
		v2=-40;
		v3=-40;
		v4=40;
		HAL_Delay(3300);//转弯完成    90
		v1=40;
		v2=40;
		v3=40;
		v4=40;
	  HAL_Delay(750);
}

void Right()
{
			 //右转
	v1=-40;
		v2=40;
		v3=40;
		v4=-40;
		HAL_Delay(3400);//转弯完成   90
	 v1=40;
		v2=40;
		v3=40;
		v4=40;
	 HAL_Delay(300);
}

void throw1(uint8_t wt)
{
  int n;
	for(n=0;n<wt;n++)
		{
		track();
		
		}
		motor_stop();
		HAL_Delay(1000);
		arm_action(2);
  	HAL_Delay(4500);
//		stopActionGroup();
//		MoveStepper(1,750);

}

void cross1(void)
{
 while(1)
{
 track();
 if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0&&HAL_GPIO_ReadPin(MR_light_GPIO_Port,MR_light_Pin)==1)
 {
  HAL_Delay(1000);
	break;
 }
}
}

void motor_speed_set(int a,int b,int c,int d)
{
	v1=a;
		v2=b;
		v3=c;
		v4=d;
}