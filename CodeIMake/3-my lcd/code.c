#include <mega16.h>
#include <delay.h>
#include <alcd.h>
void main(void)
{
lcd_init(16);
while (1)
{
lcd_gotoxy(0,0);
lcd_putsf("Hello World");
delay_ms(100);
lcd_clear();
lcd_gotoxy(8,1);
lcd_putsf("5*6=30");
delay_ms(100);
 }
}
