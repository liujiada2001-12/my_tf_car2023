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
#include "move.h"
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
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern float motor1speed;
extern float motor2speed;
extern float motor3speed;
extern float motor4speed;
extern float motor1mileage;
extern float motor2mileage;
extern float motor3mileage;
extern float motor4mileage;
extern tpid pid1,pid2,pid3,pid4,pid1s;
uint16_t timercount=0;
uint16_t timercount1=0;
int position_control_flag=0;
extern short encoder1count;
extern short encoder2count;
extern short encoder3count;
extern short encoder4count;
float v1,v2,v3,v4;
extern User_USART JY901_data;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	track();
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
			
			if(position_control_flag==1)
			{
					motor_getmmileage();
					pid1s.target_val=6000;
					pid_realize_s(&pid1s,motor1mileage);
				motor_speedpid_conrol(pid1s.out,pid1s.out,pid1s.out,pid1s.out);
			}
			else
			{
				motor1mileage=0;
				motor2mileage=0;
				motor3mileage=0;
				motor4mileage=0;
				motor_speedpid_conrol(v1,v2,v3,v4);
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
