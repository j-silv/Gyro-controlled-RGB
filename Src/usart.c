#include "main.h"

void Configure_USART(void)
{
	/* Enable the AHB clock of the GPIO Port that the USART peripheral is connected to */
	USARTx_GPIO_CLK_ENABLE();

	/* Configure Tx Pin as : Alternate function, High Speed, Push pull, Pull up */
	gpio_usart_initstruct.Pin        = USARTx_TX_PIN;
	gpio_usart_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_usart_initstruct.Speed      = LL_GPIO_SPEED_FREQ_LOW;
	gpio_usart_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_usart_initstruct.Pull       = LL_GPIO_PULL_UP;
	gpio_usart_initstruct.Alternate  = LL_GPIO_AF_1; // Mapped to USART2 peripheral

	/* Initialize USART2_TX_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(USARTx_TX_GPIO_PORT, &gpio_usart_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	/* Configure Rx Pin as : Alternate function, High Speed, Push pull, Pull up */
	gpio_usart_initstruct.Pin        = USARTx_RX_PIN;
	gpio_usart_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_usart_initstruct.Speed      = LL_GPIO_SPEED_FREQ_LOW;
	gpio_usart_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_usart_initstruct.Pull       = LL_GPIO_PULL_UP;
	gpio_usart_initstruct.Alternate  = LL_GPIO_AF_1; // Mapped to USART2 peripheral

	/* Initialize USART2_RX_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(USARTx_RX_GPIO_PORT, &gpio_usart_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	/* Enable the APB clock for the USART peripheral*/
	USARTx_CLK_ENABLE();

	/* Set clock source */
	USARTx_CLK_SOURCE();

	// Configure USART with default values in USART struct
	LL_USART_StructInit(&usart_initstruct);

	/* Initialize USART2 according to parameters defined in initialization structure. */
	if (LL_USART_Init(USARTx_INSTANCE, &usart_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure USART clock with default values in USART clock struct
	LL_USART_ClockStructInit(&usartclk_initstruct);

	/* Initialize USART2 Clock according to parameters defined in initialization structure. */
	if (LL_USART_ClockInit(USARTx_INSTANCE, &usartclk_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Turn on USART
	LL_USART_Enable(USARTx_INSTANCE);

	/* Polling USART initialisation */
	while((!(LL_USART_IsActiveFlag_TEACK(USARTx_INSTANCE))) || (!(LL_USART_IsActiveFlag_REACK(USARTx_INSTANCE))))
	{
	}
}


void sendMessage(uint8_t *message, uint8_t message_length)
{

  uint8_t nb_bytes_sent = 0;

  /* Send characters one per one, until last char to be sent */
  while (nb_bytes_sent < message_length)
  {
    /* Wait for TXE flag (data register empty) to be raised */
    while (!LL_USART_IsActiveFlag_TXE(USARTx_INSTANCE))
    {
    }

    /* Write character in Transmit Data register.
       TXE flag is cleared by writing data in TDR register */
    LL_USART_TransmitData8(USARTx_INSTANCE, message[nb_bytes_sent++]);

    /******* Another way to transmit data with pointer arithmetic ********/
    /* return current value of pointer, then increment the pointer position
    LL_USART_TransmitData8(USARTx_INSTANCE, *(message)++);
    nb_bytes_sent++; */
  }

  /* Wait for TC flag to be raised for last char */
  while (!LL_USART_IsActiveFlag_TC(USARTx_INSTANCE))
  {
  }

  // Tx sequence completed successfully
}
