/*
 * File:   main.c
 * Author: Muhammad Hassan
 *
 * Created on October 26, 2021, 8:38 AM
 */


#include <avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

#define set_bit(reg,b) reg |= (1<<b)
#define clr_bit(reg,b) reg &= ~(1<<b)
#define tog_bit(reg,b) reg ^= (1<<b) 

int main(void) {
    /* Replace with your application code */
   
    clr_bit(DDRA,7); // PA0 input
    set_bit(PORTA,7); // enable pull up
    
    set_bit(DDRB,4);  // PC0 output
    clr_bit(PORTB,4); // initial value =0
  
    // char flag = 0;
    while (1) 
    {

/*       if( !(PINA & 0x80) )
        {
            tog_bit(PORTC,0); 
        }
  */
        
      if ( ( (PINA)&(0x80) )== 0 )            // If switch is closed
      {
         set_bit(PORTB,4);
         _delay_ms(500);
         clr_bit(PORTB,4);
         _delay_ms(500);
      }
      else
      {
         clr_bit(PORTB,4);
      }
    }
    
 
}
