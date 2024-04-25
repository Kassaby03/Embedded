/*
 * LCD_config.h
 *
 *  Created on: Mar 11, 2023
 *      Author: hp
 */

#ifndef COTS_HALL_LCD_LCD_CONFIG_H_
#define COTS_HALL_LCD_LCD_CONFIG_H_


#define RS						DIO_PIN0
#define RW						DIO_PIN1
#define E 						DIO_PIN2

#define FUNCTION_SET			0b00111100
#define DIS_ON_OFF				0b00001111
#define CLR_LCD					0b00000001
#define INTRY_MODE				0b00000110


#define LCD_LINE_0 0
#define LCD_LINE_1 1

#define LCD_ROW_1 127
#define LCD_ROW_2 191



#endif /* COTS_HALL_LCD_LCD_CONFIG_H_ */
