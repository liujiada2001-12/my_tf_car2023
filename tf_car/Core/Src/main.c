/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "motor.h"
#include "encoder.h"
#include "pid.h"
#include "bsp_usart.h"
#include "bsp_tim.h"
#include "bsp_tim.h"
#include "move.h"
#include "imu.h"
#include "jy901.h"
#include "vision.h"
#include "arm.h"
#include "distance.h"
#include "cmd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_TIM_PeriodElapasedCallback(TIM_HandleTypeDef *htim);
void track(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern unsigned char RedORBlue;
extern uint8_t flagr;
extern uint8_t flagg;
extern unsigned char RedORBlueData[3];
int from_a_or_b=0;//0为A，1为B
uint8_t greencount=0,redcount=0;

extern float motor1speed;
extern float motor2speed;
extern float motor3speed;
extern float motor4speed;
extern float motor1mileage;
extern float motor2mileage;
extern float motor3mileage;
extern float motor4mileage;
extern float mileage;
int position_control_flag=0;
extern tpid pid1,pid2,pid3,pid4,pid1s,pidturn;
uint16_t timercount=0;
uint16_t timercount1=0;
extern short encoder1count;
extern short encoder2count;
extern short encoder3count;
extern short encoder4count;
float v1,v2,v3,v4;
extern User_USART JY901_data;
float direction0;


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int n;
	int cnt1;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM6_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim6);             //启动时基
	motor_encoder_init();
	motor_pwm_init();
	pid_init();
	__HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
	v1=0;
	v2=0;
	v3=0;
	v4=0;
	User_USART_Init(&JY901_data);
	HAL_Delay(3000);
	direction0=JY901_data.angle.angle[2];
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	

/*         D******************E******************F */
/*         *                  *                  * */
/*         *                  *                  * */
/*         *                  *                  * */
/*         A******************B******************C */
/*         *                                       */
/*         *    ********************************** */
/*         O                                       */



/***********O点到A点右转************************* */		
	
	HAL_Delay(1000);
	direction0=JY901_data.angle.angle[2];
	arm_action(3);  //舵机开始位
	gofoward(O_T0_A,direction0);  
	gocontinue(O_T0_A,direction0);  
	HAL_Delay(1000);
	turn(direction0+90);
	turn(direction0+90);
	HAL_Delay(500);
	
/***********ABC方向前进*************************** */		
	 motor_speed_set(40,40,40,40);
  for(cnt1=0;cnt1<10;cnt1++)
{
	 act1(cnt1);//识别到放置存储区回到A过程
	
/***********A点后方向选择*************************** */		
	 if(cnt1<9) //不是最后一次就左转
	 {
			direction0=JY901_data.angle.angle[2];
			turn(direction0-90);
		  turn(direction0-90);
	 }//此时车头朝ABC方向
	 
	 if(cnt1==9)//最后一次直走会出发点
	 {
		 direction0=JY901_data.angle.angle[2];
		 gofoward(O_T0_A+200,direction0);
		 gocontinue(O_T0_A+200,direction0);
	 }
}
//	
//	


















  while (1)
  {
		v1=0;
		v2=0;
		v3=0;
		v4=0;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

//		HAL_Delay(500);
//		motor_pwm_set(-40,-40,-40,-40);
//		uint8_t c_Data[]="及你太美\r\n";
//		HAL_UART_Transmit(&huart1,c_Data,sizeof(c_Data),0xffff);
//		handler_data(&pid1);
//		printf("1:%d\r\n",encoder1count);
//		printf("2:%d\r\n",encoder2count);
//		printf("3:%d\r\n",encoder3count);
//		printf("4:%d\r\n",encoder4count);
		HAL_Delay(10);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   	if(htim == &htim6)//1ms 1000hz
	{
		timercount++;
		timercount1++;
//		imu_getdata();
//		if(timercount1<=5000)
//		{
//			v2=80;
//		}
//		else{
//			v2=0;
//		}
		if(timercount%10 == 0)//10ms计算速度
		{
			motor_encoder_getdata();
		}
		if(timercount%20 == 0)//20ms计算速度
		{
			pid_realize_turn(&pidturn,JY901_data.angle.angle[2]);
			if(position_control_flag==1)
			{
					motor_getmmileage();
					pid_realize_s(&pid1s,mileage);
				motor_speedpid_conrol(pid1s.out-pidturn.out,pid1s.out+pidturn.out,pid1s.out+pidturn.out,pid1s.out-pidturn.out);
			}
			else
			{

				motor_speedpid_conrol(v1-pidturn.out,v2+pidturn.out,v3+pidturn.out,v4-pidturn.out);
//				motor_speedopenloop_conrol(40,40,40,40);
				float data1,data2,data3;
				data1=(float)JY901_data.angle.angle[0];
				data2=(float)JY901_data.angle.angle[1];
				data3=(float)JY901_data.angle.angle[2];
				printf("%.2f,%.2f,%.2f\n",data1,data2,data3);
			}
			timercount=0;
		}
	}
}

