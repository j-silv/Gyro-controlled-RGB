#ifndef INC_USART_H_
#define INC_USART_H_

#define USARTx_INSTANCE 			  USART2
#define USARTx_CLK_ENABLE()           LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2)
#define USARTx_CLK_SOURCE()           LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1)
#define USARTx_GPIO_CLK_ENABLE()      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA)
#define USARTx_TX_PIN                 LL_GPIO_PIN_2
#define USARTx_TX_GPIO_PORT           GPIOA
#define USARTx_RX_PIN                 LL_GPIO_PIN_3
#define USARTx_RX_GPIO_PORT           GPIOA

// Struct instance --> the parameters to setup the USART peripheral
LL_USART_InitTypeDef usart_initstruct;
LL_USART_ClockInitTypeDef usartclk_initstruct;

// Struct instance --> the GPIO parameters to setup the USART pins
LL_GPIO_InitTypeDef gpio_usart_initstruct;

void Configure_USART(void);
void sendMessage(uint8_t *message, uint8_t message_length);

#endif /* INC_USART_H_ */
