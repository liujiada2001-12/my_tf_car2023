#include "bsp_init.h"
#include "bsp_openmv.h"
#include "bsp_motor.h"
#include "bsp_led.h"
#include "dwt_delay.h"
#include "tim.h"
void bsp_init()
{
	DWT_Delay_Init();
	LED_Init();
	openmv_init();
	tim1_pwm_init();
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Base_Start_IT(&htim6);
}