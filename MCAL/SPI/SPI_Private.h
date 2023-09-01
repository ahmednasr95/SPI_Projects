/*
 * SPI_Private.h
 *
 * Created: 9/1/2023 8:55:14 AM
 *  Author: Ahmed ElSayed
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR		(*(volatile UINT8_t *) 0x2D)
#define SPSR		(*(volatile UINT8_t *) 0x2E)
#define SPDR		(*(volatile UINT8_t *) 0x2F)

/*SPCR Pins*/
#define SPCR_SPR0	0
#define SPCR_SPR1	1
#define SPCR_CPHA	2
#define SPCR_CPOL	3
#define SPCR_MSTR	4
#define SPCR_DORD	5
#define SPCR_SPE	6
#define SPCR_SPIE	7

/*SPSR Pins*/
#define SPSR_SPI2X	0
#define SPCR_WCOL	6
#define SPSR_SPIF	7

/*SPI interrupt control*/
#define SPI_INT_DS		0
#define SPI_INT_EN		1

/*SPI control*/
#define SPI_DS		0
#define SPI_EN		1

/*data order control*/
#define SPI_DORD_MSB		0
#define SPI_DORD_LSB		1

/*master select control*/
#define SPI_MSTR		0
#define SPI_SLAVE		1

/*Clock Parity*/
#define SPI_LEADING_EDGE_RISING		0
#define SPI_LEADING_EDGE_FALLING	1

/*Clock Phase*/
#define SPI_LEADING_EDGE_SAMPLE		0
#define SPI_LEADING_EDGE_SETUP		1

/*Double data rate*/
#define SPI_DDR_DS		0
#define SPI_DDR_EN		1

/*prescalers*/
#define SPI_PRESCALE_2		4
#define SPI_PRESCALE_4		0
#define SPI_PRESCALE_8		5
#define SPI_PRESCALE_16		1
#define SPI_PRESCALE_32		6
#define SPI_PRESCALE_64		7 
#define SPI_PRESCALE_128	3

#endif /* SPI_PRIVATE_H_ */