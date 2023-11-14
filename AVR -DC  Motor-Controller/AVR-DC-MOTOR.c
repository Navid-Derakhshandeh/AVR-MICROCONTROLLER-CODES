#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 

#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    DDRC = 0xff;
    DDRB = 0xff;
    DDRA.1 = 0;
    DDRD.1 = 1;
    DDRD.2 = 1;
    while(1)
    {
        if(PINA.1==1)
        {
            PORTD.1 = 1;
            PORTD.2 = 0;
            PORTC = 0xff;
            delay_ms(50);
            PORTC = 0x00; 
            delay_ms(50);
        }               
        else if(PINA.1 == 0)
        {
            PORTD.2 = 1;
            PORTD.1 = 0;
            PORTB = 0xff;
            delay_ms(50);
            PORTB = 0x00; 
            delay_ms(50);
        }
            
    }     

         
  
}