void track(void)
{
	int fl,fr,ml,mr;
	fl=HAL_GPIO_ReadPin(FL_light_GPIO_Port,FL_light_Pin);
	fr=HAL_GPIO_ReadPin(FR_light_GPIO_Port,FR_light_Pin);
	ml=HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin);
	mr=HAL_GPIO_ReadPin(MR_light_GPIO_Port,MR_light_Pin);
	
		if(fl ==0 && fr ==1)
		{
			v1=40;
			v3=10;
			v2=10;
			v4=40;
		}
		else if(fl ==1 && fr ==0)
		{
			v1=10;
			v3=40;
			v2=40;
			v4=10;
		}
		else
		{
			v1=40;
			v3=40;
			v2=40;
			v4=40;
		}
		
		if((fl == 0 && fr == 0)||(fl == 1&& fr == 1))//直走
		{
			HAL_Delay(500);
			if((fl == 0 && fr == 0)||(fl == 1&& fr == 1))
			{
			v1=40;
			v3=40;
			v2=40;
			v4=40;
			HAL_Delay(500);

			 }
		}
}
int light;
/******************识别到放置存储区回到A过程***********/
void act1(uint8_t action_cnt)
{
	mileage=0;
	light=HAL_GPIO_ReadPin(Light_GPIO_Port,Light_Pin);
	 flagr=flagg=0;
	/******************循迹等待识别到盆栽***********/
   while(1)
  { 
		track();
		if(LIGHT==0)
		{
			HAL_Delay(20);//消抖
			if(LIGHT==0)
			{
			motor_stop();
			HAL_Delay(1000);
      arm_action(6);                   // 转过去识别
			__HAL_UART_ENABLE_IT(&huart4,UART_IT_IDLE);  
			vision_handler();
			HAL_Delay(2500);
			if(flagr)
			{redcount++;}
			if(flagg) 
			{greencount++;}
			__HAL_UART_DISABLE_IT(&huart4,UART_IT_IDLE);
//			HAL_Delay(1000);
			arm_action(1);                  //  抓取和回中
			HAL_Delay(3000); 
			break;
			}
		}		
  }
motor_stop();
HAL_Delay(1000);
if(action_cnt+1<=5&&flagg)//次数小于5且为绿
{
 flagg=0;
 direction0=JY901_data.angle.angle[2];
	
 while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}
// gocontinue(A_T0_B,direction0);
// gocontinue(A_T0_B,direction0);
// mileage=0;
//	direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
// turn(direction0-90);
 direction0=JY901_data.angle.angle[2];
 gofoward(B_T0_E,direction0);
	gocontinue(B_T0_E,direction0);
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
 turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];//两次左转即AB向到B到E转向D

 gocontinue(greencount*1500,direction0);
 motor_stop();
 HAL_Delay(1000);
 arm_action(2);
 HAL_Delay(4500);//计算走的距离并放下
 motor_stop();
 HAL_Delay(100);
 gocontinue(E_T0_D,direction0); 
 gocontinue(E_T0_D,direction0); 
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90);   
 turn(direction0-90); 
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(D_T0_A,direction0);//继续向前左转回A
 gocontinue(D_T0_A,direction0);
 from_a_or_b=0;
 HAL_Delay(750);
}
if(action_cnt+1>5&&flagg)//次数大于5且为绿
{
 flagg=0;
 direction0=JY901_data.angle.angle[2];
	
 while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}
	
