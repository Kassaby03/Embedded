/*
 * dio_pro.c
 *
 *  Created on: Feb 6, 2023
 *      Author: osama
 */

//task 3333333333333333333
#include "LIB/BIT.H"
#include "LIB/STD_TYPES1.h"
#include <avr/io.h>
#include "dio_init.h"
void MDIO_vSetBitDir(u8 A_u8PortNo,u8 A_u8BitNo,u8 A_u8BitDir    )
{   if((A_u8PortNo<=DIO_PORTD)&&(A_u8BitNo<=DIO_PIN7)&&(A_u8BitDir<=DIO_OUTPUT)){
	switch(A_u8PortNo){
	case DIO_PORTA:
	WRT_BIT(DDRA,A_u8BitNo,A_u8BitDir);
	break;
	case DIO_PORTB:
	WRT_BIT(DDRB,A_u8BitNo,A_u8BitDir);
	break;
	case DIO_PORTC:
	WRT_BIT(DDRC,A_u8BitNo,A_u8BitDir);
	break;
	case DIO_PORTD:
	WRT_BIT(DDRD,A_u8BitNo,A_u8BitDir);
	break;
	}
}
}

void MDIO_vSetBitVal(u8 A_u8PortNo,u8 A_u8BitNo,u8 A_u8BitVal )
{   if((A_u8PortNo<=DIO_PORTD)&&(A_u8BitNo<=DIO_PIN7)&&(A_u8BitVal<=DIO_HIGH)){
	switch(A_u8PortNo){
		case DIO_PORTA:
		WRT_BIT(PORTA,A_u8BitNo,A_u8BitVal);
		break;
		case DIO_PORTB:
		WRT_BIT(PORTB,A_u8BitNo,A_u8BitVal);
		break;
		case DIO_PORTC:
		WRT_BIT(PORTC,A_u8BitNo,A_u8BitVal);
		break;
		case DIO_PORTD:
		WRT_BIT(PORTD,A_u8BitNo,A_u8BitVal);
		break;

	}}
}



u8 MDIO_u8vGetBitVal(u8 A_u8PortNo , u8 A_u8BitNo                ){
	u8 L_u8BitVal;
	 if((A_u8PortNo<=DIO_PORTD)&&(A_u8BitNo<=DIO_PIN7)){
		switch(A_u8PortNo){
		case DIO_PORTA:
		L_u8BitVal=GET_BIT(PINA,A_u8BitNo);
		break;
		case DIO_PORTB:
		L_u8BitVal=GET_BIT(PINB,A_u8BitNo);
		break;
		case DIO_PORTC:
		L_u8BitVal=GET_BIT(PINC,A_u8BitNo);
		break;
		case DIO_PORTD:
		L_u8BitVal=GET_BIT(PIND,A_u8BitNo);
		break;
		}
	}
return L_u8BitVal;
}

void MDIO_vTogBit(u8 A_u8PortNo , u8 A_u8BitNo                   )
{

	 if((A_u8PortNo<=DIO_PORTD)&&(A_u8BitNo<=DIO_PIN7)){
			switch(A_u8PortNo){
			case DIO_PORTA:
			TOG_BIT(PORTA,A_u8BitNo);
			break;
			case DIO_PORTB:
			TOG_BIT(PORTB,A_u8BitNo);
			break;
			case DIO_PORTC:
			TOG_BIT(PORTC,A_u8BitNo);
			break;
			case DIO_PORTD:
			TOG_BIT(PORTD,A_u8BitNo);
			break;
			}
}
}
void MDIO_vSetPortDir(u8 A_u8PortNo ,  u8 A_u8PortDir            )
{
	 if((A_u8PortNo<=DIO_PORTD)){
				switch(A_u8PortNo){
				case DIO_PORTA:
				DDRA= A_u8PortDir ;
				break;
				case DIO_PORTB:
				DDRB= A_u8PortDir ;
				break;
				case DIO_PORTC:
				DDRC=A_u8PortDir ;
				break;
				case DIO_PORTD:
				DDRD=A_u8PortDir ;
				break;
				}
}
}
void MDIO_vSetPortVal(u8 A_u8PortNo , u8 A_u8PortVal             )
{
	 if((A_u8PortNo<=DIO_PORTD)){
					switch(A_u8PortNo){
					case DIO_PORTA:
					PORTA= A_u8PortVal ;
					break;
					case DIO_PORTB:
					PORTB= A_u8PortVal ;
					break;
					case DIO_PORTC:
					PORTC=A_u8PortVal ;
					break;
					case DIO_PORTD:
					PORTD=A_u8PortVal ;
					break;
					}
	 }

}
