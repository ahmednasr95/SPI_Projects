/*
 * DIO_Private.h
 *
 * Created: 8/31/2023 7:14:07 PM
 *  Author: Ahmed ElSayed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*register definition*/
#define PORTA_DDR			(*(volatile UINT8_t*)0x3A)
#define PORTB_DDR			(*(volatile UINT8_t*)0x37)
#define PORTC_DDR			(*(volatile UINT8_t*)0x34)
#define PORTD_DDR			(*(volatile UINT8_t*)0x31)

#define PORTA_DATA			(*(volatile UINT8_t*)0x3B)
#define PORTB_DATA			(*(volatile UINT8_t*)0x38)
#define PORTC_DATA			(*(volatile UINT8_t*)0x35)
#define PORTD_DATA			(*(volatile UINT8_t*)0x32)

#define PORTA_PIN			(*(volatile UINT8_t*)0x39)
#define PORTB_PIN			(*(volatile UINT8_t*)0x36)
#define PORTC_PIN			(*(volatile UINT8_t*)0x33)
#define PORTD_PIN			(*(volatile UINT8_t*)0x30)
#endif /* DIO_PRIVATE_H_ */