//	if(from_a_or_b==0)
//	{
//		gocontinue(A_T0_B+B_T0_C,direction0);
//	}
//	if(from_a_or_b==1)
//	{
//		gocontinue(B_T0_C,direction0);
//	}
// mileage=0;
// direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
// turn(direction0-90);
	
 direction0=JY901_data.angle.angle[2];
 gofoward(C_T0_F,direction0);
 gocontinue(C_T0_F,direction0);
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
 turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2]; //两次左转即ABC向到F转向E

 gocontinue(F_T0_E+greencount*1500,direction0);						//FED向过E
 motor_stop();
 HAL_Delay(1000);
 arm_action(2);
 HAL_Delay(4500);//计算走的距离并放下
 motor_stop();
 HAL_Delay(100);

 gocontinue(E_T0_D+F_T0_E,direction0); 
  gocontinue(E_T0_D+F_T0_E,direction0); 
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90);  
 turn(direction0-90);  
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(D_T0_A,direction0);             //继续循迹向前左转回A
 gocontinue(D_T0_A,direction0); 
 from_a_or_b=0;
 HAL_Delay(750);
}
if(flagr && action_cnt+1<=5) //次数小于5且为红
{
 flagr=0;
 direction0=JY901_data.angle.angle[2];
	
	while(1)
{
 track();
 if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0&&HAL_GPIO_ReadPin(MR_light_GPIO_Port,MR_light_Pin)==1)
 {
  HAL_Delay(1000);
	break;
 }
}
	 while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}
//	if(from_a_or_b==0)
//	{
//		gocontinue(A_T0_B+B_T0_C,direction0);
//		gocontinue(A_T0_B+B_T0_C,direction0);
//	}
//	if(from_a_or_b==1)
//	{
//		gocontinue(B_T0_C,direction0);
//		gocontinue(B_T0_C,direction0);
//	}             //过B继续到C
// 
// mileage=0;
// direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
// turn(direction0-90);

 direction0=JY901_data.angle.angle[2];
 gofoward(C_T0_F,direction0);
	gocontinue(C_T0_F,direction0);
	direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
 turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];               //两次左转即ABC向到F转向E

 gocontinue(redcount*1500,direction0);
	motor_stop();
 HAL_Delay(1000);
 arm_action(2);
 HAL_Delay(4500);//计算走的距离并放下
 motor_stop();
 HAL_Delay(100);//////根据红色盆栽数延时走距离并放下

 gocontinue(E_T0_D+F_T0_E,direction0);               //FED向循迹过E
 gocontinue(E_T0_D+F_T0_E,direction0);  
 direction0=JY901_data.angle.angle[2];
  turn(direction0-90);    
	turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(D_T0_A,direction0);                    //继续循迹向前左转回A
 gocontinue(D_T0_A,direction0);   
 from_a_or_b=0;
 HAL_Delay(750);
}

if(flagr && action_cnt+1>5 && action_cnt+1<=9)//次数大于5且为红
{
 flagr=0;
	
 direction0=JY901_data.angle.angle[2];
	
	 while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}
