/*
 * LCD_Driver.c
 *
 * Created: 1/22/2020 1:59:35 PM
 *  Author: Costa
 */ 


#include "STD_Types.h"
#include "Dio.h"
#include "Dio_CFG.h"
#include "LCD_Driver.h"

void LCD_VidInit(void)
{
	
	// initialization steps as Data sheet
	Dio_VidWritePin(PB,RW_PIN,LOW);
	Dio_VidWritePin(PB,E_PIN,LOW);
	_delay_ms(15);

	LCD_VidCommand(0x33);
	LCD_VidCommand(0x32);
	LCD_VidCommand(0x28);
	LCD_VidCommand(0x0e);
	LCD_VidCommand(0x01);

	_delay_us(2000);
}

void LCD_VidCommand(uint8_t cmd)
{
	Dio_VidWritePin(PB,RS_PIN,LOW);
	//SEND the command high nibble to D4:D7
	Dio_VidWritePin(PA,LCD_D4,READBIT(cmd,4));
	Dio_VidWritePin(PA,LCD_D5,READBIT(cmd,5));
	Dio_VidWritePin(PA,LCD_D6,READBIT(cmd,6));
	Dio_VidWritePin(PA,LCD_D7,READBIT(cmd,7));
		
	Dio_VidWritePin(PB,E_PIN,HIGH);
	_delay_ms(1);
	Dio_VidWritePin(PB,E_PIN,LOW);
	_delay_us(100);
		
	//send the Low nibble to D0:D3
	Dio_VidWritePin(PA,LCD_D4,READBIT(cmd,0));
	Dio_VidWritePin(PA,LCD_D5,READBIT(cmd,1));
	Dio_VidWritePin(PA,LCD_D6,READBIT(cmd,2));
	Dio_VidWritePin(PA,LCD_D7,READBIT(cmd,3));
	
	
	Dio_VidWritePin(PB,E_PIN,HIGH);
	_delay_ms(1);
	Dio_VidWritePin(PB,E_PIN,LOW);
	_delay_us(100);
}

void LCD_VidDisplayChar(uint8_t data)
{
	Dio_VidWritePin(PB,RS_PIN,HIGH);
	
	//SEND the command high nibble to D4:D7
	Dio_VidWritePin(PA,LCD_D4,READBIT(data,4));
	Dio_VidWritePin(PA,LCD_D5,READBIT(data,5));
	Dio_VidWritePin(PA,LCD_D6,READBIT(data,6));
	Dio_VidWritePin(PA,LCD_D7,READBIT(data,7));
		
	Dio_VidWritePin(PB,E_PIN,HIGH);
	_delay_ms(1);
	Dio_VidWritePin(PB,E_PIN,LOW);
	_delay_us(100);
		
	//send the Low nibble to D0:D3
	Dio_VidWritePin(PA,LCD_D4,READBIT(data,0));
	Dio_VidWritePin(PA,LCD_D5,READBIT(data,1));
	Dio_VidWritePin(PA,LCD_D6,READBIT(data,2));
	Dio_VidWritePin(PA,LCD_D7,READBIT(data,3));
	
	Dio_VidWritePin(PB,E_PIN,HIGH);
	_delay_ms(1);
	Dio_VidWritePin(PB,E_PIN,LOW);
	_delay_us(100);
}

void LCD_VidDisplayString(char * str)
{
	uint8 i =0 ;
	while(str[i] != 0)
	{
		LCD_VidDisplayChar(str[i]);
		i++;
	}
}

void LCD_VidDisplayNum(uint16 num)
{
	uint8 i =0 , sub_num;
	LCD_VidCommand(Shift_cursor_right);
	LCD_VidCommand(Shift_cursor_right);
	LCD_VidCommand(Shift_cursor_right);
	LCD_VidCommand(Shift_cursor_right);
	LCD_VidCommand(Decrement_cursor);
	for (i=0;i<5;i++)
	{
		sub_num = num %10;
		num /= 10;
		LCD_VidDisplayChar(sub_num+48);
	}
	LCD_VidCommand(Increment_cursor);
}

void LCD_VidDisplayNum_2(uint16 num)
{
	uint16 i;
	uint8 sub_num;
	for (i=10000 ; i >= 1 ; i/=10)
	{
		if (num >= i)
		{
			sub_num = (num/i)%10;
			LCD_VidDisplayChar(sub_num+48);
		}
		
	}
}

void LCD_VidDisplayNum_8bit(sint8 num)
{
	
	if (READBIT(num,7) == 0x01)
	{
		num *= -1;
		LCD_VidDisplayChar('-');
	}

	sint8 str[5]; //< Use a array of char
	itoa(num,str,10);
	LCD_VidDisplayString(str);
	
	
	/*for (sint8 i=7 ; i>0 ; i--)
	{
		if (READBIT(num , i) == 0x00)
		{
			LCD_VidDisplayChar('0');
		}
		else if (READBIT(num , i) == 0x01)
		{
			LCD_VidDisplayChar('1');
		}
		else
		{
			LCD_VidDisplayChar('-');
		}
	}
	if (READBIT(num , 0) == 0x00)
	{
		LCD_VidDisplayChar('0');
	}
	else if (READBIT(num , 0) == 0x01)
	{
		LCD_VidDisplayChar('1');
	}
	else
	{
		LCD_VidDisplayChar('-');
	}*/
}


void LCD_VidDisplayNum_Binary(sint8 num)
{
	LCD_VidCommand(cursor_beginning_2_line);
	for (sint8 i=7 ; i>0 ; i--)
	{
		if (READBIT(num , i) == 0x00)
		{
			LCD_VidDisplayChar('0');
		}
		else if (READBIT(num , i) == 0x01)
		{
			LCD_VidDisplayChar('1');
		}
		else
		{
			LCD_VidDisplayChar('0');
		}
	}
	if (READBIT(num , 0) == 0x00)
	{
		LCD_VidDisplayChar('0');
	}
	else if (READBIT(num , 0) == 0x01)
	{
		LCD_VidDisplayChar('1');
	}
	else
	{
		LCD_VidDisplayChar('0');
	}
	
	LCD_VidCommand(cursor_beginning_1_line);
}