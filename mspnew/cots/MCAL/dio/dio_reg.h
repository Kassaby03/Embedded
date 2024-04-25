/*
 * dio_reg.h
 *
 *  Created on: Feb 6, 2023
 *      Author: osama
 */

#ifndef COTS_MCAL_DIO_REG_H_
#define COTS_MCAL_DIO_REG_H_
#define PORTA *((volatile u8*)(0x3B))
#define PORTB *((volatile u8*)((0x38))
#define PINA *((volatile u8*)(0x39))
#define DDRA *((volatile u8*)(0x3A))
#define DDRB *((volatile u8*)(0x37))
#define PINB *((volatile u8*)(0x36))
#define PORTC *((volatile u8*)(0x35))
#define DDRC *((volatile u8*)(0x34))
#define PINC *((volatile u8*)(0x33))
#define PORTD *((volatile u8*)(0x32))
#define DDRD *((volatile u8*)(0x31))
#define PIND *((volatile u8*)(0x30))





#endif /* COTS_MCAL_DIO_REG_H_ */