// if(from_a_or_b==0)
//	{
//		gocontinue(A_T0_B+B_T0_C,direction0);
//	}
//	if(from_a_or_b==1)
//	{
//		gocontinue(B_T0_C,direction0);
//	}
//	
// mileage=0;
//	direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
//	turn(direction0-90);
	
	
 direction0=JY901_data.angle.angle[2];
 gofoward(C_T0_F,direction0);
 gocontinue(C_T0_F,direction0);
	direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
 turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];                         //两次左转即ABC向到F转向E

	
 gocontinue(redcount*1500,direction0);
	
	motor_stop();
 HAL_Delay(1000);
 arm_action(2);
 HAL_Delay(4500);//计算走的距离并放下
 motor_stop();
 HAL_Delay(100);/////////根据红色盆栽数延时走距离并放下
 
 gocontinue(B_T0_E,direction0);               //FED向到E
  gocontinue(B_T0_E,direction0); 
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90);   
turn(direction0-90);	
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(B_T0_E,direction0);      
gocontinue(B_T0_E,direction0); //继续向前左转回B，不是最后一次会左转即朝ABC向
 from_a_or_b=1;
	HAL_Delay(750);
}

if(flagr && action_cnt+1==10)//最后一个是红色
{
 flagr=0;                      
	
 direction0=JY901_data.angle.angle[2];
	
while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}	
// if(from_a_or_b==0)
//	{
//		gocontinue(A_T0_B+B_T0_C,direction0);
//	}
//	if(from_a_or_b==1)
//	{
//		gocontinue(B_T0_C,direction0);
//	}
//	
//	mileage=0;
//	direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
//	turn(direction0-90);
	
	
 direction0=JY901_data.angle.angle[2];
 gofoward(C_T0_F,direction0);
	gocontinue(C_T0_F,direction0);
	direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
	turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2]; //两次左转即ABC向到F转向E

 gocontinue(redcount*1500,direction0);           //根据红色盆栽数延时走距离并放下
 motor_stop();
HAL_Delay(100);
 gocontinue(E_T0_D+F_T0_E,direction0);               //FED向循迹过E
	 gocontinue(E_T0_D+F_T0_E,direction0);
	direction0=JY901_data.angle.angle[2];
  turn(direction0-90);    
	turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(D_T0_A,direction0);                        //继续向前左转回A
 gocontinue(D_T0_A,direction0);      
	from_a_or_b=0;
	HAL_Delay(750);
}
if(flagg && action_cnt+1==10)//最后一个是绿的
{
	 flagg=0;
	
	direction0=JY901_data.angle.angle[2];
	
while(1)
{
  track();
	if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
	{
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(ML_light_GPIO_Port,ML_light_Pin)==0)
		{
				mileage=0;
				direction0=JY901_data.angle.angle[2];
				turn(direction0-90);
				turn(direction0-90);
			break;
		}
	
	}
}	
// if(from_a_or_b==0)
//	{
//		gocontinue(A_T0_B+B_T0_C,direction0);
//	}
//	if(from_a_or_b==1)
//	{
//		gocontinue(B_T0_C,direction0);
//	}
//	
//	mileage=0;
//	direction0=JY901_data.angle.angle[2];
// turn(direction0-90);
//	turn(direction0-90);
	
	
 direction0=JY901_data.angle.angle[2];
 gofoward(C_T0_F,direction0);
	gocontinue(C_T0_F,direction0);    
	direction0=JY901_data.angle.angle[2];
 turn(direction0-90);
	turn(direction0-90);
 mileage=0;
 direction0=JY901_data.angle.angle[2];  //两次左转即ABC向到F转向E

 gocontinue(F_T0_E+greencount*1500,direction0);						//FED向过E
 motor_stop();
 HAL_Delay(1000);
 arm_action(2);
 HAL_Delay(4500);//计算走的距离并放下
 motor_stop();
 HAL_Delay(100);        //根据绿色盆栽数延时走距离并放下
 
	
	 gocontinue(E_T0_D+F_T0_E,direction0);               //FED向循迹过E
	  gocontinue(E_T0_D+F_T0_E,direction0);  
 direction0=JY901_data.angle.angle[2];
 turn(direction0-90); 
 turn(direction0-90);	
 mileage=0;
 direction0=JY901_data.angle.angle[2];
 gofoward(D_T0_A,direction0);                        //继续向前左转回A
 gocontinue(D_T0_A,direction0);   
	from_a_or_b=0;                      
	HAL_Delay(750);
}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
