#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

/*constants definition*/
#define MAX_REG_VAL 0xFF

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF

#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0x00

void DIO_SetPortDir(UINT8_t Port, UINT8_t Dir);
void DIO_SetPinDir(UINT8_t Port, UINT8_t Pin, UINT8_t Dir);

void DIO_SetPortVal(UINT8_t Port, UINT8_t Val);
void DIO_SetPinVal(UINT8_t Port, UINT8_t Pin, UINT8_t Val);

void DIO_ReadPort(UINT8_t Port, UINT8_t* Val);
void DIO_ReadPin(UINT8_t Port, UINT8_t Pin, UINT8_t* Val);

void DIO_TogglePin(UINT8_t Port,  UINT8_t Pin);
#endif	/* DIO_INTERFACE_H_ */


