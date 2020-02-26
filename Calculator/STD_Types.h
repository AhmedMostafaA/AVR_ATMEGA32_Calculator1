/*
 * STD_Types.h
 *
 * Created: 1/20/2020 7:04:00 PM
 *  Author: Costa
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define HIGH 1
#define LOW 0

#define SETBIT(Reg,Bit) Reg|=(1<<Bit) 
#define CLEARBIT(Reg,Bit) Reg&=~(1<<Bit)
#define TOGGLEBIT(Reg,Bit) Reg^=(1<<Bit)
#define READBIT(Reg,Bit) (Reg>>Bit)&1

typedef char uint8;
typedef short uint16;
typedef long uint32;
typedef long long uint64;
typedef char sint8;
typedef short sint16;
typedef long sint32;
typedef long long sint64;

#endif /* STD_TYPES_H_ */