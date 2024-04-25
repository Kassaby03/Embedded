/*
 * main.c
 *
 *  Created on: Feb 7, 2023
 *      Author: hp
 */
#include "../LIB/BIT.H"
#include "../LIB/STD_TYPES1.h"
#include "../MCAL/dio/dio_init.h"
#include "../MCAL/dio/dio_reg.h"
#include<util\delay.h>
#include"../HALL/KDP/KDP_init.h"

void main(void){
	HSSD_Init( DIO_PORTA ,DIO_PIN0 );
	while(1){
	HLED_vLEDon(DIO_PORTA ,DIO_PIN0);
     _delay_ms(1000);
     HLED_vLEDoff(DIO_PORTA ,DIO_PIN0);
          _delay_ms(1000);
	}




}





