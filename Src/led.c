#include "main.h"

void Configure_LED(void)
{
  /* Enable the LED2 Clock */
  LED2_GPIO_CLK_ENABLE();

  /* Configure IO in output push-pull mode to drive external LED2 */
  gpio_led_initstruct.Pin        = LED2_PIN;
  gpio_led_initstruct.Mode       = LL_GPIO_MODE_OUTPUT;
  gpio_led_initstruct.Speed      = LL_GPIO_SPEED_FREQ_LOW;
  gpio_led_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  gpio_led_initstruct.Pull       = LL_GPIO_PULL_NO;

  /* Initialize LED2_GPIO_PORT port according to parameters defined in initialization structure. */
  if (LL_GPIO_Init(LED2_GPIO_PORT, &gpio_led_initstruct) != SUCCESS)
  {
    /* Initialization Error */
    while (1)
    {
    }
  }
}


