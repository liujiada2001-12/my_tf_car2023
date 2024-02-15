#include "bsp_led.h"
#include "gpio.h"
//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStruct;
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
 GPIO_InitStruct.Pin=GPIO_PIN_5;				 //LED0-->PB.5 端口配置
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;		 //推挽输出
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;		 //IO口速度为50MHz
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);				 //根据设定参数初始化GPIOB.5
 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);						 //PB.5 输出高

 GPIO_InitStruct.Pin=GPIO_PIN_5;	    		 //LED1-->PE.5 端口配置, 推挽输出
 HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);	  				 //推挽输出 ，IO口速度为50MHz
 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);							 //PE.5 输出高 
}
 
