/*
 * ADC.c
 *
 * Created: 2/12/2019 1:37:07 PM
 * Author: Lost Heaven
 */

#include <mega16.h>
#include <delay.h>

unsigned int ADC(unsigned char channel);

void main(void)
{
unsigned int read;
DDRC = 0xff;
DDRD = 0x03;

ADMUX = 0b00000000;
ADCSRA = 0b10000110;


while (1)                               
    {
    read = ADC(0);
    PORTC = read;    //(PORTC = read & 0x00ff)
    PORTD = read >> 8;
    delay_ms(1000);
    read = ADC(1);
    PORTC = read;    //(PORTC = read & 0x00ff)
    PORTD = read >> 8;
    delay_ms(1000);
    }
}

unsigned int ADC(unsigned char channel)
{
 ADMUX = (ADMUX & 0b11100000) | channel;
 delay_us(10);
 ADCSRA.6 = 1;   //Start conversion
 while(ADCSRA.6 == 1);  //Wait till conversion ends
 return ADCW; // return ADCL|(DCH<<8) 
}
/*
float ADC(unsigned char channel)
{
 ADMUX = (ADMUX & 0b11100000) | channel;
 delay_us(10);
 ADCSRA.6 = 1;   //Start conversion
 while(ADCSRA.6 == 1);  //Wait till conversion ends
 return ADCW/1023.0 * Vref; 
}
*/