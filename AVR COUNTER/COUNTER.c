#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 
#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    int i ;
    int j;
    unsigned char Array[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
    unsigned char Array1[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
    DDRA = 0xff;
    DDRB = 0xff; 

while (1)
      {
          for(i=0;i<=9;i++)
          {
            PORTA = Array[i];
            delay_ms(30);
            for(j=0;j<=9;j++)
            {
               PORTB = Array1[j];
               delay_ms(30);
            }
          
            
          }
         

      }
}
