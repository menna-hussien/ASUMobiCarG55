#include <RedBot.h>

RedBotSensor left_sen = RedBotSensor(A3);   
RedBotSensor center_sen = RedBotSensor(A4); 
RedBotSensor right_sen = RedBotSensor(A5);  
//data_sheet
// constants that are used in the code. lineStandard is the level to detect 
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed
//motor A
#define spd1 9
#define motor1f 10
#define motor1b 11
//motor b
#define spd2 6
#define motor2f 12
#define motor2b 13
int lineStandard = 500;



void setup()
{ pinMode(motor1f, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
  Serial.begin(9600);
  Serial.println("IR Sensor Readings:: ");
  delay(1000);
}

void loop()
{
  Serial.print(left_sen.read());
  Serial.print("\t");  
  Serial.print(center_sen.read());
  Serial.print("\t"); 
  Serial.print(right_sen.read());
  Serial.println();

//data_sheet
  // if on the line drive left and right at the same speed (left is CCW / right is CW)
  if(center_sen.read() > lineStandard)
  {//right
   right();
  }
  //data_sheet
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right_sen.read() > lineStandard)
  {//left
  left();
  }
  //data_sheet
  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left_sen.read() > lineStandard)
  {//right
  right();
  }
  //data_sheet
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left_sen.read() > lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    //stop
    Stop ();
  }
  else
  {
  //any dir
    forward();
  }
  delay(0);  // add a delay to decrease sensitivity.
}

void right() {
  analogWrite(spd1,100);
  analogWrite(spd2,100);
  digitalWrite(motor1f, LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
}
void Stop () {
  analogWrite(spd1, 0);
  analogWrite(spd2, 0);
  digitalWrite(motor1f, LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, LOW);
}
void left() {
  analogWrite(spd1, 100);
  analogWrite(spd2, 100);
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, LOW);
}
void forward() {
  analogWrite(spd1, 100);
  analogWrite(spd2, 100);
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
}
void back(){

   analogWrite(spd1, 255);
  analogWrite(spd2, 255);
  digitalWrite(motor1f, LOW);
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
}
