#include "move.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "encoder.h"
#include "pid.h"
#include "motor.h"
void motor_init()
{
	motor_encoder_init();
	motor_pwm_init();
	pid_init();
}
extern float motor1speed;
extern float motor2speed;
extern float motor3speed;
extern float motor4speed;
extern tpid pid1,pid2,pid3,pid4;


void motor_speedopenloop_conrol(int v1,int v2,int v3,int v4)
{
			motor_pwm_set(v1,v2,v3,v4);
}

void motor_speedpid_conrol(int v1,int v2,int v3,int v4)
{
			pid1.target_val=v1;
			pid2.target_val=v2;
			pid3.target_val=v3;
			pid4.target_val=v4;
			pid_realize(&pid1,motor1speed);
			pid_realize(&pid2,motor2speed);
			pid_realize(&pid3,motor3speed);
			pid_realize(&pid4,motor4speed);
//			printf("v1:%.2f\r\n",pid1.out);
//		printf("v2:%.2f\r\n",pid2.out);
//		printf("v3:%.2f\r\n",pid3.out);
//		printf("v4:%.2f\r\n",pid4.out);
			motor_pwm_set(pid1.target_val+pid1.out,pid2.target_val+pid2.out,pid3.target_val+pid3.out,pid4.target_val+pid4.out);
}
extern int v1,v2,v3,v4;
void track()
{
	if(FL_LIGHT ==0 && FR_LIGHT ==1)
		{
			v1=50;
			v3=10;
			v2=10;
			v4=50;
		}
		else if(FL_LIGHT ==1 && FR_LIGHT ==0)
		{
			v1=10;
			v3=50;
			v2=50;
			v4=10;
		}
		else
		{
			v1=50;
			v3=50;
			v2=50;
			v4=50;
		}
}