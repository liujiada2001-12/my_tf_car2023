#include "bsp_arm.h"
#include "arm_task.h"
#include "sys.h"
#include "usart.h"
#include "dwt_delay.h"


/*****************************************机械臂舵机任务部分*****************************/


/*
控制舵机停止
*/
void stoparm(void)
{
	char i;
	static u8 stop[5] = {0x55,0x55,0x02,0x07};
	for( i = 0 ; i < 4; i++) 
		{
			while((USART3->SR&0X40)==0);  
			USART3->DR = stop[i]; 
		}	
}

/*
*	#1G#3G#1GC2\r\n
*	通过串口调用不同动作组
*	num为动作组名称
*	
*/
void controlarm(u8 num)
{

	char i;
	
	static u8 action0[8] = {0x55,0x55,0x05,0x06,0x00,0x01,0x00};	
	static u8 action1[8] = {0x55,0x55,0x05,0x06,0x01,0x01,0x00};
	static u8 action2[8] = {0x55,0x55,0x05,0x06,0x02,0x01,0x00};
	static u8 action3[8] = {0x55,0x55,0x05,0x06,0x03,0x01,0x00};
	static u8 action4[8] = {0x55,0x55,0x05,0x06,0x04,0x01,0x00};	
	static u8 action5[8] = {0x55,0x55,0x05,0x06,0x05,0x01,0x00};	
	static u8 action6[8] = {0x55,0x55,0x05,0x06,0x06,0x01,0x00};
	static u8 action7[8] = {0x55,0x55,0x05,0x06,0x07,0x01,0x00};
	static u8 action8[8] = {0x55,0x55,0x05,0x06,0x08,0x01,0x00};
	static u8 action9[8] = {0x55,0x55,0x05,0x06,0x09,0x01,0x00};
	static u8 action10[8] = {0x55,0x55,0x05,0x06,0x0A,0x01,0x00};
	static u8 action11[8] = {0x55,0x55,0x05,0x06,0x0B,0x01,0x00};
	static u8 action12[8] = {0x55,0x55,0x05,0x06,0x0C,0x01,0x00};
	switch (num){
		case 0: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action1[i]; 
				}	
					break;
		}
		case 1: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action1[i]; 
				}	
					break;
		}
		case 2: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action2[i]; 
				}	
					break;
		}		
		case 3: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action3[i]; 
				}	
					break;
		}
		case 4: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action4[i]; 
				}	
				break;
			}
		case 5: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action5[i]; 
				}	
			break;				
		}
		case 6: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action6[i]; 
				}	
			break;				
		}	
	case 7: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action7[i]; 
				}	
			break;				
		}
		case 8: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action8[i]; 
				}	
			break;				
		}
			case 9: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action9[i]; 
				}	
			break;				
		}
				case 10: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action10[i]; 
				}	
			break;				
		}
		case 11: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action11[i]; 
				}	
			break;				
		}
			case 12: {
			for( i = 0 ; i < 7; i++) 
				{
					while((USART3->SR&0X40)==0);  
					USART3->DR = action12[i]; 
				}	
			break;				
		}
	
	}
				
}