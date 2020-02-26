/*
 * project_26_2_2020_Calculator2.c
 *
 * Created: 2/26/2020 12:41:58 AM
 * Author : Costa
 */ 


#include "STD_Types.h"
#include "Dio.h"
#include "keypad_Driver.h"
#include "LCD_Driver.h"
#include "Stack.h"

sint8 operation (sint8 num1 , sint8 num2 , uint8 opr);
void Error_msg();

int main(void)
{
	uint8 key , keyReleased = 0;
	uint8 digit_flag=0 ,  oprnd = 0;
	sint8 fnum = 0, snum = 0 , result;
	Dio_VidInit();
	Keypad_vidInt();
	LCD_VidInit();
	while (1)
	{
		key = Keypad_U8Read();
		Keypad_vidInt();
		
		/* just for check that released key to not add number more than one in one pressed */
		if (key != 'f' && keyReleased == 1)
		{
			LCD_VidDisplayChar(key);
			keyReleased = 0;
			
			if (key>='0' && key <= '9')
			{
				if (digit_flag == 1)
				{
					fnum = pop() * 10;
					fnum += (key-48);
					push(fnum);
					
				}
				else if (digit_flag == 0 )
				{
					digit_flag = 1 ;
					if (!isfull())
					{
						push(key-48);
					}
					else
					{Error_msg();}
				}
				else{}
				
			}
			else if (key == '.')
			{
				main();
			}
			else if (key != '=')
			{
				digit_flag = 0;
				
				if (oprnd == 0)
				{
					oprnd = key;
				}
				else
				{
					if (!isempty())
					{
						snum = pop();
					}
					else
					{Error_msg();}
					
					if (!isempty())
					{
						fnum = pop();
					}
					else
					{Error_msg();}
					
					result = operation(fnum,snum,oprnd);
					if (!isfull())
					{
						push(result);
					}
					else
					{
						Error_msg();
					}
					
					oprnd = key;
				}
			}
			else if (key == '=')
			{
				digit_flag = 0;
				if (!isempty())
				{
					snum = pop();
				}
				else
				{Error_msg();}
				
				if (!isempty())
				{
					fnum = pop();
				}
				else
				{Error_msg();}
					
				result = operation(fnum,snum,oprnd);
				LCD_VidCommand(Clear_display_screen);
				LCD_VidDisplayNum_8bit(result);
				//LCD_VidDisplayNum_Binary(result);
				oprnd = 0;
				if (!isfull())
				{
					push(result);
				}
				else
				{Error_msg();}
			}
			else{}
		}
		else if (key == 'f')
		{
			keyReleased =1;
		}
		else{}
	}
}

sint8 operation (sint8 num1 , sint8 num2 , uint8 opr)
{
	if (opr == '+')
	{
		return (num1+num2);
	}
	else if (opr == '-')
	{
		return (num1-num2);
	}
	else if (opr == '*')
	{
		return (num1*num2);
	}
	else if (opr == '/')
	{
		if (num2 == 0 )
		{
			LCD_VidCommand(Clear_display_screen);
			LCD_VidCommand(cursor_beginning_2_line);
			LCD_VidDisplayString("divided by zero");
			_delay_ms(500);
			LCD_VidCommand(cursor_beginning_1_line);
			main();
		}
		return (num1/num2);
	}
	
}

void Error_msg()
{
	LCD_VidCommand(Clear_display_screen);
	LCD_VidCommand(cursor_beginning_2_line);
	LCD_VidDisplayString("Error");
	_delay_ms(500);
	main();
}