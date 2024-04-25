/*
 * ssd_prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: hp
 */
#include "../../LIB/STD_TYPES1.h"
#include "Private.h"
#include "ssd_init.h"
#include "../../MCAL/dio/dio_init.h"
void HSSD_Init(u8 A_u8PortNo)
{
	MDIO_vSetPortDir(A_u8PortNo,0xff);

}
void HSSD_vSSDPrintNo(u8 A_u8PortNo,u8 A_u8Num)
{
	u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	MDIO_vSetPortVal(A_u8PortNo, arr[A_u8Num]);


}

