#include "main.h"

LL_GPIO_InitTypeDef gpio_initstruct;
LL_USART_InitTypeDef usart_initstruct;
LL_USART_ClockInitTypeDef usartclk_initstruct;

// Function prototypes
void Configure_SysTick(void);
void SystemClock_Config(void);
void Configure_GPIO(void);
void Configure_USART(void);
void sendMessage(uint8_t *message, uint8_t message_length);


// USART variables
const uint8_t terminal_setup_msg[] = "***USART COMM WITH LED BLINKY***\r\n";
uint8_t nb_bytes_sent = 0;

int main(void)
{
  // Configure the system clock to 48 MHz
  SystemClock_Config();
  
  // Configure LED pin
  Configure_GPIO();

  // Configure USART peripheral
  Configure_USART();

  // Enable SYSTICK interrupt and set its RELOAD register value
  SysTick_Config(SYSCLK_HZ/4); // interrupt triggered every 250 ms

  // Setup terminal message
  sendMessage((uint8_t*)terminal_setup_msg, sizeof(terminal_setup_msg));

  // Send classic message
  sendMessage((uint8_t*)"Hello, World!\r\n", sizeof("Hello, World!\r\n"));

  // Endless loop (application)
  while (1)
  {
  }
}


void Configure_USART(void)
{
	/* Enable the peripheral clock of GPIO Port */
	USARTx_GPIO_CLK_ENABLE();

	/* Configure Tx Pin as : Alternate function, High Speed, Push pull, Pull up */
	LL_GPIO_SetPinMode(USARTx_TX_GPIO_PORT, USARTx_TX_PIN, LL_GPIO_MODE_ALTERNATE);
	USARTx_SET_TX_GPIO_AF();
	LL_GPIO_SetPinSpeed(USARTx_TX_GPIO_PORT, USARTx_TX_PIN, LL_GPIO_SPEED_FREQ_HIGH);
	LL_GPIO_SetPinOutputType(USARTx_TX_GPIO_PORT, USARTx_TX_PIN, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinPull(USARTx_TX_GPIO_PORT, USARTx_TX_PIN, LL_GPIO_PULL_UP);

	/* Configure Rx Pin as : Alternate function, High Speed, Push pull, Pull up */
	LL_GPIO_SetPinMode(USARTx_RX_GPIO_PORT, USARTx_RX_PIN, LL_GPIO_MODE_ALTERNATE);
	USARTx_SET_RX_GPIO_AF();
	LL_GPIO_SetPinSpeed(USARTx_RX_GPIO_PORT, USARTx_RX_PIN, LL_GPIO_SPEED_FREQ_HIGH);
	LL_GPIO_SetPinOutputType(USARTx_RX_GPIO_PORT, USARTx_RX_PIN, LL_GPIO_OUTPUT_PUSHPULL);
	LL_GPIO_SetPinPull(USARTx_RX_GPIO_PORT, USARTx_RX_PIN, LL_GPIO_PULL_UP);

	/* Enable USART peripheral clock and clock source ***********************/
	USARTx_CLK_ENABLE();

	/* Set clock source */
	USARTx_CLK_SOURCE();

	// Configure USART with default values in USART struct
	LL_USART_StructInit(&usart_initstruct);

	// Set up USART peripheral
	LL_USART_Init(USARTx_INSTANCE, &usart_initstruct);

	// Configure USART clock with default values in USART clock struct
	LL_USART_ClockStructInit(&usartclk_initstruct);

	// Set up USART clock settings
	LL_USART_ClockInit(USARTx_INSTANCE, &usartclk_initstruct);

	// Turn on USART
	LL_USART_Enable(USARTx_INSTANCE);

	/* Polling USART initialisation */
	while((!(LL_USART_IsActiveFlag_TEACK(USARTx_INSTANCE))) || (!(LL_USART_IsActiveFlag_REACK(USARTx_INSTANCE))))
	{
	}
}

void Configure_GPIO(void)
{
  /* Enable the LED2 Clock */
  LED2_GPIO_CLK_ENABLE();

  /* Configure IO in output push-pull mode to drive external LED2 */
  gpio_initstruct.Pin        = LED2_PIN;
  gpio_initstruct.Mode       = LL_GPIO_MODE_OUTPUT;
  gpio_initstruct.Speed      = LL_GPIO_SPEED_FREQ_LOW;
  gpio_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  gpio_initstruct.Pull       = LL_GPIO_PULL_NO;

  /* Initialize LED2_GPIO_PORT port according to parameters defined in initialization structure. */
  if (LL_GPIO_Init(LED2_GPIO_PORT, &gpio_initstruct) != SUCCESS)
  {
    /* Initialization Error */
    while (1)
    {
    }
  }
}


void sendMessage(uint8_t *message, uint8_t message_length)
{
  /* Send characters one per one, until last char to be sent */
  while (nb_bytes_sent < message_length)
  {
    /* Wait for TXE flag (data register empty) to be raised */
    while (!LL_USART_IsActiveFlag_TXE(USARTx_INSTANCE))
    {
    }

    /* Copied from example --> doesn't seem to be important for our purposes
    // If last char to be sent, clear TC flag
    if (ubSend == (sizeof(aStringToSend) - 1))
    {
      LL_USART_ClearFlag_TC(USARTx_INSTANCE);
    }
    */

    /* Write character in Transmit Data register.
       TXE flag is cleared by writing data in TDR register */
    // return current value of pointer, then increment the pointer position
    LL_USART_TransmitData8(USARTx_INSTANCE, *(message)++);

    nb_bytes_sent++;
  }

  /* Wait for TC flag to be raised for last char */
  while (!LL_USART_IsActiveFlag_TC(USARTx_INSTANCE))
  {
  }

  /* Wait for TXE flag to be raised to assure that a new transmission can take place */
  while (!LL_USART_IsActiveFlag_TXE(USARTx_INSTANCE))
  {
  }

  /* Tx sequence completed successfully --> reset nb_bytes_sent */
  nb_bytes_sent=0;
}



// Function called from SysTick interrupt handler
void SysTick_Callback(void)
{
	LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
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
