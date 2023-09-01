/*
 * SPI_Interface.h
 *
 * Created: 9/1/2023 8:54:58 AM
 *  Author: Ahmed ElSayed
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"

void SPI_Master_Init(void);

void SPI_Slave_Init(void);

UINT8_t SPI_RecieveCharacter();
void SPI_SendCharacter(UINT8_t chr);


#endif /* SPI_INTERFACE_H_ */