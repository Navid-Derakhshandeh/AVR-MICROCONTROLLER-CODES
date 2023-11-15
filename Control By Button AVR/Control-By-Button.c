#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 

#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    DDRB.1 = 0;
    DDRB.2 = 0;
    DDRB.3 = 0;
    DDRD.1 = 1;
    DDRD.2 = 1;
    DDRD.3 = 1;
    while(1)
    {
      if(PINB.1==1)   
      {
          PORTD.1 = 1;
      }             
      else if(PINB.1==0)
      {
          PORTD.1 = 0;
      }
      if(PINB.2==1)   
      {
          PORTD.2 = 1;
      }             
      else if(PINB.2==0)
      {
          PORTD.2 = 0;
      }
      if(PINB.3==1)   
      {
          PORTD.3 = 1;
      }             
      else if(PINB.3==0)
      {
          PORTD.3 = 0;
      }
    }
}