#include "main.h"

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

	/* Enable USART peripheral clock and clock source */
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
