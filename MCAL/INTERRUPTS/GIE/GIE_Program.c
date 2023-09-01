/*
 * GIE_Program.c
 *
 * Created: 8/31/2023 7:25:01 PM
 *  Author: Ahmed ElSayed
 */ 
#include "GIE_Interface.h"
#include "GIE_Private.h"


void GIE_Enable(){
	SET_BIT(SREG, SREG_I);
}

void GIE_Disable(){
	CLEAR_BIT(SREG, SREG_I);
}