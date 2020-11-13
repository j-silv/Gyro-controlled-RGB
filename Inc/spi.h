#ifndef INC_SPI_H_
#define INC_SPI_H_

#define SPIx_INSTANCE 			      SPI2
#define SPIx_CLK_ENABLE()             LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2)
// set clock source for SPI peripheral like for USART?
#define SPIx_GPIO_CLK_ENABLE()        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB)
#define SPIx_SCK_PIN				  LL_GPIO_PIN_3
#define SPIx_SCK_GPIO_PORT			  GPIOB
#define SPIx_MISO_PIN				  LL_GPIO_PIN_4
#define SPIx_MISO_GPIO_PORT			  GPIOB
#define SPIx_MOSI_PIN				  LL_GPIO_PIN_5
#define SPIx_MOSI_GPIO_PORT			  GPIOB

LL_SPI_InitTypeDef spi_initstruct;
LL_GPIO_InitTypeDef gpio_spi_initstruct;

void Configure_SPI(void);
void testSPIDevice(void);

#endif /* INC_SPI_H_ */
