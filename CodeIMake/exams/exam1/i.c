/*
 * i.c
 *
 * Created: 12/2/2021 12:24:45 AM
 * Author: Abdo Gamal
 */

#include <mega16.h>
#include <delay.h>
#include <math.h>
#include <alcd.h>
unsigned int ADC_read(unsigned char chennel);

void main(void)
{
while (1)
    {
    // Please write your application code here

    }
}       
 unsigned int ADC_read(unsigned char chennel){
                      
 ADMUX=0b0;
 ADCSRA=0b10010011;
  ADMUX=(ADMUX&0b11100000)|chennel;
  ADCSRA.6=1;
  while(ADCSRA.6==0);
  return (ADCW/2024.0*5)*10;
 }
