/*
 * Stack.c
 *
 * Created: 2/25/2020 9:57:50 PM
 *  Author: Costa
 */ 


#include "Stack.h"

uint8 MAXSIZE = 2;
sint8 stack[2];
uint8 top = 0;

sint8 isempty(void) {

	if(top == 0)
		return 1;
	else
		return 0;
}

sint8 isfull(void) {

	if(top == MAXSIZE)
		return 1;
	else
		return 0;
}

sint8 peek(void) {
	return stack[top];
}

sint8 pop(void) 
{
	sint8 data;
	if(!isempty()) {
		data = stack[top];
		top = top - 1;
		return data;
		} else {
		return -1;
	}
}

uint8 push(sint8 data) 
{

	if(!isfull()) 
	{
		top = top + 1;
		stack[top] = data;
		return 1;
	} 
	else 
	{
		return 0;
	}
}