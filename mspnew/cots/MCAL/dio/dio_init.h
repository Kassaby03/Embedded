/*
 * dio_init.h
 *
 *  Created on: Feb 6, 2023
 *      Author: osama
 */



#ifndef COTS_MCAL_DIO_INIT_H_
#define COTS_MCAL_DIO_INIT_H_

//PORTS


#define DIO_PORTA         0
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3



//PINS

#define DIO_PIN0          0
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

//INPUT,OUTPUT,HIGH,LOW

#define DIO_OUTPUT        1
#define DIO_INPUT         0
#define DIO_HIGH          1
#define DIO_LOW           0
//void MDIO_vSetBitDir(u8 A_u8PortNo,u8 A_u8BitNo,u8 A_u8BitDir    );

void MDIO_vSetBitDir(u8 A_u8PortNo,u8 A_u8BitNo,u8 A_u8BitDir    );
void MDIO_vSetBitVal(u8 A_u8PortNo,u8 A_u8BitNo,u8 A_u8BitVal );
u8 MDIO_u8vGetBitVal(u8 A_u8PortNo , u8 A_u8BitNo                );
void MDIO_vTogBit(u8 A_u8PortNo , u8 A_u8BitNo                   );
void MDIO_vSetPortDir(u8 A_u8PortNo ,  u8 A_u8PortDir            );
void MDIO_vSetPortVal(u8 A_u8PortNo , u8 A_u8PortVal             );
#endif /* COTS_MCAL_DIO_INIT_H_ */
