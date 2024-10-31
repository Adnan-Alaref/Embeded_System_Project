/*
 * LED_PWM.c
 *
 * Created: 11/23/2021 11:33:25 PM
 * Author: Muhammad Hassan
 */

#include <mega16.h>
#include <delay.h>


void PWM_init()
{
   TCCR0 |= 0b01101001 ;
   //TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);     //Fast PWM, non-inverting mode and no prescaler.
   DDRB.3 = 1;            //setting the output pin of 4th pin of Port B-PB3.                                                 //0 to 255 - 0 means 0% and 255 means 100% duty cycle
}


void main(void)
{
	unsigned char duty;
	
	PWM_init();  
    
	while (1)
	{
		for(duty=0; duty<127; duty++)
		{	
			OCR0 = duty;  /*increase the LED light intensity*/
			delay_ms(8);
		}
        
		for(duty=127; duty>1; duty--)
		{
			OCR0 = duty;  //decrease the LED light intensity
			delay_ms(8);
		}
        
	}       
    
}
