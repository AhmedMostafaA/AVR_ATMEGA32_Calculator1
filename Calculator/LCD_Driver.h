/*
 * LCD_Driver.h
 *
 * Created: 1/22/2020 1:58:59 PM
 *  Author: Costa
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "STD_Types.h"

extern void LCD_VidInit(void);
extern void LCD_VidCommand(uint8_t cmd);
extern void LCD_VidDisplayChar(uint8_t data);
extern void LCD_VidDisplayString(char * str);
extern void LCD_VidDisplayNum(uint16 num);
extern void LCD_VidDisplayNum_2(uint16 num);
extern void LCD_VidDisplayNum_8bit(sint8 num);
extern void LCD_VidDisplayNum_Binary(sint8 num);
#define RS_PIN 1
#define RW_PIN 2
#define E_PIN 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

typedef enum{
	
	Clear_display_screen = 0x01,
	Return_home = 0x02,
	Decrement_cursor = 0x04,
	Increment_cursor = 0x06,
	Shift_display_right = 0x05,
	Shift_display_left = 0x07,
	Display_off_cursor_off = 0x08,
	Display_off_cursor_on = 0x0a,
	Display_on_cursor_off  = 0x0c,
	Display_on_cursor_blinking = 0x0e,
	Shift_cursor_left = 0x10,
	Shift_cursor_right = 0x14,
	Shift_display_pos_left = 0x18,
	Shift_display_pos_right = 0x1c,
	cursor_beginning_1_line = 0x80,
	cursor_beginning_2_line = 0xc0
	
}command_t;

#endif /* LCD_DRIVER_H_ */