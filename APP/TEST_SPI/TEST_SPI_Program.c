/*
* TEST_UART_Program.c
*
* Created: 8/31/2023 9:29:19 PM
*  Author: Ahmed ElSayed
*/
#include "TEST_SPI_Interface.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "DIO_Private.h"

void Init(){
	SPI_Master_Init();
	DIO_SetPinDir(DIO_PORTA, DIO_PIN7, DIO_PIN_OUTPUT);
}

void Test_SPI(){
	UINT8_t x = 0;
	SPI_SendCharacter('A');
	x = SPI_RecieveCharacter();
	
	if(x == 'A'){
		DIO_TogglePin(DIO_PORTA, DIO_PIN7);
		_delay_ms(500);
	}
}