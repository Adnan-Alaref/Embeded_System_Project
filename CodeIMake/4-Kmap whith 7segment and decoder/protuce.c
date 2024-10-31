/*
 * protuce.c
 *
 * Created: 11/18/2021 9:52:47 PM
 * Author: Abdo Gamal
 */

    #include <mega16.h>
     char Keypad();    
    
    void main(void)
    {
      char number;
     DDRC=0b00000111;
     PORTC=0b11111000;
     DDRD=0x0f;
  
         
    while (1)
        {
        // Please write your application code here           
        
              number=Keypad();
              PORTD=  number;

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
                   return 1;
               break;

                case  0b11101110:
                   return 4;
               break; 
               
               
                case  0b11011110:
                   return 7;
               break;    
                  case  0b10111110:
                   return 10;
               break;
               }             
               
                     
        PORTC.0=1;
        PORTC.1=0;
        PORTC.2=1;
        switch (PINC)
               {
               case  0b11110101:
                   return 2;
               break;

                case  0b11101101:
                   return 5;
               break; 
               
               
                case 0b11011101:
                   return 8;
               break;    
                  case  0b10111101:
                   return 0;
               break;
               }
             
                                     
        PORTC.0=1;
        PORTC.1=1;
        PORTC.2=0;
        switch (PINC)
               {
               case  0b11110011:
                   return 3;
               break;

                case  0b11101011:
                   return 6;
               break; 
               
               
                case  0b11011011:
                   return 9;
               break;    
                  case  0b10111011:
                   return 11;
               break;
               }
             }
    }
