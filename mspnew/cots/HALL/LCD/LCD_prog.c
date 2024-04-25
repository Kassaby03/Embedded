/*
 * LCD_prog.c
 *
 *  Created on: Feb 9, 2023
 *      Author: hp
 */
#include"../../LIB/STD_TYPES1.h"
#include "../../MCAL/dio/dio_init.h"
#include"LCD_Init.h"
#include"util/delay.h"
#include"LCD_config.h"

#define LCD_DATAPORT     DIO_PORTD
#define LCD_ControlPORT   DIO_PORTB


#define RS  DIO_PIN0
#define RW  DIO_PIN1
#define E   DIO_PIN2
void HLCD_vSendCommand(u8 L_u8Data)
{
	    MDIO_vSetBitVal(LCD_ControlPORT,RS,DIO_LOW);
		MDIO_vSetBitVal(LCD_ControlPORT,RW,DIO_LOW);

		MDIO_vSetPortVal(LCD_DATAPORT,L_u8Data);

		MDIO_vSetBitVal(LCD_ControlPORT,E,DIO_HIGH);
		_delay_ms(1);
		MDIO_vSetBitVal(LCD_ControlPORT,E,DIO_LOW);

		_delay_ms(1);


}
void HLCD_vSendData(u8 L_u8Data)
{


	MDIO_vSetBitVal(LCD_ControlPORT,RS,DIO_HIGH);
		MDIO_vSetBitVal(LCD_ControlPORT,RW,DIO_LOW);
		MDIO_vSetPortVal(LCD_DATAPORT,L_u8Data);
		MDIO_vSetBitVal(LCD_ControlPORT,E,DIO_HIGH);
		_delay_ms(1);
		MDIO_vSetBitVal(LCD_ControlPORT,E,DIO_LOW);
		_delay_ms(1);

}
  void HLCD_vLCDInit(void)
{
	MDIO_vSetPortDir(LCD_DATAPORT,0xff);
	MDIO_vSetBitDir(LCD_ControlPORT,RS,DIO_OUTPUT);
	MDIO_vSetBitDir(LCD_ControlPORT,RW,DIO_OUTPUT);
	MDIO_vSetBitDir(LCD_ControlPORT,E,DIO_OUTPUT);

	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_us(50);
	HLCD_vSendCommand(0b00001111);
	_delay_us(50);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(2);
	HLCD_vSendCommand(0b00000110);


}
void HLCD_vSendStr(u8*A_u8Ptr)
{
	u8 L_u8var;
	for(L_u8var=0;A_u8Ptr[L_u8var]!='\0';L_u8var++)
	{
		HLCD_vSendData(A_u8Ptr[L_u8var]);

	}


}
void HLCD_vGoTo(u8 A_u8RowIndex,u8 A_u8ColIndex)
{
	if((A_u8RowIndex<2)&&(A_u8ColIndex<16))
	{
		if(A_u8RowIndex==LCD_LINE_0)
		{
			HLCD_vSendCommand(LCD_ROW_1+A_u8ColIndex);
		}
		else if(A_u8RowIndex==LCD_LINE_1)
		{
			HLCD_vSendCommand(LCD_ROW_2+A_u8ColIndex);
		}
	}

}
void HLCD_vSendNum(s32 A_s32num)
{
	if(A_s32num<0)
	{
		HLCD_vSendData('-');
		A_s32num*=-1;
	}
	if(A_s32num!=0)
	{
		HLCD_vSendNum(A_s32num/10);
		HLCD_vSendData('0'+(A_s32num)%10);

	}
}
void HLCD_vClear(void)
{
	HLCD_vSendCommand(CLR_LCD);
}
void HLCD_vSaveCustomChar(u8 A_u8Index,u8 A_u8CustomChar[])
{
	u8 L_Counter;
	HLCD_vSendCommand(CGRAM_ADDRESS+A_u8Index*8);
	for(L_Counter=0;L_Counter<8;L_Counter++){
		HLCD_vSendData(A_u8CustomChar[L_Counter]);
		}

	HLCD_vSendCommand(DDRAM_ADDRESS);

}
void HLCD_vDisplayCustomChar(u8 A_u8Cgram_index)
{
	if(A_u8Cgram_index<8){
		HLCD_vSendData(A_u8Cgram_index);

	}




}
