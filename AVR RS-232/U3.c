#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 
#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    DDRA = 0xff;
    UCSRB = (1<<RXEN);
    UCSRC = (1<<UCSZ1) | (1<<UCSZ0) | (1<<URSEL);
    UBRRL = 0x33;
while (1)
      {
        while (! (UCSRA & (1<<RXC)));
            PORTA = UDR;
      }
}
