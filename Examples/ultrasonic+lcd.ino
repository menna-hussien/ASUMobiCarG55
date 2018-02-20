#include <NewPing.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(11,10,9,8,7,6);
const int trigger=13;
const int echo=12;
float t,d;
void setup() {
  // put your setup code here, to run once:
  pinMode (trigger,OUTPUT);
  pinMode (echo,INPUT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,0);
delayMicroseconds(2);
digitalWrite (13,1);
t= pulseIn(echo,HIGH);
d=t/28;
lcd.setCursor(0,0);
lcd.print(String(d));
}
