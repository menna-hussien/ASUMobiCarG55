#include<Servo.h>
#include<NewPing.h>
const int trigger=5;
const int echo=2;
NewPing ultrasonic (trigger,echo);
Servo myservo;
float d_forward,d_left,d_right;
char data = 0;
int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
int spd1 = 7;
int spd2 = 6;
long duration;
long distance;
void setup() {
  // put your setu p code here, to run once:
   Serial.begin(9600);
 pinMode (motor1f, OUTPUT);
  pinMode (motor1b, OUTPUT);
  pinMode (motor2f, OUTPUT);
  pinMode (motor2b, OUTPUT);
  pinMode (spd1, OUTPUT);
  pinMode (spd2, OUTPUT);
pinMode(5,OUTPUT);
pinMode(2,INPUT);

myservo.attach(9);
myservo.write(90);
myservo.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
   forward();

if (Serial.available() > 0)
  {

    data = Serial.read();
    if (USReadings() > 30) {
      Serial.println("USReadings()>30");
      switch (data)
      {
        case 'F' :
        Serial.println("forward");
          forward();
          data = 0;
          break;

        case 'B' :
          backward();
          data = 0;
          break;

        case 'R' :
          left();
          data = 0;

          break;
        case 'L' :
          right();
          data = 0;

          break;

        default:
          digitalWrite (motor1b, LOW);
          digitalWrite (motor1f, LOW);
          digitalWrite (motor2b, LOW);
          digitalWrite (motor2f, LOW);
          digitalWrite(spd1, HIGH);
          digitalWrite(spd2, HIGH);
          //  analogWrite (9,255);
          //analogWrite (6,255);

      }
    }
    else if (USReadings() < 30)
    { Serial.println("d<30");
    STOP();
  myservo.write(0); delay(1000);
  d_left=ultrasonic.ping_cm();
  delay(500);
  Serial.println(d_left);
  myservo.write(180); delay(1000);
  d_right=ultrasonic.ping_cm();
  delay(500);
  Serial.println(d_right);
  if(d_left<d_right)
  right();
  else left();
      
    } else STOP();
  }
}
void forward()
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  digitalWrite(spd1, HIGH);
  digitalWrite(spd2, HIGH);
}

void right()
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  digitalWrite(spd1, HIGH);
  digitalWrite(spd2, HIGH);
}
void left()
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, HIGH);
  digitalWrite(spd1, HIGH);
  digitalWrite(spd2, HIGH);
}
void backward()
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, HIGH);
  digitalWrite (motor2f, LOW);
  digitalWrite(spd1, HIGH);
  digitalWrite(spd2, HIGH);
}
void STOP()
{
  digitalWrite (motor1b, LOW);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, LOW);
  digitalWrite(spd1, HIGH);
  digitalWrite(spd2, HIGH);
}

long USReadings()
{
  digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  digitalWrite(5,LOW);
  duration = pulseIn(2,HIGH);
  distance= (duration/2)*0.034 ; 
  return distance ;
}


