/**
  ******************************************************************************
  * File: Main application code
  * Author: Justin Silver
  *
  * 
  * The SPI communication line is tested with accelerometer peripheral
  * 
  *
  ******************************************************************************
  */

#include "main.h"

const uint8_t terminal_setup_msg[] = "***USART COMM SPI TEST***\r\n";
uint8_t SPI_RX_buffer;

int main(void)
{
  // Configure the system clock to 48 MHz
  SystemClock_Config();

  /* PERIPHERALS */
  Configure_LED();
  Configure_USART();
  Configure_SPI();

  /* FOR TESTING, DISABLE INTERRUPTS
  // Enable SYSTICK interrupt and set its RELOAD register value
  SysTick_Config(SYSCLK_HZ/4); // interrupt triggered every 250 ms
  */

  // Send setup message
  sendMessage((uint8_t*)terminal_setup_msg, sizeof(terminal_setup_msg));


  // Turn measurement mode ON in SPI slave
  configSlave();
  // Check device ID and store in receive buffer
  SPI_RX_buffer = checkSlaveID();
  // Print out result and see if it matches actual ID (in ISO 8859-1, result should be SHY = 0x00AD)
  sendMessage(&SPI_RX_buffer,sizeof(SPI_RX_buffer));

  // Endless loop (application)
  while (1)
  {
  }
}


// Function called from SysTick interrupt handler
void SysTick_Callback(void)
{
	if (LL_GPIO_IsOutputPinSet(LED2_GPIO_PORT,LED2_PIN))
	{
		LL_GPIO_ResetOutputPin(LED2_GPIO_PORT,LED2_PIN);
		//sendMessage((uint8_t*)"LED is OFF\r\n", sizeof("LED is OFF\r\n"));
	}

	else
	{
		LL_GPIO_SetOutputPin(LED2_GPIO_PORT,LED2_PIN);
		//sendMessage((uint8_t*)"LED is ON\r\n", sizeof("LED is ON\r\n"));
	}
}




/* ==============   BOARD SPECIFIC CONFIGURATION CODE BEGIN    ============== */
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSI48)
  *            SYSCLK(Hz)                     = 48000000
  *            HCLK(Hz)                       = 48000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            HSI Frequency(Hz)              = 48000000
  *            PREDIV                         = 2
  *            PLLMUL                         = 2
  *            Flash Latency(WS)              = 1
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  /* Set FLASH latency */ 
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);

  /* Enable HSI48 and wait for activation*/
  LL_RCC_HSI48_Enable(); 
  while(LL_RCC_HSI48_IsReady() != 1) 
  {
  };
  
  /* Main PLL configuration and activation */
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI48, LL_RCC_PLL_MUL_2, LL_RCC_PREDIV_DIV_2);
  
  LL_RCC_PLL_Enable();
  while(LL_RCC_PLL_IsReady() != 1)
  {
  };
  
  /* Sysclk activation on the main PLL */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  };
  
  /* Set APB1 prescaler */
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  
  /* Set systick to 1ms in using frequency set to 48MHz */
  /* This frequency can be calculated through LL RCC macro */
  /* ex: __LL_RCC_CALC_PLLCLK_FREQ (HSI48_VALUE, LL_RCC_PLL_MUL_2, LL_RCC_PREDIV_DIV_2) */
  LL_Init1msTick(SYSCLK_HZ);
  
  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(SYSCLK_HZ);
}
/* ==============   BOARD SPECIFIC CONFIGURATION CODE END      ============== */


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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
