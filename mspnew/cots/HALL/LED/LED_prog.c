/*
 * LED_prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: hp
 */
#include"../../LIB/STD_TYPES1.h"
#include"../../MCAL/dio/dio_init.h"
#include"LED_init.h"
void HLED_vLEDInit(u8 A_u8PortNo,u8 A_u8BitNo)
{

	MDIO_vSetBitDir(A_u8PortNo,A_u8BitNo,DIO_OUTPUT);


}
void HLED_vLEDon(u8 A_u8PortNo, u8 A_u8BitNo)
{


	MDIO_vSetBitVal(A_u8PortNo,A_u8BitNo,DIO_HIGH);

}
void HLED_vLEDoff(u8 A_u8PortNo,u8 A_u8BitNo)
{


	MDIO_vSetBitVal(A_u8PortNo,A_u8BitNo,DIO_LOW);

}

