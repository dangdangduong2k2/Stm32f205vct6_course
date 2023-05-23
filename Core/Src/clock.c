#include "clock.h" 


void system_clock_peripheral_init(void)
{
      
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    ////////////////////////////////////////////////
    
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
}

void SystemClock_Config(void)
{
  
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

 
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
  } 

  
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
  }
}