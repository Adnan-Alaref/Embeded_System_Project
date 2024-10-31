/*
 * protuce.c
 *
 * Created: 11/18/2021 9:52:47 PM
 * Author: Abdo Gamal
 */

    #include <mega16.h>   
     #include <alcd.h>  // not  lcd.h not work
     char Keypad();    
    
    void main(void)
    {
    
     char number;
     DDRC=0b00000111;
     PORTC=0b11111000;
     lcd_init(16);
         
    while (1)
        {
        // Please write your application code here           
        
              number=Keypad(); 
              lcd_clear();
              
              if(number=='*'||number=='#')   {
              lcd_printf("number = %c",number); }
              else           {
              lcd_printf("number = %d",number); 
                              }         
                              
              lcd_gotoxy(0,1);
              if(number=='*'||number=='#')
              lcd_printf("number+1 = %c",number);
              else  
              lcd_printf("number +1 = %d",number+1);

        }
    } 
    
    
    char Keypad(){
                 
    while(1){
        PORTC.0=0;
        PORTC.1=1;
        PORTC.2=1;
        switch (PINC)
               {
               case 0b11110110:    
                while (PINC.3==0) ;        //for debouncey
                   return 1;    
                   
               break;
                case  0b11101110:
                    while (PINC.4==0);
                   return 4;
               break; 
               
               
                case  0b11011110: 
                  while (PINC.5==0);
                   return 7;
               break;    
                  case  0b10111110:   
                    while (PINC.6==0);
                   return '*';
               break;
               }             
               
                     
        PORTC.0=1;
        PORTC.1=0;
        PORTC.2=1;
        switch (PINC)
               {
               case  0b11110101:
                 while (PINC.3==0);
                   return 2;
               break;

                case  0b11101101: 
                  while (PINC.4==0);
                   return 5;
               break; 
               
               
                case 0b11011101:
                  while (PINC.5==0);
                   return 8;
               break;    
                  case  0b10111101:
                    while (PINC.6==0) ;
                   return 0;
               break;
               }
             
                                     
        PORTC.0=1;
        PORTC.1=1;
        PORTC.2=0;
        switch (PINC)
               {
               case  0b11110011: 
                 while (PINC.3==0);
                   return 3;
               break;

                case  0b11101011:
                  while (PINC.4==0) ;
                   return 6;
               break; 
               
               
                case  0b11011011:
                  while (PINC.5==0) ;
                   return 9;
               break;    
                  case  0b10111011:
                    while (PINC.6==0);
                   return '#';
               break;
               }
             }
    }
