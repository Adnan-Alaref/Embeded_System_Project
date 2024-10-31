/*
 * motor_PWM.c
 *
 * Created: 11/24/2021 12:30:41 AM
 * Author: Muhammad Hassan
 */

#include <mega16.h>


void PWM_init()
{
   TCCR0 |= 0b01101001 ;
   //TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);     //Fast PWM, non-inverting mode and no prescaler.
   DDRB.3 = 1;            //setting the output pin of 4th pin of Port B-PB3.                                               //0 to 255 - 0 means 0% and 255 means 100% duty cycle
}

void main(void)
{
  PWM_init();

  DDRD.2 = 0;
  PORTD.2 = 1;

  DDRD.3 = 0;
  PORTD.3 = 1;
  
  DDRB.2 = 0;
  PORTB.2 = 1;  
  
  #asm("sei") //SREG = (1<<7); // GLobal interrupt
  GICR |= 0b11100000;  
  MCUCR |= 0b00001010 ;
  MCUCSR |= (1<<6);                              
  

  OCR0 = 0; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating

while (1)
    {
    // Please write your application code here

    }
}


interrupt [2] void ext0(void)
{
  OCR0 = 255; //If button 1 is pressed, set OCR0=255 (duty cycle=100%)
}


interrupt [3] void ext1(void)
{
  OCR0=217; //If button 2 is pressed, set OCR0=217 (duty cycle=85%)
}


interrupt [19] void ext2(void)
{
  OCR0=127; //If button 3 is pressed, set OCR0=127 (duty cycle=50%)
}
