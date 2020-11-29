#include "main.h"

/*
Device Configuration steps for the ADXL362 accelerometer
1. Set activity and inactivity thresholds and timers.
	a. Write to Register 0x20 to Register 0x26.
	b. To minimize false positive motion triggers, set the TIME_ACT register greater than 1.
2. Configure activity and inactivity functions.
	a. Write to Register 0x27.
3. Configure FIFO.
	a. Write to Register 0x28 and Register 0x29.
4. Map interrupts.
	a. Write to Register 0x2A and Register 0x2B.
5. Configure general device settings.
	a. Write to Register 0x2C.
6. Turn measurement on.
	a. Write to Register 0x2D.
*/


/* DEBUGGING NOTES 14/11/2020
 * When performing read registers, 0xFF is sent back on SPI line
 * Register DEVID_AD and DEVID_MST gives 0xFF sent back
 *
 * 0xFF is definitely coming from the slave once we perform the read...
 * Upon further reading... it seems that I will have to send "dummy" data
 * on the MOSI line (zeros for example) to actually start the clock signal
 * I can do this after sending the 2 commands and then I can go ahead and poll the 
 * RXNE pin (receive data)
 * 
 */

void configSlave(void)
{
	// Configure the slave to measurement mode
	LL_GPIO_ResetOutputPin(SPIx_NSS_GPIO_PORT,SPIx_NSS_PIN);

	SPIsendByte(SPI_WRITE_REG);
	SPIsendByte(POWER_CTL);
	SPIsendByte(1U << 1);

	LL_GPIO_SetOutputPin(SPIx_NSS_GPIO_PORT,SPIx_NSS_PIN);
}

// To check if SPI comm is working, master asks for the ADXL362 Analog Device's ID number
uint8_t checkSlaveID(void)
{
	volatile uint8_t byteReceived = 0xBBU; // clearly identifiable initial value
	
	// Set chip select line LOW
	LL_GPIO_ResetOutputPin(SPIx_NSS_GPIO_PORT,SPIx_NSS_PIN);

	// Perform a read command at the DEVID_AD register
	SPIsendByte(SPI_READ_REG);
	SPIsendByte(DEVID_AD);
	
	// Store the received byte from the accelerometer
	byteReceived = SPIreceiveByte();
	
	// Set chip select line HIGH
	LL_GPIO_SetOutputPin(SPIx_NSS_GPIO_PORT,SPIx_NSS_PIN);
	
	return(byteReceived);
}

