#include "encoder.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "usart.h"
#include "encoder.h"
#include "motor.h"
#include "move.h"
#include "pid.h"
#include "bsp_tim.h"
//extern short encoder1count;
//extern short encoder2count;
//extern short encoder3count;
//extern short encoder4count;
//extern tpid pid1,pid2,pid3,pid4;
//uint16_t timercount=0;
//void HAL_TIM_PeriodElapasedCallback(TIM_HandleTypeDef *htim)
//{
//	if(htim == &htim8)//2ms 500hz
//	{
//		timercount++;
//		if(timercount%5 == 0)//10ms计算速度
//		{
//			HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_0);
//			motor_encoder_getdata();
//		}
//		if(timercount%10 == 0)//20ms计算速度
//		{
//			motor_speedopenloop_conrol(-40,-40,-40,-40);
////			timercount=0;
//		}
//	}
//}

