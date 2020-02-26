/*
 * Stack.h
 *
 * Created: 2/25/2020 10:05:39 PM
 *  Author: costa
 */ 


#ifndef STACK_H_
#define STACK_H_

#include "STD_Types.h"


extern sint8 pop(void);
extern uint8 push(sint8 data);
extern sint8 isempty(void);
extern sint8 isfull(void);

#endif /* STACK_H_ */