#ifndef INC_USART_H_
#define INC_USART_H_

LL_USART_InitTypeDef usart_initstruct;
LL_USART_ClockInitTypeDef usartclk_initstruct;

void Configure_USART(void);
void sendMessage(uint8_t *message, uint8_t message_length);

#endif /* INC_USART_H_ */
