#include "bsp_arm.h"
#include "sys.h"
#include "usart.h"
#include "dwt_delay.h"


/*****************************************机械臂舵机部分*****************************/

//串口3初始化
//已在  MX_USART3_UART_Init();完成




///*中断处理函数*/
//void USART3_IRQHandler(void)
//{
//	unsigned char Clear;
//	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
//	{
//		Clear= USART3->DR;
//	}

//}



//void StepperInit(void){

//	GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);  //使能GPIO外设
//	
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOG, &GPIO_InitStructure);
//	
//	PGout(2)=0;		//0号步进电机 
//}
///*
//	功能：在某一时刻只能控制一个步进电机转动
//	stepper：电机标号，dir：该电机的转向，pulse：脉冲
//	注意：	1.delay_ms()最多不超过1500ms。
//			2.速度不要调的太快，否则电机转不动
//			3.调节步进电机驱动器的额定输出电流大小，可改变步进电机的输出转矩
//*/
//void MoveStepper( u8 dir, u16 pulse)
//{

//			PGout(2)=dir;		//0号步进电机方向
//			while(pulse>0)
//				{
//				PGout(3)=pulse;	//把pulse的最后一位给PGout(2)
//				pulse--;
//				delay_us(1400);		//通过更改此值可改变步进电机速度
//				//delay_ms(1);
//				}

//}


