#include "sys.h"
#include "bsp_openmv.h"
#include "usart.h"
unsigned char RedORBlue=0;
u8 flagr=0;
u8 flagg=0;
unsigned char RedORBlueData[3];

//举例：   HAL_UART_Transmit(&huart1, (uint8_t *)ZZX, 3, 0xffff);   //串口发送三个字节数据，最大传输时间0xffff
//HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
//串口中断接收，以中断方式接收指定长度数据。
//大致过程是，设置数据存放位置，接收数据长度，然后使能串口接收中断。接收到数据时，会触发串口中断。
//再然后，串口中断函数处理，直到接收到指定长度数据，而后关闭中断，进入中断接收回调函数，不再触发接收中断。(只触发一次中断)
//while(HAL_UART_GetState(&huart4) == HAL_UART_STATE_BUSY_TX)   //检测UART发送结束
/**************** **********************/

void openmv_init(void)
{
		 __HAL_UART_ENABLE_IT(&huart4,UART_IT_IDLE);
		
}



void USART4_IRQHandler(void)
{
	static u8 iii;
	
	if(huart4.Instance->SR & UART_FLAG_RXNE)
	{
		RedORBlueData[iii++] = UART4->DR;
	}
	if(huart4.Instance->SR & UART_FLAG_IDLE)
	{
		printf("RedORBlueData[0]:%c\t RedORBlueData[1]:%c\t RedORBlueData[2]:%c\t\r\n",RedORBlueData[0],RedORBlueData[1],RedORBlueData[2]);
		if(iii>2){iii=0;}
		
		if(RedORBlueData[0]=='R' && RedORBlueData[1]=='R' && RedORBlueData[2]=='R' )
			{
			RedORBlue = 'R';
				flagr=1;
				flagg=0;
				
		  }
		if(RedORBlueData[0]=='G' && RedORBlueData[1]=='G' && RedORBlueData[2]=='G' )
			{
			RedORBlue = 'G';
				flagg=1;
				flagr=0;
		  }
		
		  
	}

}


