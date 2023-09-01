#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_SetPortDir(UINT8_t Port, UINT8_t Dir){
	switch(Port){
		case DIO_PORTA:
			PORTA_DDR = Dir;
			break;
		case DIO_PORTB:
			PORTB_DDR = Dir;
			break;
		case DIO_PORTC:
			PORTC_DDR = Dir;
			break;
		case DIO_PORTD:
			PORTD_DDR = Dir;
			break;
		/*handle errors using default*/
	}
}

void DIO_SetPinDir(UINT8_t Port, UINT8_t Pin, UINT8_t Dir){
	switch(Dir){
		case DIO_PIN_OUTPUT:
			switch(Port){
				case DIO_PORTA:
					SET_BIT(PORTA_DDR, Pin);
					break;
				case DIO_PORTB:
					SET_BIT(PORTB_DDR, Pin);
					break;
				case DIO_PORTC:
					SET_BIT(PORTC_DDR, Pin);
					break;
				case DIO_PORTD:
					SET_BIT(PORTD_DDR, Pin);
					break;
				/*handle errors using default*/
			}
			break;
		case DIO_PIN_INPUT:
			switch(Port){
				case DIO_PORTA:
					CLEAR_BIT(PORTA_DDR, Pin);
					break;
				case DIO_PORTB:
					CLEAR_BIT(PORTB_DDR, Pin);
					break;
				case DIO_PORTC:
					CLEAR_BIT(PORTC_DDR, Pin);
					break;
				case DIO_PORTD:
					CLEAR_BIT(PORTD_DDR, Pin);
					break;
				/*handle errors using default*/
			}
			break;	
		/*handle errors using default*/		
	}
}

void DIO_SetPortVal(UINT8_t Port, UINT8_t Val){
	if(MAX_REG_VAL >= Val){
		switch(Port){
			case DIO_PORTA:
				PORTA_DATA = Val;
				break;
			case DIO_PORTB:
				PORTB_DATA = Val;
				break;
			case DIO_PORTC:
				PORTC_DATA = Val;
				break;
			case DIO_PORTD:
				PORTD_DATA = Val;
				break;
			/*handle errors using default*/
		}
	}else{
		/*handle errors*/
	}
}

void DIO_SetPinVal(UINT8_t Port, UINT8_t Pin, UINT8_t Val){
	switch(Val){
		case DIO_PIN_HIGH:
		switch(Port){
			case DIO_PORTA:
				SET_BIT(PORTA_DATA, Pin);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB_DATA, Pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC_DATA, Pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD_DATA, Pin);
				break;
			/*handle errors using default*/
		}
		break;
		case DIO_PIN_LOW:
			switch(Port){
				case DIO_PORTA:
					CLEAR_BIT(PORTA_DATA, Pin);
					break;
				case DIO_PORTB:
					CLEAR_BIT(PORTB_DATA, Pin);
					break;
				case DIO_PORTC:
					CLEAR_BIT(PORTC_DATA, Pin);
					break;
				case DIO_PORTD:
					CLEAR_BIT(PORTD_DATA, Pin);
					break;
				/*handle errors using default*/
			}
			break;
		/*handle errors using default*/
	}
}

void DIO_ReadPort(UINT8_t Port, UINT8_t* Val){
	switch(Port){
		case DIO_PORTA:
			*Val = PORTA_PIN;
			break;
		case DIO_PORTB:
			*Val = PORTB_PIN;
			break;
		case DIO_PORTC:
			*Val = PORTC_PIN;
			break;
		case DIO_PORTD:
			*Val = PORTD_PIN;
			break;
		/*handle errors using default*/
	}
}

void DIO_ReadPin(UINT8_t Port, UINT8_t Pin, UINT8_t* Val){
	switch(Port){
		case DIO_PORTA:
			*Val = READ_BIT(PORTA_PIN, Pin);
			break;
		case DIO_PORTB:
			*Val = READ_BIT(PORTB_PIN, Pin);
			break;
		case DIO_PORTC:
			*Val = READ_BIT(PORTC_PIN, Pin);
			break;
		case DIO_PORTD:
			*Val = READ_BIT(PORTD_PIN, Pin);
			break;
		/*handle errors using default*/
	}
}

void DIO_TogglePin(UINT8_t Port, UINT8_t Pin){
	switch(Port){
		case DIO_PORTA:
			TOGGLE_BIT(PORTA_DATA, Pin);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB_DATA, Pin);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC_DATA, Pin);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD_DATA, Pin);
			break;
		/*handle errors using default*/
	}
}