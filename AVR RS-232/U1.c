#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 
#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>


void USART (void)
{
    UCSRB = (1<<TXEN);
    UCSRC = (1<< UCSZ1) | (1<<UCSZ0) | (1<<URSEL);
    UBRRL = 0x33;
}
void TX (unsigned char ch)
{
    while (! (UCSRA & (1<<UDRE)));
    UDR = ch;
}

void main(void)
{
    
    USART();
    while(1)
    {
        TX ('N');
    }
}
