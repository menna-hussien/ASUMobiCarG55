#include<NewPing.h>
const int trigger=5;
const int echo=2;
NewPing ultrasonic(trigger,echo);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  for (int i=9;i<=13;i++)
{pinMode (i,OUTPUT);
}
pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,0);
delayMicroseconds(2);
digitalWrite(5,1);
delayMicroseconds(10);
digitalWrite(5,0);
 float d=ultrasonic.ping_cm();
   if (d<=30)
{ 
 right();
 delay(1000);
 forward();
 d=ultrasonic.ping_cm();
  if(d<=30)
  {
 right();
 delay(1000);
 
 forward();
}
  else {
  forward();
}
}
else {
   forward();
}
if(Serial.available()>0){
  char r=Serial.read();
  switch (r) {
    case 'F' : //forward
     forward();
    break;
    case 'B' : //backward
    backward();
    break;
    case 'R' : //right
   right();
    break;
    case '4' : //left
    left();
    break;
    default: //stop
   stop();
  }
}
}
void forward()
{
   digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH); 
  digitalWrite(10,LOW);
}
void right()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
 digitalWrite(11,LOW); 
  digitalWrite(10,HIGH); 
}
void left()
{
   digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
void backward()
{  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}
void stop()
{
   digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
