#include "encoder.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "usart.h"
void motor_encoder_init()
{
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);
	
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim5);
}
short encoder1count=0;
short encoder2count=0;
short encoder3count=0;
short encoder4count=0;

float motor1speed=0;
float motor2speed=0;
float motor3speed=0;
float motor4speed=0;
float motor1mileage=0;
float motor2mileage=0;
float motor3mileage=0;
float motor4mileage=0;
void motor_encoder_getdata()
{
	encoder1count=(short)__HAL_TIM_GET_COUNTER(&htim2);
	encoder2count=(short)__HAL_TIM_GET_COUNTER(&htim3);
	encoder3count=(short)__HAL_TIM_GET_COUNTER(&htim4);
	encoder4count=(short)__HAL_TIM_GET_COUNTER(&htim5);

	__HAL_TIM_SET_COUNTER(&htim2,0);
	__HAL_TIM_SET_COUNTER(&htim3,0);
	__HAL_TIM_SET_COUNTER(&htim4,0);
	__HAL_TIM_SET_COUNTER(&htim5,0);
	
	
	motor1speed=(float) encoder1count*100*100/150/11/4;
	motor2speed=(float) encoder2count*100*100/150/11/4;
	motor3speed=(float) encoder3count*100*100/150/11/4;
	motor4speed=(float) encoder4count*100*100/150/11/4;
}

void motor_getmmileage()
{
	motor1mileage+=0.02*motor1speed*20;
	motor2mileage+=0.02*motor2speed*20;
	motor3mileage+=0.02*motor3speed*20;
	motor4mileage+=0.02*motor4speed*20;
	printf("Àï³ÌÊý:%.2f\r\n",motor1mileage);
}
