#include "main.h"

void Configure_SPI(void)
{
	// Enable the peripheral clock of GPIOB
	SPIx_GPIO_CLK_ENABLE();

	// Configure SCK Pin connected to pin 31 of CN10 connector
	gpio_spi_initstruct.Pin        = SPIx_SCK_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI2 peripheral

	/* Initialize SPI2_SCK_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_SCK_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure MISO Pin connected to pin 27 of CN10 connector
	gpio_spi_initstruct.Pin        = SPIx_MISO_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI2 peripheral

	/* Initialize SPI2_MISO_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_MISO_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure MOSI Pin connected to pin 29 of CN10 connector
	gpio_spi_initstruct.Pin        = SPIx_MOSI_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI2 peripheral

	/* Initialize SPI2_MOSI_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_MOSI_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

// ********* INTERRUPTS*************
/*// (2) Configure NVIC for SPI1 transfer complete/error interrupts *********
  // Set priority for SPI1_IRQn
  NVIC_SetPriority(SPI1_IRQn, 0);
  // Enable SPI1_IRQn
  NVIC_EnableIRQ(SPI1_IRQn);*/
// ********* INTERRUPTS ***********

  // (3) Configure SPI1 functional parameters *******************************

  // Enable the peripheral clock of GPIOB
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SPI1);

 //  Configure SPI1 communication
  LL_SPI_SetBaudRatePrescaler(SPI1, LL_SPI_BAUDRATEPRESCALER_DIV256);
  LL_SPI_SetTransferDirection(SPI1,LL_SPI_FULL_DUPLEX);
  LL_SPI_SetClockPhase(SPI1, LL_SPI_PHASE_2EDGE);
  LL_SPI_SetClockPolarity(SPI1, LL_SPI_POLARITY_HIGH);
 //  Reset value is LL_SPI_MSB_FIRST
  //LL_SPI_SetTransferBitOrder(SPI1, LL_SPI_MSB_FIRST);
  LL_SPI_SetDataWidth(SPI1, LL_SPI_DATAWIDTH_8BIT);
  LL_SPI_SetNSSMode(SPI1, LL_SPI_NSS_SOFT);
  LL_SPI_SetRxFIFOThreshold(SPI1, LL_SPI_RX_FIFO_TH_QUARTER);


  // Set the nucleo board as the master in SPI comm
  LL_SPI_SetMode(SPI1, LL_SPI_MODE_MASTER);

 //  Enable SPI2
  LL_SPI_Enable(SPI2);
}
