/*
 * SPI_Program.c
 *
 * Created: 9/1/2023 8:55:57 AM
 *  Author: Ahmed ElSayed
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

static void (*SPI_CallBack)(void);

void SPI_Master_Init(){
	volatile UINT8_t SPCR_setting = 0;
	volatile UINT8_t SPSR_setting = 0;
	
	#if SPI_MODE == SPI_EN
	
	SET_BIT(SPCR_setting, SPCR_SPE);
	
	/*interrupt control*/
	#if SPI_INT_MODE == SPI_INT_EN
	
	SET_BIT(SPCR_setting, SPCR_SPIE);
	GIE_Enable();
	
	#elif SPI_INT_MODE == SPI_INT_DS
	
	CLEAR_BIT(SPCR_setting, SPCR_SPIE);
	
	#endif /*SPI_INT_MODE*/
	
	/*clock parity*/
	#if SPI_CLK_PARITY == SPI_LEADING_EDGE_RISING
	
	CLEAR_BIT(SPCR_setting, SPCR_CPOL);
	
	#elif SPI_CLK_PARITY == SPI_LEADING_EDGE_FALLING
	
	SET_BIT(SPCR_setting, SPCR_CPOL);
	
	#endif /*SPI_CLK_PARITY*/
	
	/*clock phase*/
	#if SPI_CLK_PHASE == SPI_LEADING_EDGE_SAMPLE
	
	CLEAR_BIT(SPCR_setting, SPCR_CPHA);
	
	#elif SPI_CLK_PHASE == SPI_LEADING_EDGE_SETUP
	
	SET_BIT(SPCR_setting, SPCR_CPHA);
	
	#endif /*SPI_CLK_PHASE*/
		
	/*ddr mode control*/
	#if SPI_DDR_MODE == SPI_DDR_DS
	
	CLEAR_BIT(SPSR_setting, SPSR_SPI2X);

	#if SPI_PRESCALE == SPI_PRESCALE_4
	
	CLEAR_BIT(SPCR_setting, SPCR_SPR0);
	CLEAR_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_16
	
	SET_BIT(SPCR_setting, SPCR_SPR0);
	CLEAR_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_64
	
	CLEAR_BIT(SPCR_setting, SPCR_SPR0);
	SET_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_128
	
	SET_BIT(SPCR_setting, SPCR_SPR0);
	SET_BIT(SPCR_setting, SPCR_SPR1);
	
	#endif /*SPI_PRESCALE*/
	
	#elif SPI_DDR_MODE == SPI_DDR_EN
	
	SET_BIT(SPSR_setting, SPSR_SPI2X);
	
	#if SPI_PRESCALE == SPI_PRESCALE_2
	
	CLEAR_BIT(SPCR_setting, SPCR_SPR0);
	CLEAR_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_8
	
	SET_BIT(SPCR_setting, SPCR_SPR0);
	CLEAR_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_32
	
	CLEAR_BIT(SPCR_setting, SPCR_SPR0);
	SET_BIT(SPCR_setting, SPCR_SPR1);
	
	#elif SPI_PRESCALE == SPI_PRESCALE_64
	
	SET_BIT(SPCR_setting, SPCR_SPR0);
	SET_BIT(SPCR_setting, SPCR_SPR1);
	
	#endif /*SPI_PRESCALE*/
	
	#endif /*SPI_DDR_MODE*/
	
	/*data order control*/
	#if SPI_DATA_ORDER == SPI_DORD_LSB
	
	SET_BIT(SPCR_setting, SPCR_DORD);
	
	#elif SPI_DATA_ORDER == SPI_DORD_MSB
	
	CLEAR_BIT(SPCR_setting, SPCR_DORD);
	
	#endif /*SPI_DATA_ORDER*/
	
	/*master mode control*/
	#if SPI_MSTR_MODE == SPI_MSTR
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT); /*SS*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);/*MOSI*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT); /*MISO*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);/*SCK*/
	
	SET_BIT(SPCR_setting, SPCR_MSTR);
	DIO_SetPinVal(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
	
	#elif SPI_MSTR_MODE == SPI_SLAVE
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT); /*SS*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);/*MOSI*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT); /*MISO*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);/*SCK*/
	
	CLEAR_BIT(SPCR_setting, SPCR_MSTR);
	
	#endif /*SPI_MSTR_MODE*/	

	#elif SPI_MODE == SPI_DS
	
	CLEAR_BIT(SPCR_setting, SPCR_SPE);
	
	#endif /*SPI_MODE*/
	
	/*write to registers*/
	SPCR = SPCR_setting;
	SPSR = SPSR_setting;
}

/*void SPI_Slave_Init(){
	
}*/

UINT8_t SPI_RecieveCharacter(){	
	while(!READ_BIT(SPSR, SPSR_SPIF));
	return SPDR;
}

void SPI_SendCharacter(UINT8_t chr){
	SPDR = chr;
	while(!READ_BIT(SPSR, SPSR_SPIF));
}

void SPI_SetCallback(void (*fPtr)(void)){
	
}

void __vector_12(void) __attribute((signal));
void __vector_12(){
	
}