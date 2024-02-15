#include "move.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "gpio.h"
#include "main.h"
#include "cmd.h"
#include "usart.h"
#include "arm.h"
void arm_action(uint8_t num)
{

	char i;
	
	static uint8_t action0[8] = {0x55,0x55,0x05,0x06,0x00,0x01,0x00};	
	static uint8_t action1[8] = {0x55,0x55,0x05,0x06,0x01,0x01,0x00};
	static uint8_t action2[8] = {0x55,0x55,0x05,0x06,0x02,0x01,0x00};
	static uint8_t action3[8] = {0x55,0x55,0x05,0x06,0x03,0x01,0x00};
	static uint8_t action4[8] = {0x55,0x55,0x05,0x06,0x04,0x01,0x00};	
	static uint8_t action5[8] = {0x55,0x55,0x05,0x06,0x05,0x01,0x00};	
	static uint8_t action6[8] = {0x55,0x55,0x05,0x06,0x06,0x01,0x00};
	static uint8_t action7[8] = {0x55,0x55,0x05,0x06,0x07,0x01,0x00};
	static uint8_t action8[8] = {0x55,0x55,0x05,0x06,0x08,0x01,0x00};
	static uint8_t action9[8] = {0x55,0x55,0x05,0x06,0x09,0x01,0x00};
	static uint8_t action10[8] = {0x55,0x55,0x05,0x06,0x0A,0x01,0x00};
	static uint8_t action11[8] = {0x55,0x55,0x05,0x06,0x0B,0x01,0x00};
	static uint8_t action12[8] = {0x55,0x55,0x05,0x06,0x0C,0x01,0x00};
	switch (num){
		case 0: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action1[i],sizeof(action1[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action1[i]; 
				}	
					break;
		}
		case 1: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action1[i],sizeof(action1[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action1[i]; 
				}	
					break;
		}
		case 2: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action2[i],sizeof(action2[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action2[i]; 
				}	
					break;
		}		
		case 3: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action3[i],sizeof(action3[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action3[i]; 
				}	
					break;
		}
		case 4: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action4[i],sizeof(action4[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action4[i]; 
				}	
				break;
			}
		case 5: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action5[i],sizeof(action5[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action5[i]; 
				}	
			break;				
		}
		case 6: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action6[i],sizeof(action6[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action6[i]; 
				}	
			break;				
		}	
	case 7: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action7[i],sizeof(action7[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action7[i]; 
				}	
			break;				
		}
		case 8: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action8[i],sizeof(action8[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action8[i]; 
				}	
			break;				
		}
			case 9: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action9[i],sizeof(action9[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action9[i]; 
				}	
			break;				
		}
				case 10: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action10[i],sizeof(action10[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action10[i]; 
				}	
			break;				
		}
		case 11: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action11[i],sizeof(action11[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action11[i]; 
				}	
			break;				
		}
			case 12: {
			for( i = 0 ; i < 7; i++) 
				{
//					HAL_UART_Transmit(&huart3,&action12[i],sizeof(action12[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
					while((USART3->SR&0X40)==0);  
					USART3->DR = action12[i]; 
				}	
			break;				
		}
	
	}
	HAL_Delay(500);	
}

void arm_stpo(void)
{
	char i;
	static u8 stop[5] = {0x55,0x55,0x02,0x07};
	for( i = 0 ; i < 4; i++) 
		{
//			HAL_UART_Transmit(&huart3,&stop[i],sizeof(stop[i]),0xffff);
//					while(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC)==RESET);
			while((USART3->SR&0X40)==0);  
			USART3->DR = stop[i]; 
		}	
}