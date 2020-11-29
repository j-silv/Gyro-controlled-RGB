#ifndef INC_ADXL362_ACC_H_
#define INC_ADXL362_ACC_H_

#define DEVID_AD_VALUE 0xAD // Analog Device ID for the ADXL362

/* SPI COMMANDS
 * First byte of SPI comm from master specifies what sort of operation */
#define SPI_WRITE_REG 0x0AU
#define SPI_READ_REG 0x0BU
#define SPI_READ_FIFO 0x0DU

/* REGISTERS */
#define DEVID_AD 0x00U
#define DEVID_MST 0x01U
#define THRESH_ACT_L 0x20U
#define THRESH_ACT_H 0x21U
#define TIME_ACT 0x22U
#define THRESH_INACT_L 0x23U
#define THRESH_INACT_H 0x24U
#define TIME_INACT_L 0x25U
#define TIME_INACT_H 0x26U
#define ACT_INACT_CTL 0x27U
#define FIFO_CONTROL 0x28U
#define FIFO_SAMPLES 0x29U
#define INTMAP1 0x2AU
#define INTMAP2 0x2BU
#define FILTER_CTL 0x2CU
#define POWER_CTL 0x2DU

/* FUNCTIONS */
void configSlave(void);
uint8_t checkSlaveID(void);



#endif /* INC_ADXL362_ACC_H_ */
