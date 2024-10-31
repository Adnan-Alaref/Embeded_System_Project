#include <mega16.h>
/* timer0 overflow interrupt */
ISR(TIMER0_OVF_vect) {
PORTB=~PORTB; /* Toggle PORTB */
TCNT0 = 0xB2;
}
int main( void ) {
DDRB=0xFF; /* Make port B as output */
sei(); /* Waits for the next instruction to finish before
enabling interrupts *\
TIMSK=(1<<TOIE0); /* Enable Timer0 overflow interrupts */
TCNT0 = 0xB2; /* Load TCNT0, count for 10ms*/
TCCR0 = (1<<CS02) | (1<<CS00); /* Start timer0 with /1024
prescaler*/
while(1);
}