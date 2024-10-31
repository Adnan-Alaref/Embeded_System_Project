/*
 * Blinking_LED.c
 *
 * Created: 11/6/2021 10:24:14 PM
 * Author: Abdo Gamal
 */

#include <mega16.h>
#include <delay.h>

void main(void)
{
DDRA.0=0;     //pin A0  is input 
PORTA.0=1;   //  pull up
DDRC.0=1;      //c0  is out put 
while (1)
    {
    // Please write your application code here
           
            
             if(PINA.0==0)
             {
             PORTC.0=1;  
             delay_ms(500);   
               PORTC.0=0;     
              delay_ms(500);   
             }     
             else 
             {
                PORTC.0=0;  
                delay_ms(500);
             }
    
    }
}
