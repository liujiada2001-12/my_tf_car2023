#include "bsp_led.h"
#include "gpio.h"
//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStruct;
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
 GPIO_InitStruct.Pin=GPIO_PIN_5;				 //LED0-->PB.5 �˿�����
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;		 //�������
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;		 //IO���ٶ�Ϊ50MHz
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);				 //�����趨������ʼ��GPIOB.5
 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);						 //PB.5 �����

 GPIO_InitStruct.Pin=GPIO_PIN_5;	    		 //LED1-->PE.5 �˿�����, �������
 HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);	  				 //������� ��IO���ٶ�Ϊ50MHz
 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);							 //PE.5 ����� 
}
 
