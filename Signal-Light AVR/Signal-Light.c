#include <mega8.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 

#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    DDRC.1 = 1;
    DDRC.2 = 1;
    DDRC.3 = 1;
    while(1)
    {
      PORTC.3 = 0x00;
      PORTC.1 = 0xff;
      delay_ms(500);
      PORTC.1 = 0x00;
      PORTC.2 = 0xff;
      delay_ms(150);
      PORTC.2 = 0x00;
      PORTC.3 = 0xff;
      delay_ms(500); 
    }
}