/*
 * File:   main.c
 * Author: Muhammad Hassan
 *
 * Created on October 26, 2021, 9:25 AM
 */


#include <avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

#define set_bit(reg,b) reg |= (1<<b)
#define clr_bit(reg,b) reg &= ~(1<<b)
#define tog_bit(reg,b) reg ^= (1<<b) 

int main(void) {
    /* Replace with your application code */
    DDRA = 0b00000000 ; // portA as an input  DDRA = 0x00;
    
    PORTA = 0b11111111; // enable pull up
    
    DDRC  = 0b01111111;  //port_c as an output
    PORTC = 0;
    while (1) 
    {
    
    switch(PINA)
    {
     case 0b11111110:
     PORTC = 0b01000000;
     break;
     
     case 0b11111101:
     PORTC = 0b01111001;
     break;
     
     case 0b11111011:
     PORTC = 0b00100100;
     break;
     
     case 0b11110111:
     PORTC = 0b00110000;
     break;
     
     case 0b11101111:
     PORTC = 0b00011001;
     break;
     
     case 0b11011111:
     PORTC = 0b00010010;
     break;
     
     case 0b10111111:
     PORTC = 0b00000010;
     break;
     
     case 0b01111111:
     PORTC = 0b01111000;
     break;           
     
     default:
     PORTC = 0b11111111;
     break;
     
    }
    }
}
