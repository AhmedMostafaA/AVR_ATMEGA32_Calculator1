/*
 * Dio_CFG.c
 *
 * Created: 1/20/2020 7:12:44 PM
 *  Author: Costa
 */ 

#include <avr/io.h>
#include "Dio_CFG.h"

/*const Dio_Pin_State_t Pin_state[LASTPIN] ={OUTPUT,INFREE,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,INPULLUP,OUTPUT,OUTPUT,OUTPUT,INPULLUP,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,INPULLUP,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT};*/

const Dio_Pin_State_t Pin_state[LASTPIN] =
{
	//portA
	OUTPUT,		 // 0 N/C
	INFREE,		 // 1 ADC 1
	OUTPUT,		 // 2 Relay_EN
	OUTPUT,		 // 3 Buzzer
	OUTPUT,		 // 4 LCD D4
	OUTPUT,		 // 5 LCD D5
	OUTPUT,		 // 6 LCD D6
	OUTPUT,		 // 7 LCD D7

	INPULLUP,			// 0 Button 0
	OUTPUT,				 // 1 LCD_RS  / 7SEG_EN1
	OUTPUT,				 // 2 LCD_RW  / 7SEG_EN2
	OUTPUT,				 // 3 LCD_E  / 7SEG_DP
	INPULLUP,			// 4 BUTTON 1
	OUTPUT,				 // 5 N/C
	OUTPUT,				 // 6 N/C
	OUTPUT,				 // 7 N/C
	
	//portC
	OUTPUT,		 // 4 /A2 H-Bridge
	OUTPUT,		 // 5 /A3 H-Bridge
	OUTPUT,		 // 6 /A4 H-Bridge
	OUTPUT,		 // 7 LED 1
	INPULLUP,		 // 0 SCL  I2C EEPROM Module
	INPULLUP,		 // 1 SDA  I2C EEPROM Module
	INPULLUP,		 // 2 LED 0
	INPULLUP,		 // 3 /A1 H-Bridge
	
	//portD
	OUTPUT,				 // 0 RX UART – Bluetooth and TTL /Button 0
	OUTPUT,				 // 1 TX UART – Bluetooth and TTL /Button 1
	INPULLUP,			// 2 Button 2
	OUTPUT,				// 3 LED 2
	OUTPUT,				 // 4 EN1 H-Bridge
	OUTPUT,				 // 5 EN2 H-Bridge
	OUTPUT,				 // 6 N/C
	OUTPUT				 // 7 SERVO
};
