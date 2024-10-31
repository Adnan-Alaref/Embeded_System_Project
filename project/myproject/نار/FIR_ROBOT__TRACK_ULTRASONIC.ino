#include <Ultrasonic.h>
#include <Servo.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Ultrasonic ultrasonic(6, 7);
Servo myservo;  // create servo object to control a servo



int pos = 0;    // variable to store the servo position



int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;
int LFLAM=5;
int SFLAM=4;
int RFLAM=2;
int WaterP=12;
void setup() {
Serial.begin(9600);
lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Firefighting");
    lcd.setCursor(5,1);
  lcd.print("Robot");
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(WaterP,OUTPUT);
myservo.attach(3);    
myservo.write(70);

pinMode(LFLAM,INPUT);
pinMode(SFLAM,INPUT);
pinMode(RFLAM,INPUT);
digitalWrite(IN1,0);
digitalWrite(IN2,0);
digitalWrite(IN3,0);
digitalWrite(IN4,0);
digitalWrite(WaterP,0);
      delay(2000);

}

void loop() {
Serial.print("Distance in CM: ");
      Serial.println(ultrasonic.distanceRead());
      
      int A=(ultrasonic.distanceRead());
  

 
       if  (digitalRead(LFLAM)==LOW)
            {
          Serial.println("LFLAM  LL"); 
          leftt();  
                delay(200);
           stopop();
  lcd.clear();
      delay(20);
   lcd.setCursor(0,0);
  lcd.print("Track the fire");
                   delay(70);

            }

          if((A>10)&& (digitalRead(SFLAM)==LOW))
            {
          Serial.println("SFLAM  SS"); 
          front();
             delay(40);
          stopop();
  lcd.clear();
      delay(20);
   lcd.setCursor(0,0);
  lcd.print("Track the fire");
                   delay(70);

            }
                 if  (digitalRead(RFLAM)==LOW)
            {
          Serial.println("RFLAM  RR"); 
          rite();
                 delay(200);
          stopop();
            lcd.clear();
      delay(20);
   lcd.setCursor(0,0);
  lcd.print("Track the fire");
                 delay(70);

            }
            
      if  ((digitalRead(RFLAM)==HIGH)&&(digitalRead(SFLAM)==HIGH)&&(digitalRead(LFLAM)==HIGH))
            {
              lcd.clear();
      delay(20);
   lcd.setCursor(5,0);
  lcd.print("No fire");
               delay(100);

            }
            
  if((A<9)&&(digitalRead(SFLAM)==LOW)){
      Serial.println("On");
      digitalWrite(WaterP,1);
                stopop();
                  lcd.clear();
      delay(20);
   lcd.setCursor(0,0);
  lcd.print("Firefighting");
  
       for (pos = 70; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 160; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
        digitalWrite(WaterP,0);

  }
}

void leftt(){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
}


void rite(){
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
}
void back(){
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
}
void front(){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
}
void stopop(){
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
}
