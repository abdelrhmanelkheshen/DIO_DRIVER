  /******************************************************************************
 *
 * [FILE NAME]: <dio.c>
 *
 * [AUTHOR]: Abdelrhman Hesham
 *
 * [DATE CREATED]: 17/11/2023
 *
 * [DESCRIPTION]: <Header file for dio>
 *
 *******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#include "types.h"

typedef enum {
  LOCKED,
  UNLOCKED=0X4C4F434B
}PORT_Lock;

typedef enum {
  INPUT,
  OUTPUT
}Direction;

typedef struct{
  PORT_Lock lock;
  Direction PIN_DIR;
  PIN_ID PIN;
  
}PORT_Configuration;

void DIO_Init(PORT_ID PORT,PORT_Configuration* Config_Ptr);
void DIO_WritePort(PORT_ID PORT,uint8 value);
void DIO_WritePin(PORT_ID PORT,PIN_ID PIN,uint8 value);
uint8 DIO_ReadPort(PORT_ID PORT);
uint8 DIO_ReadPin(PORT_ID PORT,PIN_ID PIN);



#endif