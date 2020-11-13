#include "main.h"

void Configure_SPI(void)
{
	/* Enable the AHB clock of the GPIO Port that the SPI peripheral is connected to */
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
/*// (2) Configure NVIC for SPI2 transfer complete/error interrupts *********
  // Set priority for SPI2_IRQn
  NVIC_SetPriority(SPI2_IRQn, 0);
  // Enable SPI2_IRQn
  NVIC_EnableIRQ(SPI2_IRQn);*/
// ********* INTERRUPTS ***********

  /* Enable the APB clock for the SPI2 peripheral*/
  SPIx_CLK_ENABLE();

  /* Configuration information for the SPI initialization structure */
  spi_initstruct.TransferDirection = LL_SPI_FULL_DUPLEX;
  spi_initstruct.Mode              = LL_SPI_MODE_MASTER;
  spi_initstruct.DataWidth         = LL_SPI_DATAWIDTH_8BIT;
  spi_initstruct.ClockPolarity     = LL_SPI_POLARITY_HIGH;
  spi_initstruct.ClockPhase        = LL_SPI_PHASE_2EDGE;
  spi_initstruct.NSS               = LL_SPI_NSS_SOFT;
  spi_initstruct.BaudRate          = LL_SPI_BAUDRATEPRESCALER_DIV256;
  spi_initstruct.BitOrder          = LL_SPI_MSB_FIRST;
  spi_initstruct.CRCCalculation    = LL_SPI_CRCCALCULATION_DISABLE;
  spi_initstruct.CRCPoly           = 7U;

  // Set threshold of RXFIFO that triggers an RXNE event
  LL_SPI_SetRxFIFOThreshold(SPI2, LL_SPI_RX_FIFO_TH_QUARTER);

  /* Initialize SPI2 according to parameters defined in initialization structure. */
  if (LL_SPI_Init(SPIx_INSTANCE, &spi_initstruct) != SUCCESS)
  {
    /* Initialization Error */
    while (1)
    {
    }
  }

 //  Enable SPI2
  LL_SPI_Enable(SPI2);
}


/*void testSPIDevice(void)
{



}*/

