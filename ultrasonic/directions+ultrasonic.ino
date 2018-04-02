#include<NewPing.h>
const int trigger=5;
const int echo=2;
int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
int spd1 = 9;
int spd2 = 6;
long duration,d ;
NewPing ultrasonic(trigger,echo);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(moror1f,OUTPUT);
  pinMode(motor1b,OUTPUT);
  pinMode(motor2f,OUTPUT);
  pinMode(motor2b,OUTPUT);
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
