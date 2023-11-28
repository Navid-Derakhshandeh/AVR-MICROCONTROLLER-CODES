#include <mega16.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed 
#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>

char e; 
char u[] = " ClockWise";
char q[] = "AntiClockWise";

void Command(char t)
{
PORTD=t;
PORTC=1;
delay_ms(5);
PORTC=0;
}

void Write( char n[] )
{
for( e = 0; e <strlen(n) ; e++ )
    {
      PORTD = n[e];
      PORTC = 0x05;
      PORTC = 0x04;
      if( e == 15 )
      {
        Command(0xC0);//New Line
      }
    }
}

void main (void)
  {
   DDRC = 0xff;
   DDRD = 0xff;  
   DDRB.1 = 0;
   DDRB.2 = 1;
   DDRA.1 = 0;
   DDRA.2 = 1;
   Command(0x01);// Clear 
   Command(0x06);// Left TO Right 
   Command(0x0c);// LCD ON Cursor OFF
   Command(0x38);// 8 bit 2 line 5*7 Dots
   while(1)
    {
      if(PINB.1 == 1)
      {     
           PORTB.2 = 1;
           Command(0x80);
           Command(0xC0);
           Write(q);   
           delay_ms(50);
           Command(0x01);
           
           
      }
      else if(PINB.1 == 0)
      {     
           PORTB.2 = 0;     
           Command(0x01);
           Command(0xC0);
           delay_ms(50);
           Command(0x01);
           
      }
      if(PINA.1 == 1)
      {         
     
           PORTA.2 = 1;
           Command(0x01);
           Write(u);
           delay_ms(50);
           Command(0x01);
      }
      else if(PINA.1 == 0)
      {    
           PORTA.2 = 0;
           Command(0x01);
           delay_ms(50);
           Command(0x01);  
      }
      
    }
}