  /******************************************************************************
 *
 * [FILE NAME]: <dio.c>
 *
 * [AUTHOR]: Abdelrhman Hesham
 *
 * [DATE CREATED]: 17/11/2023
 *
 * [DESCRIPTION]: <Source file for dio>
 *
 *******************************************************************************/
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bitwise_operation.h"

void DIO_Init(PORT_ID PORT,PORT_Configuration* Config_Ptr)
{
    SET_BIT(SYSCTL_RCGCGPIO_R,PORT);
 
    while((GET_BIT(SYSCTL_RCGCGPIO_R,PORT))==0){};

    switch(PORT) 
    {
    case PORTA:
      GPIO_PORTA_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTA_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTA_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTA_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTA_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTA_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTA_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if ( Config_Ptr -> PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTA_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTA_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTA_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    case PORTB:
   
      GPIO_PORTB_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTB_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTB_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTB_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTB_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTB_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTB_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if ( Config_Ptr -> PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTB_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTB_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTB_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    case PORTC:
      GPIO_PORTC_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTC_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTC_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTC_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTC_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTC_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTC_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if (Config_Ptr->PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTC_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTC_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTC_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    case PORTD:
    
      GPIO_PORTD_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTD_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTD_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTD_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTD_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTD_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTD_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if (Config_Ptr -> PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTD_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTD_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTD_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    case PORTE:
      GPIO_PORTE_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTE_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTE_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTE_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTE_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTE_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTE_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if (Config_Ptr -> PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTE_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTE_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTE_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    case PORTF:
      GPIO_PORTF_LOCK_R= Config_Ptr->lock; //unlock PORTA
  
      GPIO_PORTF_CR_R|= (1 << Config_Ptr->PIN); //Accept changes
  
      GPIO_PORTF_AMSEL_R &= ~(1 << Config_Ptr->PIN);
   
      GPIO_PORTF_PCTL_R &= ~(0x00000000 | ( 0x0F << (Config_Ptr->PIN)));
  
      GPIO_PORTF_AFSEL_R &= ~(1 << Config_Ptr->PIN);
  
      if (Config_Ptr -> PIN_DIR == LOGIC_LOW)
      {
          GPIO_PORTF_DIR_R &= ~(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTF_PUR_R |= (1 << Config_Ptr->PIN); //pullup
      }
      else if  (Config_Ptr -> PIN_DIR == LOGIC_HIGH)
      {
          GPIO_PORTF_DIR_R|=(1 << Config_Ptr->PIN); // Define directions 
          GPIO_PORTF_DATA_R &= ~(1 << Config_Ptr->PIN);
      }

      GPIO_PORTF_DEN_R |= (1 << Config_Ptr->PIN);//enable pins
      break;
    }
}
             
void DIO_WritePort(PORT_ID PORT,uint8 value)
{
   switch(PORT)
   {
   case PORTA:
     GPIO_PORTA_DATA_R=value;
     break;
   case PORTB:
      GPIO_PORTB_DATA_R=value;
      break;
   case PORTC:
      GPIO_PORTC_DATA_R=value;
      break;
   case PORTD:
       GPIO_PORTD_DATA_R=value;
       break;
   case PORTE:
       GPIO_PORTE_DATA_R=value;
       break;
   case PORTF:
       GPIO_PORTF_DATA_R=value;
       break;
   default:
     break;
   }
 }
 
void DIO_WritePin(PORT_ID PORT,PIN_ID PIN,uint8 value)
{
   switch(PORT)
   {
   case PORTA:
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTA_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTA_DATA_R,PIN);
     }
     case PORTB:
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTB_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTB_DATA_R,PIN);
     }
       case PORTC:
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTC_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTC_DATA_R,PIN);
     }
       case PORTD:
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTD_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTD_DATA_R,PIN);
     }
       case PORTE:
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTE_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTE_DATA_R,PIN);
     }
       case PORTF:
       
     if(value==LOGIC_LOW)
     {
       CLEAR_BIT(GPIO_PORTF_DATA_R,PIN);
     }
     else
     {
       SET_BIT(GPIO_PORTF_DATA_R,PIN);
     }
   default:
     break;
   }
}

uint8 DIO_ReadPort(PORT_ID PORT)
{
   switch(PORT)
   {
   case PORTA:
     return GPIO_PORTA_DATA_R;
     break;
   case PORTB:
        return GPIO_PORTB_DATA_R;
      break;
   case PORTC:
       return GPIO_PORTC_DATA_R;
      break;
   case PORTD:
        return GPIO_PORTD_DATA_R;
       break;
   case PORTE:
        return GPIO_PORTE_DATA_R;
       break;
   case PORTF:
         return GPIO_PORTF_DATA_R;
       break;
   default:
     return 0;
   }
  
}

uint8 DIO_ReadPin(PORT_ID PORT,PIN_ID PIN)
{
   switch(PORT)
   {
   case PORTA:
     return GET_BIT(GPIO_PORTA_DATA_R,PIN);
     break;
   case PORTB:
     return GET_BIT(GPIO_PORTB_DATA_R,PIN);
      break;
   case PORTC:
     return GET_BIT(GPIO_PORTC_DATA_R,PIN);
      break;
   case PORTD:
        return GET_BIT(GPIO_PORTD_DATA_R,PIN);
       break;
   case PORTE:
        return GET_BIT(GPIO_PORTE_DATA_R,PIN);
       break;
   case PORTF:
        return GET_BIT(GPIO_PORTF_DATA_R,PIN);
       break;
   default:
     return 0;
   }
}  