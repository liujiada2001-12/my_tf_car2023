#include "motor.h"
#include "tim.h"
#include "gpio.h"
void motor1(int MotorOutput)
{
	if(MotorOutput>=0)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,0);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,1);
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, myabs(MotorOutput));
}

void motor2(int MotorOutput)
{
	if(MotorOutput>=0)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,0);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,1);
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, myabs(MotorOutput));
}

void motor3(int MotorOutput)
{
	if(MotorOutput>=0)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,0);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,1);
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, myabs(MotorOutput));
}


void motor4(int MotorOutput)
{
	if(MotorOutput>=0)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, myabs(MotorOutput));
}

int myabs(int a)
{
	int b;
	if(a>=0)
	{
		b=a;
	}
	else
	{
		b=-a;
	}
	return b;
}