/*
 * Dio.h
 *
 * Created: 1/20/2020 7:11:43 PM
 *  Author: Costa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "Dio_CFG.h"

extern const Dio_Pin_State_t Pin_state[];
extern void Dio_VidInit(void);
extern void Dio_VidWritePin(Dio_Port_t port_num , uint8 pin_num ,uint8 level);
extern void Dio_VidTogglePin(Dio_Port_t port_num , uint8 pin_num);
extern uint8 Dio_U8ReadPin(Dio_Port_t port_num , uint8 pin_num);
extern void Dio_VidWritePort(Dio_Port_t port_num ,uint8 num);
extern void Dio_vidWriteHalfPort(Dio_Port_t port_num ,uint8 num , uint8 level);
extern uint8 Dio_U8ReadPort(Dio_Port_t port_num);


#endif /* DIO_H_ */