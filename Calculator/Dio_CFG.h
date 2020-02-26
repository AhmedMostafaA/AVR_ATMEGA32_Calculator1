/*
 * Dio_CFG.h
 *
 * Created: 1/20/2020 7:13:20 PM
 *  Author: Costa
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

typedef enum
{
	PA=0,
	PB,
	PC,
	PD	
}Dio_Port_t;

typedef enum
{
	OUTPUT=0,
	INPULLUP,
	INFREE
}Dio_Pin_State_t;

typedef enum
{
	PORTA_0 = 0,
	PORTA_1,
	PORTA_2,
	PORTA_3,
	PORTA_4,
	PORTA_5,
	PORTA_6,
	PORTA_7,
	PORTB_0,
	PORTB_1,
	PORTB_2,
	PORTB_3,
	PORTB_4,
	PORTB_5,
	PORTB_6,
	PORTB_7,
	PORTC_0,
	PORTC_1,
	PORTC_2,
	PORTC_3,
	PORTC_4,
	PORTC_5,
	PORTC_6,
	PORTC_7,
	PORTD_0,
	PORTD_1,
	PORTD_2,
	PORTD_3,
	PORTD_4,
	PORTD_5,
	PORTD_6,
	PORTD_7,
	LASTPIN
}Dio_Pin_t;

#endif /* DIO_CFG_H_ */