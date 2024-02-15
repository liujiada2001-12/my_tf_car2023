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
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "vofa.h"
#include "string.h"
#include "bsp_pid.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
float MotorSpeed1;  // 电机当前速度数值，从编码器中获取
float MotorSpeed2;  // 电机当前速度数值，从编码器中获取
float MotorSpeed3;  // 电机当前速度数值，从编码器中获取
float MotorSpeed4;  // 电机当前速度数值，从编码器中获取
int MotorOutput1;		  // 电机输出
int MotorOutput2;		  // 电机输出
int MotorOutput3;		  // 电机输出
int MotorOutput4;		  // 电机输出
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
extern _pid pid1,pid2,pid3,pid4,pidAs,pidBs,pid1,pid2;//pidx->速度PID量，pidxs->位置PID量
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_RTC_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_UART4_Init();
  MX_USART3_UART_Init();
  MX_TIM6_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);	    // TIM3_CH1(pwm)
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);	    // TIM3_CH2(pwm)
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);	    // TIM3_CH3(pwm)
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);	    // TIM3_CH4(pwm)
	
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1); // 开启编码器1A
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_2); // 开启编码器1B
	
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_1); // 开启编码器1A
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_2); // 开启编码器1B
	
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_1); // 开启编码器1A
  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_2); // 开启编码器1B	

	HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_1); // 开启编码器1A
  HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_2); // 开启编码器1B

  HAL_TIM_Base_Start_IT(&htim6);                // 使能定时器2中断
	PID_param_init();
  while (1)
  {
		int a=0;
		int b=0;
		a=HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_7);
		b=HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_8);

		if(a==1 &&b ==0)
		{
			pid1.aim=4000;
			pid2.aim=-4000;
			pid3.aim=4000;
			pid4.aim=-4000;
		}
		else if(a==0&&b==1)
		{
			pid1.aim=-4000;
			pid2.aim=4000;
			pid3.aim=4000;
			pid4.aim=-4000;
		}
		else
		{
			pid1.aim=4000;
			pid2.aim=4000;
			pid3.aim=4000;
			pid4.aim=4000;
		}
		HAL_Delay(5);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

int ctt=0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static unsigned char i = 0;
    if (htim == (&htim6))
    {
			ctt++;
        //1.获取电机速度
        pid1.now = (short)(__HAL_TIM_GET_COUNTER(&htim2)/18);   
			  pid2.now = (short)(__HAL_TIM_GET_COUNTER(&htim3)/18); 
				pid3.now = (short)(__HAL_TIM_GET_COUNTER(&htim4)/18);  
			  pid4.now = (short)(__HAL_TIM_GET_COUNTER(&htim5)/18);  
        // TIM4计数器获得电机脉冲，该电机在10ms采样的脉冲/18则为实际转速的rpm
        __HAL_TIM_SET_COUNTER(&htim6,0);  // 计数器清零
			
        //2.将占空比导入至电机控制函数
//        pid1.aim=4000; // 3600即为50%的占空比
//			  pid2.aim=4000; // 3600即为50%的占空比
//			  pid3.aim=4000; // 3600即为50%的占空比
//			  pid4.aim=4000; // 3600即为50%的占空比
			
				speed_pid_calculate(&pid1);
			  speed_pid_calculate(&pid2);
			  speed_pid_calculate(&pid3);
			  speed_pid_calculate(&pid4);

				motor1((int)pid1.out);
			  motor2((int)pid2.out);
			  motor3((int)pid3.out);
			  motor4((int)pid4.out);
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
