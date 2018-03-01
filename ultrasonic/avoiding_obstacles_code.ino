#include <LiquidCrystal.h>
LiquidCrystal lcd (11,10,9,8,3,2);



#include<NewPing.h>
const int trigger=13;
const int echo=12;
float t,d;
void setup() {
lcd.begin(16,2);
for(int i=4;i<=7;i++)
{
  pinMode(i,OUTPUT);
}
  
  // put your setup code here, to run once:
}

void loop() {
  
  // put your main code here, to run repeatedly:
digitalWrite(13,0);
delayMicroseconds(2);
digitalWrite(13,1);
delayMicroseconds(10);
digitalWrite(13,0);
 t=pulseIn(echo,trigger);
 d=t/58;
 lcd.setCursor(0,0);
  lcd.print(String(d));
  if (d<=20)
{ 
  digitalWrite(7,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW); 
  digitalWrite(4, HIGH);
  if(d<=20)
  {
     digitalWrite(7,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW); 
  digitalWrite(4, HIGH);
  delay(50);
  }
  else {
    digitalWrite(7,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH); 
  digitalWrite(4, LOW);
}
}
else {
    digitalWrite(7,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH); 
  digitalWrite(4, LOW);
}
}
