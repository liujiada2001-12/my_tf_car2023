#include "move.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "gpio.h"
#include "usart.h"
#include "main.h"
#include "cmd.h"
#include "arm.h"
#include "vision.h"
unsigned char RedORBlue=0;
uint8_t flagr=0;
uint8_t flagg=0;
unsigned char RedORBlueData[3];

void vision_handler(void)
{
	static uint8_t iii;

	  HAL_UART_Receive_IT(&huart4,&RedORBlueData[iii++],1);
//		RedORBlueData[iii++] = UART4->DR;

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
