#include "mcc_generated_files/system.h"
#include <stdio.h>
/*
                         UART_Demo.c
 */

unsigned char temp;

void UART_Demo_Initialize(void) 
{

    printf("\rPICDEM LAB II - Date 08/11/2015\r\n");  
    printf("UART Communications 8-bit Rx and Tx\r\n\n");
    printf("Keyboard Type H : LED ON   Type L: LED OFF \r\n\n");

}

void UART_Demo_Command_INT(void) 
{    
    if(eusartRxCount!=0) 
    {   

    temp=UART1_Read();  // read a byte for RX

    EUSART_Write(temp);  // send a byte to TX  (from Rx)

    switch(temp)    // check command  
    {
     case 'H':
     case 'h':
        {
            LED_SetHigh();
            printf(" -> LED On!!      \r");             
            break;
        }
     case 'L':
     case 'l':
        {
            LED_SetLow();
            printf(" -> LED Off!!     \r");   
            break;
        }
     default:
        {
            printf(" -> Fail Command!! \r");            
            break;
        }       
    }
    }
}

/**
 End of File
 */