/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

// Low-level STM32 drivers
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_utils.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_ll_usart.h"
#include "stm32f0xx_ll_spi.h"
#include "stm32f0xx_ll_cortex.h"

// Peripherals
#include "spi.h"
#include "usart.h"
#include "led.h"

// Function prototypes
void Configure_SysTick(void);
void SystemClock_Config(void);
void SysTick_Callback(void);


#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */


// Clk frequency
#define SYSCLK_HZ 48000000 // 48 MHz

// Onboard push button
#define USER_BUTTON_PIN                         LL_GPIO_PIN_13
#define USER_BUTTON_GPIO_PORT                   GPIOC
#define USER_BUTTON_GPIO_CLK_ENABLE()           LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC)   
#define USER_BUTTON_EXTI_LINE                   LL_EXTI_LINE_13
#define USER_BUTTON_EXTI_IRQn                   EXTI4_15_IRQn
#define USER_BUTTON_EXTI_LINE_ENABLE()          LL_EXTI_EnableIT_0_31(USER_BUTTON_EXTI_LINE)   
#define USER_BUTTON_EXTI_FALLING_TRIG_ENABLE()  LL_EXTI_EnableFallingTrig_0_31(USER_BUTTON_EXTI_LINE)   
#define USER_BUTTON_SYSCFG_SET_EXTI()           do {                                                                     \
                                                  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);                  \
                                                  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTC, LL_SYSCFG_EXTI_LINE13);  \
                                                } while(0)
#define USER_BUTTON_IRQHANDLER                  EXTI4_15_IRQHandler

#endif /* __MAIN_H */
