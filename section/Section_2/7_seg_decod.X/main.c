/*
 * File:   main.c
 * Author: Muhammad Hassan
 *
 * Created on October 26, 2021, 9:41 AM
 */


#include <avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

#define set_bit(reg,b) reg |= (1<<b)
#define clr_bit(reg,b) reg &= ~(1<<b)
#define tog_bit(reg,b) reg ^= (1<<b)

int main(void) {
    /* Replace with your application code */
    clr_bit(DDRA,0); // PA0 as an input
    set_bit(PORTA,0); // enable pull up
    
    set_bit(DDRC,0);  // PC0 as an output
    clr_bit(PORTC,0); // PC0 = 0 
    
    DDRD |= 0b00001111; // PD0,PD1,PD2,PD3 output
    PORTD = 0;          //000000000
    
    char count = 0;
    while (1) 
    {
        if( !(PINA & 0x01) ) //toggel  the led when press on switch
        {
            tog_bit(PORTC,0); 
        }
         _delay_ms(500);
        PORTD = count;
        if (count == 9)
            count = 0;     
        count ++;
       
            
    }
}
