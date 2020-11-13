#ifndef INC_LED_H_
#define INC_LED_H_

// Onboard LED
#define LED2_PIN                           LL_GPIO_PIN_5
#define LED2_GPIO_PORT                     GPIOA
#define LED2_GPIO_CLK_ENABLE()             LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA)

LL_GPIO_InitTypeDef gpio_led_initstruct;

void Configure_LED(void);

#endif /* INC_LED_H_ */
