/*
 * keypad_Driver.c
 *
 * Created: 2/21/2020 7:42:10 PM
 *  Author: Costa
 */ 
/*
* DIO_CFG.c change pins of port C make sure you used files that added in this project
*  	
*/


#include "keypad_Driver.h"
#include "Dio.h"

void Keypad_vidInt(void)
{
	Dio_vidWriteHalfPort(PC,0x00,LOW); // put 0 on output pins
}

/*
uint8 Keypad_U8Read(void)
{
	Dio_WritePin(PC,0,HIGH);
	Dio_WritePin(PC,1,LOW);
	Dio_WritePin(PC,2,LOW);
	Dio_WritePin(PC,3,LOW);
	if (Dio_ReadPin(PC,4) == HIGH)
	{
		return '1';
	}
	else if (Dio_ReadPin(PC,5) == HIGH)
	{
		return '2';
	}
	else if (Dio_ReadPin(PC,6) == HIGH)
	{
		return '3';
	}
	else if (Dio_ReadPin(PC,7) == HIGH)
	{
		return '+';
	}
	
	Dio_WritePin(PC,0,LOW);
	Dio_WritePin(PC,1,HIGH);
	Dio_WritePin(PC,2,LOW);
	Dio_WritePin(PC,3,LOW);
	if (Dio_ReadPin(PC,4) == HIGH)
	{
		return '4';
	}
	else if (Dio_ReadPin(PC,5) == HIGH)
	{
		return '5';
	}
	else if (Dio_ReadPin(PC,6) == HIGH)
	{
		return '6';
	}
	else if (Dio_ReadPin(PC,7) == HIGH)
	{
		return '-';
	}
	
	Dio_WritePin(PC,0,LOW);
	Dio_WritePin(PC,1,LOW);
	Dio_WritePin(PC,2,HIGH);
	Dio_WritePin(PC,3,LOW);
	if (Dio_ReadPin(PC,4) == HIGH)
	{
		return '7';
	}
	else if (Dio_ReadPin(PC,5) == HIGH)
	{
		return '8';
	}
	else if (Dio_ReadPin(PC,6) == HIGH)
	{
		return '9';
	}
	else if (Dio_ReadPin(PC,7) == HIGH)
	{
		return '*';
	}
	
	Dio_WritePin(PC,0,LOW);
	Dio_WritePin(PC,1,LOW);
	Dio_WritePin(PC,2,LOW);
	Dio_WritePin(PC,3,HIGH);
	if (Dio_ReadPin(PC,4) == HIGH)
	{
		return '.';
	}
	else if (Dio_ReadPin(PC,5) == HIGH)
	{
		return '0';
	}
	else if (Dio_ReadPin(PC,6) == HIGH)
	{
		return '=';
	}
	else if (Dio_ReadPin(PC,7) == HIGH)
	{
		return '/';
	}
	
	
	return 'f';
	
}

*/

/*
*	used Input_free(infree) on output pins
*	read logic one that when key pressed
*/
/*
uint8 Keypad_U8Read(void)
{
	sint8 i = 0;
	sint8 j = 0;
	sint8 temp;
	Dio_WritePin(PC,0,LOW);
	Dio_WritePin(PC,1,LOW);
	Dio_WritePin(PC,2,LOW);
	Dio_WritePin(PC,3,LOW);
	for (i=0 ; i<4 ; i++)
	{
		Dio_WritePin(PC,i,HIGH);
		for (j=4 ; j<8 ; j++)
		{
			if (Dio_ReadPin(PC,j) == HIGH)
			{
				if((i<3)&&(j<7) )
				{
					temp = (j+1) + ((i+1-2)*3);	
					return temp+48;
				}
				else if ((j==7))
				{
					if (i==0)
					{
						return '+';
					}
					else if (i==1)
					{
						return '-';
					}
					else if (i==2)
					{
						return '*';
					}
					else if (i==3)
					{
						return '/';
					}
					else{}
				}
				else if((i==3))
				{
					if (j==4)
					{
						return '.';
					}
					else if (j==5)
					{
						return '0';
					}
					else if (j==6)
					{
						return '=';
					}
				}
				else{}
			}
		}
		Dio_WritePin(PC,i,LOW);
	}
	return 'f';
}*/


/* 
*	used pull_up resistance that configure in micro_controller on output pins
*	read logic zero that when key pressed
*/
uint8 Keypad_U8Read(void)
{
	sint8 i = 0;
	sint8 j = 0;
	sint8 temp;
	Dio_VidWritePin(PC,0,HIGH);
	Dio_VidWritePin(PC,1,HIGH);
	Dio_VidWritePin(PC,2,HIGH);
	Dio_VidWritePin(PC,3,HIGH);
	for (i=0 ; i<4 ; i++)
	{
		Dio_VidWritePin(PC,i,LOW);
		for (j=4 ; j<8 ; j++)
		{
			if (Dio_U8ReadPin(PC,j) == LOW)
			{
				if((i<3)&&(j<7) )
				{
					temp = ((j+1) + ((i+1-2)*3))-1;
					return temp+48;
				}
				else if ((j==7))
				{
					if (i==0)
					{
						return '-';
					}
					else if (i==1)
					{
						return '*';
					}
					else if (i==2)
					{
						return '/';
					}
					else if (i==3)
					{
						return '+';
					}
					else{}
				}
				else if((i==3))
				{
					if (j==4)
					{
						return '.';
					}
					else if (j==5)
					{
						return '0';
					}
					else if (j==6)
					{
						return '=';
					}
				}
				else{}
			}
		}
		Dio_VidWritePin(PC,i,HIGH);
	}
	return 'f';
}

