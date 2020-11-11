#ifndef INC_SPI_H_
#define INC_SPI_H_

LL_SPI_InitTypeDef spi_initstruct;

LL_GPIO_InitTypeDef gpio_spi_initstruct;

void Configure_SPI(void);
void testSPIDevice(void);

#endif /* INC_SPI_H_ */
