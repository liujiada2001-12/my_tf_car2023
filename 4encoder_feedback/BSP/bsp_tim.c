#include "encoder.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "usart.h"
uint16_t timer8count=0;
void HAL_TIM_PeriodElapasedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim8)//2ms 500hz
	{
		timer8count++;
		if(timer8count%5 == 0)//10msº∆À„ÀŸ∂»
		{
			motor_encoder_getdata();
			timer8count=0;
		}
	}
}

