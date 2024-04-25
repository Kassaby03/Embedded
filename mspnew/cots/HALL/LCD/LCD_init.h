/*
 * LCD_init.h
 *
 *  Created on: Feb 9, 2023
 *      Author: hp
 */

#ifndef COTS_HALL_LCD_LCD_INIT_H_
#define COTS_HALL_LCD_LCD_INIT_H_
void HLCD_vSendcommand(u8 L_u8Data);
void HLCD_vSendData(u8 L_u8Data);
void HLCD_vLCDInit(void);
void HLCD_vSendStr(u8*A_u8Ptr);
void HLCD_vSendNum(s32 A_s32num);
void HLCD_vClear(void);
void HLCD_vGoTo(u8 A_u8RowIndex,u8 A_u8ColIndex);
#define DDRAM_ADDRESS 0b10000000
#define CGRAM_ADDRESS 0b01000000

#endif /* COTS_HALL_LCD_LCD_INIT_H_ */
