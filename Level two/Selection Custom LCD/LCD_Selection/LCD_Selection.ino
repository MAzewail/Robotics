#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A
LiquidCrystal_I2C lcd(32, 16, 2);

#define SENSOR1_PIN 2
#define SENSOR2_PIN 3
byte c1=0,c2=0;

byte arraw[8] = {
  B11000,
  B11100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000
};
void setup() {
  pinMode(SENSOR1_PIN,INPUT_PULLUP);
  pinMode(SENSOR2_PIN,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,arraw);
  lcd.clear();
  lcd.home();
  lcd.write(0);
  lcd.print(" Select Program");
  lcd.setCursor(0,1);
  lcd.print(" Settings ");
}

void loop() {
  if(!digitalRead(SENSOR1_PIN)){
  c1=(++c1>3)?3:(c1);
  wait(SENSOR1_PIN);
  printsc(c1);
  }
  else if(!digitalRead(SENSOR2_PIN)){
  c1=(c1--<=0)?0:c1;
  wait(SENSOR2_PIN);
  printsc(c1);
  }
  
  
}
void wait(byte pin){
  while(!digitalRead(pin));
}

void printsc(byte s){
  //lcd.clear();
  switch(s){
  case 0 : 
  lcd.home();  
  lcd.write(0);
  lcd.print(" Select Program ");
  lcd.setCursor(0,1);
  lcd.print(" Settings       ");
    break;
  case 1 : 
  lcd.home();  
  lcd.print(" Select Program");
  lcd.setCursor(0,1);
  lcd.write(0);
  lcd.print(" Settings      ");
    break;
  case 2 :   
  lcd.home();  
  lcd.print(" Settings       ");
  lcd.setCursor(0,1);
  lcd.write(0);
  lcd.print(" Power Saving ");
    break;
  case 3 : 
  lcd.home();  
  lcd.print(" Power Saving   ");
  lcd.setCursor(0,1);
  lcd.write(0);
  lcd.print(" Shut down      ");
    break;  
  }
}
