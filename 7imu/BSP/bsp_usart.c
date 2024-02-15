#include "encoder.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "bsp_usart.h"
#include "pid.h"
#include "string.h"
#include "usart.h"
#include "cJSON.h"
uint8_t usart2_readbuf[256];
uint8_t usart2_readcount=0;
uint8_t usart2_lastreadcount=0;
void usart2_irq_userhandler()
{
	if(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_RXNE))
	{
		if(usart2_readcount>=255) usart2_readcount = 0;
		HAL_UART_Receive(&huart2,&usart2_readbuf[usart2_readcount++],1,1000);
	}
}

uint8_t usart_waitreadfinish(void)
{
	static uint16_t usart_lastreadcount = 0;
	if(usart2_readcount==0)
	{
		usart2_lastreadcount = 0;
		return 1; 
	}
	if(usart2_readcount==usart2_lastreadcount)
	{
		usart2_readcount=0;
		usart2_lastreadcount = 0;
		return 0;
	}
	usart2_lastreadcount =usart2_readcount;
	return 2;
}
float p,i,d,a;
void handler_data(tpid *pid)
{
	cJSON * cJSON_data, *cJSON_vlaue;
	if(usart_waitreadfinish()==0)
	{
		cJSON_data=cJSON_Parse((const char*)usart2_readbuf);
		
		if(cJSON_GetObjectItem(cJSON_data,"p")!=NULL)
		{
			cJSON_vlaue=cJSON_GetObjectItem(cJSON_data,"p");
			p =cJSON_vlaue->valuedouble;
			pid->kp=p;
		}
		
		if(cJSON_GetObjectItem(cJSON_data,"i")!=NULL)
		{
			cJSON_vlaue=cJSON_GetObjectItem(cJSON_data,"i");
			i =cJSON_vlaue->valuedouble;
			pid->ki=i;
		}
		
		if(cJSON_GetObjectItem(cJSON_data,"d")!=NULL)
		{
			cJSON_vlaue=cJSON_GetObjectItem(cJSON_data,"d");
			d =cJSON_vlaue->valuedouble;
			pid->kd=d;
		}
		
		if(cJSON_GetObjectItem(cJSON_data,"a")!=NULL)
		{
			cJSON_vlaue=cJSON_GetObjectItem(cJSON_data,"a");
			a =cJSON_vlaue->valuedouble;
			pid->target_val=a;
		}
		
		memset(usart2_readbuf,0,255);
		printf("p:%,3f i:%,3f d:%,3f p:%,3f\r\n",p,i,d,a);
	}
}