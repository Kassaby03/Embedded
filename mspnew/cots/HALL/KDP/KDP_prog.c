/*
 * KDP_prog.c

 *
 *  Created on: Feb 9, 2023
 *      Author: hp
 *
 */
#include"../../LIB/STD_TYPES1.h"
#include"../../MCAL/dio/dio_init.h"
#include "KDP_Init.h"
#include<util/delay.h>
#include"KPD.CONFIG.h"
void HKPD_vKDOInit(void)
{
	MDIO_vSetPortDir(KEYPAD_PORT,0xF0);
	MDIO_vSetPortVal(KEYPAD_PORT,0xFF);



}
u8 HKPD_GetPressedKey(void)
{
	u8 L_u8Row,L_u8Col,L_u8Val=255,L_u8flag=0;
		u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};
		for (L_u8Col=0;L_u8Col<4;L_u8Col++){
			MDIO_vSetBitVal(KEYPAD_PORT,L_u8Col+4,DIO_LOW);
			for (L_u8Row=0;L_u8Row<4;L_u8Row++){
				if (MDIO_u8vGetBitVal(KEYPAD_PORT,L_u8Row)==0){
					_delay_ms(20);
					if (MDIO_u8vGetBitVal(KEYPAD_PORT,L_u8Row)==0){
						L_u8Val=arr[L_u8Row][L_u8Col];
						while (MDIO_u8vGetBitVal(KEYPAD_PORT,L_u8Row)==0);
						L_u8flag=1;
						break;
					}

				}
			}
			MDIO_vSetBitVal(KEYPAD_PORT,L_u8Col+4,DIO_HIGH);
			if (L_u8flag==1)
				break;
		}
		return L_u8Val;

}

