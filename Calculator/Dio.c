/*
 * Dio.c
 *
 * Created: 1/20/2020 7:12:00 PM
 *  Author: Costa
 */ 

#include "Dio.h"

void Dio_VidInit(void)
{
	Dio_Port_t port;
	uint8 pin,i;
	for (i=0 ; i< LASTPIN ; i++)
	{
		port = i / 8;
		pin  = i % 8 ;
		
		switch(port)
		{
			case PA:
						if (OUTPUT == Pin_state[i])
						{
							SETBIT(DDRA,pin);
						}
						else if (INFREE == Pin_state[i])
						{
							CLEARBIT(DDRA,pin);
						}
						else
						{
							CLEARBIT(DDRA,pin);
							SETBIT(PORTA,pin);
						}
						break;
			case PB:
						if (OUTPUT == Pin_state[i])
						{
							SETBIT(DDRB,pin);
						}
						else if (INFREE == Pin_state[i])
						{
							CLEARBIT(DDRB,pin);
						}
						else
						{
							CLEARBIT(DDRB,pin);
							SETBIT(PORTB,pin);
						}
						break;
			case PC:
						if (OUTPUT == Pin_state[i])
						{
							SETBIT(DDRC,pin);
						}
						else if (INFREE == Pin_state[i])
						{
							CLEARBIT(DDRC,pin);
						}
						else
						{
							CLEARBIT(DDRC,pin);
							SETBIT(PORTC,pin);
						}
						break;
			case PD:
						if (OUTPUT == Pin_state[i])
						{
							SETBIT(DDRD,pin);
						}
						else if (INFREE == Pin_state[i])
						{
							CLEARBIT(DDRD,pin);
						}
						else
						{
							CLEARBIT(DDRD,pin);
							SETBIT(PORTD,pin);
						}
						break;
			default: break;
		}
		
	}
		
}

void Dio_VidWritePin(Dio_Port_t port_num , uint8 pin_num ,uint8 level)
{
	switch(port_num)
	{
		case PA:
					if (HIGH == level)
					{
						SETBIT(PORTA,pin_num);
					}
					else
					{
						CLEARBIT(PORTA,pin_num);
					}
					break;
		case PB:
					if (HIGH == level)
					{
						SETBIT(PORTB,pin_num);
					}
					else
					{
						CLEARBIT(PORTB,pin_num);
					}
					break;
		case PC:
					if (HIGH == level)
					{
						SETBIT(PORTC,pin_num);
					}
					else
					{
						CLEARBIT(PORTC,pin_num);
					}
					break;
		case PD:
					if (HIGH == level)
					{
						SETBIT(PORTD,pin_num);
					}
					else
					{
						CLEARBIT(PORTD,pin_num);
					}
					break;
		default:    break;
	}
}

void Dio_VidTogglePin(Dio_Port_t port_num , uint8 pin_num)
{
	switch(port_num)
	{
		case PA:
			TOGGLEBIT(PORTA,pin_num);
			break;
		case PB:
			TOGGLEBIT(PORTB,pin_num);
			break;
		case PC:
			TOGGLEBIT(PORTC,pin_num);
			break;
		case PD:
			TOGGLEBIT(PORTD,pin_num);
			break;
		default:break;
	}
}

uint8 Dio_U8ReadPin(Dio_Port_t port_num , uint8 pin_num)
{
	uint8 Pin_level = LOW;
	
	switch(port_num)
	{
		case PA:
					Pin_level = READBIT(PINA,pin_num);
					break;
		case PB:
					Pin_level = READBIT(PINB,pin_num);
					break;
		case PC:
					Pin_level = READBIT(PINC,pin_num);
					break;
		case PD:
					Pin_level = READBIT(PIND,pin_num);
					break;
		default:	break;
	}
	return Pin_level;
}

void Dio_VidWritePort(Dio_Port_t port_num ,uint8 num)
{
	switch(port_num)
	{
		case PA:
					PORTA = num;
					break;
		case PB:
					PORTB = num;
					break;
		case PC:
					PORTC = num;
					break;
		case PD:
					PORTD = num;
					break;
		default:    break;
	}
}

void Dio_vidWriteHalfPort(Dio_Port_t port_num ,uint8 num , uint8 level)
{
	
	switch(port_num)
	{
		case PA:
					if (HIGH == level)
					{
						PORTA &= 0x0f; 
						num = num & 0xf0;
						PORTA |= num;
					}
					else
					{
						PORTA &= 0xf0;
						num = num & 0x0f;
						PORTA |= num;
					}
					break;
		case PB:
					if (HIGH == level)
					{
						PORTB &= 0x0f;
						num = num & 0xf0;
						PORTB |= num;
					}
					else
					{
						PORTB &= 0xf0;
						num = num & 0x0f;
						PORTB |= num;
					}
					break;
		case PC:
					if (HIGH == level)
					{
						PORTC &= 0x0f;
						num = num & 0xf0;
						PORTC |= num;
					}
					else
					{
						PORTC &= 0xf0;
						num = num & 0x0f;
						PORTC |= num;
					}
					break;
		case PD:
					if (HIGH == level)
					{
						PORTD &= 0x0f;
						num = num & 0xf0;
						PORTD |= num;
					}
					else
					{
						PORTD &= 0xf0;
						num = num & 0x0f;
						PORTD |= num;
					}
					break;
		default:    break;
	}
	
}

uint8 Dio_U8ReadPort(Dio_Port_t port_num)
{
	switch(port_num)
	{
		case PA:
			return PORTA;
			break;
		case PB:
			return PORTB;
			break;
		case PC:
			return PORTC;
			break;
		case PD:
			return PORTD;
			break;
		default:break;
	}
}