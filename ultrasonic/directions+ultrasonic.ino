#include<NewPing.h>
const int trigger=5;
const int echo=2;
long duration,d ;
NewPing ultrasonic(trigger,echo);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
 usReading();
   if (d<=30)
{ 
 right();
 delay(500);
 forward();
usReading();
  if(d<=30)
  {
 right();
 delay(500);
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
    case 'L' : //left
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
  
   digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
void left()
{
  
   digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
 digitalWrite(11,LOW); 
  digitalWrite(10,HIGH); 
  
  
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
long usReadig()
{
  digitalWrite(5,0);
delayMicroseconds(2);
digitalWrite(5,1);
delayMicroseconds(10);
digitalWrite(5,0);
  duration = pulseIn(2,HIGH);
  d= (duration/2)*0.034 ; 
  return d;
}
