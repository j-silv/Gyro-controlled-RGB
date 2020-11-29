#include "main.h"

void Configure_SPI(void)
{
	/* Enable the AHB clock of the GPIO Port that the SPI peripheral is connected to */
	SPIx_GPIO_CLK_ENABLE();

	// Configure SCK Pin connected to pin 31 of CN10 connector (D3 Arduino connector)
	gpio_spi_initstruct.Pin        = SPIx_SCK_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI1 peripheral

	/* Initialize SPI1_SCK_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_SCK_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure MISO Pin connected to pin 27 of CN10 connector (D5 Arduino connector)
	gpio_spi_initstruct.Pin        = SPIx_MISO_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL; // shouldn't this be input?????
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI1 peripheral

	/* Initialize SPI1_MISO_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_MISO_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure MOSI Pin connected to pin 29 of CN10 connector (D4 Arduino connector)
	gpio_spi_initstruct.Pin        = SPIx_MOSI_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;
	gpio_spi_initstruct.Alternate  = LL_GPIO_AF_0; // Mapped to SPI1 peripheral

	/* Initialize SPI1_MOSI_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_MOSI_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}

	// Configure NSS Pin connected to pin 25 of CN10 connector (D6 Arduino connector)
	gpio_spi_initstruct.Pin        = SPIx_NSS_PIN;
	gpio_spi_initstruct.Mode       = LL_GPIO_MODE_OUTPUT;
	gpio_spi_initstruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	gpio_spi_initstruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio_spi_initstruct.Pull       = LL_GPIO_PULL_DOWN;

	/* Initialize SPI1_NSS_GPIO port according to parameters defined in initialization structure. */
	if (LL_GPIO_Init(SPIx_NSS_GPIO_PORT, &gpio_spi_initstruct) != SUCCESS)
	{
		/* Initialization Error */
		while (1)
		{
		}
	}



// ********* INTERRUPTS*************
/*// (2) Configure NVIC for SPI1 transfer complete/error interrupts *********
  // Set priority for SPI2_IRQn
  NVIC_SetPriority(SPI2_IRQn, 0);
  // Enable SPI2_IRQn
  NVIC_EnableIRQ(SPI2_IRQn);*/
// ********* INTERRUPTS ***********

  /* Enable the APB clock for the SPI1 peripheral*/
  SPIx_CLK_ENABLE();

  /* Configuration information for the SPI initialization structure */
  spi_initstruct.TransferDirection = LL_SPI_FULL_DUPLEX;
  spi_initstruct.Mode              = LL_SPI_MODE_MASTER;
  spi_initstruct.DataWidth         = LL_SPI_DATAWIDTH_8BIT;
  spi_initstruct.ClockPolarity     = LL_SPI_POLARITY_LOW; // ADXL362 (slave) expects CPOL = 0
  spi_initstruct.ClockPhase        = LL_SPI_PHASE_1EDGE;  // ADXL362 (slave) expects CPHA = 0
  // Dedicated GPIO pin will be used as chip select line
  spi_initstruct.NSS               = LL_SPI_NSS_SOFT;
  /* as per ADXL362 (slave) datasheet, SPI comm should be between 1-8 MHz
   * prescaler values gives a 1.5 MHz SPI comm clock, which is within specification */
  spi_initstruct.BaudRate          = LL_SPI_BAUDRATEPRESCALER_DIV32;
  spi_initstruct.BitOrder          = LL_SPI_MSB_FIRST;
  spi_initstruct.CRCCalculation    = LL_SPI_CRCCALCULATION_DISABLE;
  spi_initstruct.CRCPoly           = 7U;

  // Set threshold of RXFIFO that triggers an RXNE event
  LL_SPI_SetRxFIFOThreshold(SPIx_INSTANCE, LL_SPI_RX_FIFO_TH_QUARTER);

  /* Initialize SPI1 according to parameters defined in initialization structure. */
  if (LL_SPI_Init(SPIx_INSTANCE, &spi_initstruct) != SUCCESS)
  {
    /* Initialization Error */
    while (1)
    {
    }
  }

 //  Enable SPI1
  LL_SPI_Enable(SPIx_INSTANCE);
}

void SPIsendByte(uint8_t byte)
{
	/* Check and wait until TXE flag value in ISR register goes high */
	while (LL_SPI_IsActiveFlag_TXE(SPIx_INSTANCE) == 0UL)
	{
	}

	// Send data passed in to funtion
	LL_SPI_TransmitData8(SPIx_INSTANCE, byte);
}

uint8_t SPIreceiveByte(void)
{

	// Send dummy byte so that the serial clock is sent when the master is reading data in
	SPIsendByte(0x00U);

	/* Check and wait until RXNE flag value in ISR register goes high */
	while (LL_SPI_IsActiveFlag_RXNE(SPIx_INSTANCE) == 0UL)
	{
	}
	// Send data passed in to funtion
	return(LL_SPI_ReceiveData8(SPIx_INSTANCE));
}


