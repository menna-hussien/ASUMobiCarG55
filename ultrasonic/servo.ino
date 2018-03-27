#include<Servo.h>
#include<NewPing.h>
const int trigger=5;
const int echo=2;
NewPing ultrasonic (trigger,echo);
Servo myservo;
float d_forward,d_left,d_right;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(5,OUTPUT);
pinMode(2,INPUT);
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
myservo.attach(3);
myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
   forward();
   digitalWrite(8,HIGH);
   digitalWrite(7,LOW);
 analogWrite(9,255);
  analogWrite(6,255);
digitalWrite(5,0);
delayMicroseconds(2);
digitalWrite(5,1);
delayMicroseconds(10);
digitalWrite(5,0);
d_forward=ultrasonic.ping_cm();

if (d_forward<=30)
{
  stop();
  myservo.write(0); delay(500);
  d_left=ultrasonic.ping_cm();
  myservo.write(180); delay(500);
  d_right=ultrasonic.ping_cm();
  if(d_left<d_right)
  right();
  else left();
}

else forward();
}

void forward()
{
  digitalWrite(13,HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH); 
  digitalWrite(10, LOW);
}
void backward()
{
  digitalWrite(13,LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW); 
  digitalWrite(10, HIGH);
}
void left()
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
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
void stop()
{
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW); 
  digitalWrite(10,LOW);
}


