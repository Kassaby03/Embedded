/*
 * DIP_prog.c
 *
 *  Created on: Feb 9, 2023
 *      Author: hp
 */
#include"../../LIB/STD_TYPES1.h"
#include"../../MCAL/dio/dio_init.h"
#include"DIP_init.h"
void  HDIP_vDIPInit(u8 A_u8PortNo, u8 A_u8PinNo)
{
	MDIO_vSetBitDir( A_u8PortNo,  A_u8PinNo,DIO_INPUT);



}
u8 HDIP_u8GetDIPVal(u8 A_u8PortNo, u8 A_u8PinNo)
{

return MDIO_u8vGetBitVal( A_u8PortNo,  A_u8PinNo);

}

