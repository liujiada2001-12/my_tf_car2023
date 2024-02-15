#include "sys.h"
#include "bsp_openmv.h"
#include "usart.h"
unsigned char RedORBlue=0;
u8 flagr=0;
u8 flagg=0;
unsigned char RedORBlueData[3];

//������   HAL_UART_Transmit(&huart1, (uint8_t *)ZZX, 3, 0xffff);   //���ڷ��������ֽ����ݣ������ʱ��0xffff
//HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
//�����жϽ��գ����жϷ�ʽ����ָ���������ݡ�
//���¹����ǣ��������ݴ��λ�ã��������ݳ��ȣ�Ȼ��ʹ�ܴ��ڽ����жϡ����յ�����ʱ���ᴥ�������жϡ�
//��Ȼ�󣬴����жϺ�������ֱ�����յ�ָ���������ݣ�����ر��жϣ������жϽ��ջص����������ٴ��������жϡ�(ֻ����һ���ж�)
//while(HAL_UART_GetState(&huart4) == HAL_UART_STATE_BUSY_TX)   //���UART���ͽ���
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


