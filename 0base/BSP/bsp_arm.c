#include "bsp_arm.h"
#include "sys.h"
#include "usart.h"
#include "dwt_delay.h"


/*****************************************��е�۶������*****************************/

//����3��ʼ��
//����  MX_USART3_UART_Init();���




///*�жϴ�����*/
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
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);  //ʹ��GPIO����
//	
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOG, &GPIO_InitStructure);
//	
//	PGout(2)=0;		//0�Ų������ 
//}
///*
//	���ܣ���ĳһʱ��ֻ�ܿ���һ���������ת��
//	stepper�������ţ�dir���õ����ת��pulse������
//	ע�⣺	1.delay_ms()��಻����1500ms��
//			2.�ٶȲ�Ҫ����̫�죬������ת����
//			3.���ڲ�������������Ķ���������С���ɸı䲽����������ת��
//*/
//void MoveStepper( u8 dir, u16 pulse)
//{

//			PGout(2)=dir;		//0�Ų����������
//			while(pulse>0)
//				{
//				PGout(3)=pulse;	//��pulse�����һλ��PGout(2)
//				pulse--;
//				delay_us(1400);		//ͨ�����Ĵ�ֵ�ɸı䲽������ٶ�
//				//delay_ms(1);
//				}

//}


