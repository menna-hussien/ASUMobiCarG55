#include<Servo.h>
#include<NewPing.h>
const int trigger = 5;
const int echo = 2;
NewPing ultrasonic(trigger, echo);
Servo myservo;
float d_forward,d_left,d_right;
char data = 0;
int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
long duration;
long distance;
char data3=0;
int flag=0;
#define spd2 6  // MOTOR_A elyemen kan 6
#define spd1 7 // MOTOR_B ELSHEMAL kan 7

int delayC= 10000;
int LS=24;            //dah ell fe eh sensor aslan
int CS=23;
int RS=22;



const byte MOTOR_A = 19;  // Motor 2 Interrupt Pin - INT 1 - Right Motor
const byte MOTOR_B = 18;  // Motor 1 Interrupt Pin - INT 0 - Left Motor

// Constant for steps in disk
const float stepcount = 20.00;  // 20 Slots in disk

// Constant for wheel diameter
const float wheeldiameter = 6.40; // Wheel diameter in millimeters

// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;

//m for distance entered by the user in phase 3
float m = 0.0;
//data2 is for direction entered in phase 3
char data2=0;



//sensor phases
/*Smoke Sensor Circuit Built with an Arduino Board*/

const int sensorPin= A0;
const int buzzerPin= A1;
int smoke_level;

//light follower code
int sensorPinRight =A2; // Right sensor pin
int sensorPinCenter =A3; // Center sensor pin
int sensorPinLeft = A4; // Left sensor pin

int lightReadingRight;
int lightToleranceRight = 1000; // Sensor reading needed to trigger right turn

int lightReadingCenter;
int lightToleranceCenter = 1000; // Sensor reading needed to trigger forward movement

int lightReadingLeft;
int lightToleranceLeft = 1000; // Sensor reading needed to trigger left turn

int readingDelay = 100; // Delay between readings

//RAIN SENSOR
int BLUE_LED = 36;

//Ultrasonic LED
int ORANGE_LED= 37;

//temperature sensor

int input_temp = A6; 
int readingtemp ; 
float temp;

//temperature sensor
int RED_LED= 38; 




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (motor1f, OUTPUT);
  pinMode (motor1b, OUTPUT);
  pinMode (motor2f, OUTPUT);
  pinMode (motor2b, OUTPUT);
  pinMode (spd1, OUTPUT);
  pinMode (spd2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  pinMode(sensorPin, INPUT);//the smoke sensor will be an input to the arduino
pinMode(buzzerPin, OUTPUT);//the buzzer serves an output in the circuit
pinMode(BLUE_LED, OUTPUT);
pinMode(ORANGE_LED, OUTPUT);
pinMode(input_temp , INPUT) ;
pinMode(RED_LED, OUTPUT);

//SERVO SENSOR
myservo.attach(9);
myservo.write(90);
myservo.writeMicroseconds(1500);

  
}
void loop() {

 // Attach the Interrupts to their ISR's
//  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  // Increase counter A when speed sensor pin goes High
//  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  // Increase counter B when speed sensor pin goes High

Serial.println("\nPlease enter a mode");

delay(10000);

if(Serial.available() > 0)
{ 
//Serial.print("Please enter a mode");
data3 = Serial.read();

//Start of phase 1
if(data3=='U')
{
  while(data3=='U')
  {
distance = USReadings();
Serial.println("\nDistance: ");
Serial.println(distance);

if (distance <= 20)
  {
    data= 0;
  }
  

if (Serial.available() > 0)
{
    data = Serial.read();
    }

else 
{

    switch (data)
    {
      case 'F' :
        Serial.println("\nforward");
        FORWARD();                
        break;

      case 'B' :
        Serial.println("\nbackward");
        BACKWARD();
        break;

      case 'R' :
        Serial.println("\nright");
        RIGHT();
        break;

      case 'L' :
        Serial.println("\nleft");
        LEFT();
        break;
      case 'T':
         data3='T';
         STOP();
         Serial.println("YOU ENTERED Line Tracker MODE");
         break;
      case 'A':
         data3='A';
         STOP();
         Serial.println("YOU ENTERED ACCURATE MODE");
         break;

      default:
        Serial.println("\nstop");
        STOP();
        break;
      }
}

 if(distance <=60 && distance >20)
 {
   digitalWrite(ORANGE_LED,HIGH);
   delay(700);
   digitalWrite(ORANGE_LED,LOW);
   delay(700);
  } 

/// obstacle avoidance system
 if (distance <= 20)
  { 
    
   digitalWrite(ORANGE_LED,HIGH);
   delay(1000);
   digitalWrite(ORANGE_LED,LOW);
  RIGHT();
  Serial.println("\nrotate right"); 
  delay(500); // equal to ~20°
  data = 'F';
  }

  }
   
}

// Start of phase 2
else if(data3=='T')
{
  Serial.println("\nLINE TRACKER MODE IS ON");
  
    
while(data3=='T')
{  

   while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0 && data3=='T')     //stop //0 white
  { 
    RIGHT1(100);
  delay(70);
    
//    Serial.println("\ndata3= ");
//    Serial.println(data3);
//    Serial.println("\nSTOP");
    
 


  
  
   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0 && data3=='T')     // Move  RIGHT  with slight angle Edite
    {
      Serial.println("\nright");
       RIGHT1(100);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }
    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD1(70);
       data3=Serial.read(); 
   if(data3!='T')
   break; 

    }
     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD1(70);
       data3=Serial.read(); 
   if(data3!='T')
   break; 
 
    }
    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Right with greater angle Edited
   {   
    Serial.println("\nrightHIGH");
    RIGHT1 (120);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
  }
  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Left with slight angle edited
  {
    Serial.println("\nleft");
     LEFT1(100);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }

  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1 && data3=='T')     // Move left with greater angle edited
  {
    Serial.println("\nleftHIGH");
     LEFT1(120);
      data3=Serial.read(); 
   if(data3!='T')
   break; 
  }  
  
  
  
  
    
   data3=Serial.read(); 
   if(data3!='T')
    break;
//  
//    analogWrite (spd1,64);
//    analogWrite (spd2,64);        //128
//
//    digitalWrite (motor2b,LOW);
//    digitalWrite (motor2f,HIGH);
//    digitalWrite (motor1b,HIGH);     
//    digitalWrite (motor1f,LOW);
//
//    if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)
//     FORWARD();
//    else if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)
//        {  analogWrite (spd1,64);
//  analogWrite (spd2,64);
//     digitalWrite (motor2b,HIGH);
//        digitalWrite (motor2f,LOW);     
//     digitalWrite (motor1b,LOW);
//      digitalWrite (motor1f,HIGH); 
//    }
//   else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)
//   {   analogWrite (spd1,64);
//    analogWrite (spd2,64);        //128
//
//    digitalWrite (motor2b,LOW);
//    digitalWrite (motor2f,HIGH);
//    digitalWrite (motor1b,HIGH);     
//    digitalWrite (motor1f,LOW);
//   }
//  else STOP();
     
  }
   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0 && data3=='T')     // Move  RIGHT  with slight angle Edite
    {
      Serial.println("\nright");
       RIGHT1 (100 );
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }
    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD1(64);
       data3=Serial.read(); 
   if(data3!='T')
   break; 

    }
     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD1(64);
       data3=Serial.read(); 
   if(data3!='T')
   break; 
 
    }
    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Right with greater angle Edited
   {   
    Serial.println("\nrightHIGH");
    RIGHT1 (64);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
  }
  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Left with slight angle edited
  {
    Serial.println("\nleft");
     LEFT1(100);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }

  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1 && data3=='T')     // Move left with greater angle edited
  {
    Serial.println("\nleftHIGH");
     LEFT1(120);
      data3=Serial.read(); 
   if(data3!='T')
   break; 
  }

   while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1 && data3=='T')     // forward
  {     Serial.println("\nstop");
  FORWARD1(70);
   data3=Serial.read(); 
   if(data3!='T')
   break; 
     
  }

  
  if(data3=='U')
  {
    Serial.println("\nyou entered U");
    data3='U';
    break;
    }
    
 else if(data3=='A')
  { 
    Serial.println("\nyou entered A");
    data3='A';
    break;
    }
 else data3='T';
}  
}

// Start of phase 3
else if (data3=='A')
{
   Serial.println("\nAccurate Mode Is On");
   
  while(data3=='A'){
    // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  // Increase counter B when speed sensor pin goes High
  Serial.println("Please enter forward (F) or backward(B) or Right(R) or left(L) or Shapes(C) ");
   delay(5000);
   data2 = Serial.read();
   if(data2=='F')
   {
   Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.parseInt();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   MoveForward(CMtoSteps(m)*5, 100);  // Forward distance(m) a metre at 90 speed
   Serial.println(CMtoSteps(m));  
   }

 else if(data2=='B')
 {
  Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.parseInt();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   MoveReverse(CMtoSteps(m)*5, 100);  // Reverse distance(m) steps at 90 speed
}
else if (data2=='R')
{  
   Serial.println("Please enter angle");
   delay(10000);
   m=Serial.parseInt();
   Serial.println("the angle enetered is ");
   Serial.println(m);
   MoveRight(angle_steps(m) , 100);
  }
  else if (data2=='L')
{  
   Serial.println("Please enter angle");
   delay(10000);
   m=Serial.parseInt();
   Serial.println("the angle enetered is ");
   Serial.println(m);
   MoveLeft(angle_steps(m) , 100);
  }
 
else if(data2=='C')
{ 
  Serial.println("\nThe shapes are ready to be drawn");

  Serial.println("\nInfinity starts ...");
  infinity();
  Serial.println("\nInfinity ends ...");
  STOP();
  delay(25000);
  
  Serial.println("\nRectangle starts ...");
  Rectangle();
  Serial.println("\nRectangle ends ...");
  STOP();  
  delay(25000);
  
  Serial.println("\nCircle starts ...");
  Circle();
  Serial.println("\nCircle ends ...");
  STOP(); 
  break;
  }

 else if(data2=='T'){
  Serial.println("\nyou entered T");
  data3='T';
  break;
  } 
else if (data2=='U'){
 Serial.println("\nyou entered U");
 data3='U';
 break;
}
else {
  Serial.println("\nNot a valid option");
  data3='A';
  }
  
 }
}  
  
else if(data3=='B')
{
  //sensors

while(data3=='B'){  
//SMOKE LEVEL SENSOR
  
smoke_level= analogRead(sensorPin); //arduino reads the value from the smoke sensor
Serial.println(smoke_level);//prints just for debugging purposes, to see what values the sensor is picking up
if(smoke_level > 200){ //if smoke level is greater than 200, the buzzer will go off
digitalWrite(buzzerPin, HIGH);
}
else{
digitalWrite(buzzerPin, LOW);
}


//light follower sensor

// Take reading from right sensor
lightReadingRight = analogRead(sensorPinRight);
Serial.print("Right Sensor Reading :");
Serial.println(lightReadingRight);

// Take reading from center sensor
lightReadingCenter = analogRead(sensorPinCenter);
Serial.println("Center Sensor Reading :");
Serial.println(lightReadingCenter);

// Take reading from left sensor
lightReadingLeft = analogRead(sensorPinLeft);
Serial.print("Left Sensor Reading :");
Serial.println(lightReadingLeft);


// Move forward if enought light is detected from center sensor
while (lightReadingCenter > lightToleranceCenter)
{ 
  FORWARD();
  digitalWrite(BLUE_LED, LOW);
  Serial.println("da5l CENTER:");
  lightReadingCenter = analogRead(sensorPinCenter);
  //STOP
  STOP();
}

// Turn right if enough light is detected from right sensor
while (lightReadingRight > lightToleranceRight)
{
   RIGHT();
  digitalWrite(BLUE_LED, LOW);
  Serial.println("da5l RIGHT:");
  lightReadingRight= analogRead(sensorPinRight);
  //STOP
  STOP();
}


// Turn left if enough light is detected from left sensor
while (lightReadingLeft > lightToleranceLeft)
{
  LEFT();
  digitalWrite(BLUE_LED, LOW);
  Serial.println("da5l LEFT:");
lightReadingLeft = analogRead(sensorPinLeft);
  //STOP
  STOP();
}


//RAIN DROP SENSOR
// read the input on analog pin A5:

  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue > 50){
  digitalWrite(BLUE_LED, HIGH);
  }
  else digitalWrite(BLUE_LED, LOW);



//TEMPERATURE SENSOR

 readingtemp  = analogRead(input_temp);
  temp = (readingtemp * (5.0/1024))*100 - 2.5 ; 
  Serial.println(temp);
  //Serial.println(readingtemp);
  delay(500) ;
  if(temp>25){
    digitalWrite(RED_LED, LOW);
    }
  else digitalWrite(RED_LED, LOW); 
 //data3=0; 

data3=Serial.read();

  if(data3=='U')
  {
    Serial.println("\nyou entered U");
    data3='U';
    break;
    }
    
 else if(data3=='A')
  { 
    Serial.println("\nyou entered A");
    data3='A';
    break;
    }
     else if(data3=='T')
  { 
    Serial.println("\nyou entered A");
    data3='A';
    break;
    }
 else data3='B';
  
}  
  
 }

else if(data3=='E')  //PHASE ONE ADDED SERVO CODE
{
  while(data3=='E')
  {
distance = USReadings();
Serial.println("\nDistance: ");
Serial.println(distance);

if (distance <= 20)
  {
    data= 0;
  }
  

if (Serial.available() > 0)
{
    data = Serial.read();
    }

else 
{

    switch (data)
    {
      case 'F' :
        Serial.println("\nforward");
        FORWARD();                
        break;

      case 'B' :
        Serial.println("\nbackward");
        BACKWARD();
        break;

      case 'R' :
        Serial.println("\nright");
        RIGHT();
        break;

      case 'L' :
        Serial.println("\nleft");
        LEFT();
        break;
      case 'T':
         data3='T';
         STOP();
         Serial.println("YOU ENTERED Line Tracker MODE");
         break;
      case 'A':
         data3='A';
         STOP();
         Serial.println("YOU ENTERED ACCURATE MODE");
         break;

      default:
        Serial.println("\nstop");
        STOP();
        break;
      }
}

 if(distance <=60 && distance >30)
 {
   digitalWrite(ORANGE_LED,HIGH);
   delay(700);
   digitalWrite(ORANGE_LED,LOW);
   delay(700);
  } 

/// obstacle avoidance system
 if (distance <= 30)
  { 
    //LEDS OR BUZZER
   digitalWrite(ORANGE_LED,HIGH);
   delay(1000);
   digitalWrite(ORANGE_LED,LOW);
//  RIGHT();
//  Serial.println("\nrotate right"); 
//  delay(500); // equal to ~20°
//  data = 'F';

//SERVOOOOOOOO
Serial.println("d<30");
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
 {
  RIGHT();
  Serial.println("\nrotate right"); 
  delay(500); // equal to ~20°
  data = 'F';

 }
  else {
    LEFT();
  Serial.println("\nrotate left"); 
  delay(500); // equal to ~20°
  data = 'F';

  }



  
  }

  }
   
}









   
 //NOTHING OF PHASES
  else 
  { 
    Serial.println("\nSORRY,NOT AVAILABLE MODE");
    Serial.println("\nPlease enter (U,T,A)");
    delay(10000);
    STOP();
  }


  
}

  
}
void FORWARD()
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  analogWrite(spd1,90);
  analogWrite(spd2,90);
}
void LEFT()
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  analogWrite(spd1, 90);
  analogWrite(spd2,90);
  
}

void RIGHT()
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, HIGH);
  analogWrite(spd1, 90);
  analogWrite(spd2, 90);
}

void BACKWARD()
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, HIGH);
  digitalWrite (motor2f, LOW);
  analogWrite(spd1, 90);
  analogWrite(spd2, 90);
}
void STOP()
{
  digitalWrite (motor1b, LOW);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, LOW);
  digitalWrite(spd1, 0);
  digitalWrite(spd2, 0);
}

void FORWARD1(int  mspeed)
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  analogWrite(spd1, mspeed);
  analogWrite(spd2,  mspeed);
}


void LEFT1(int  mspeed)
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  analogWrite(spd1,  mspeed);
  analogWrite(spd2, mspeed);
  
}
void RIGHT1(int mspeed)
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, HIGH);
  analogWrite(spd1,  mspeed);
  analogWrite(spd2,  mspeed);
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


// Interrupt Service Routines

// Motor A pulse count ISR
void ISR_countA()  
{
  counter_A++;  // increment Motor A counter value
} 

// Motor B pulse count ISR
void ISR_countB()  
{
  counter_B++;  // increment Motor B counter value
}


// Function to convert from centimeters to steps
int CMtoSteps(float cm) {

  int result;  // Final calculation result
  float circumference = (wheeldiameter * 3.14); // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = (int) f_result; // Convert to an integer (note this is NOT rounded)
 
  return result;  // End and return result
}





int angle_steps ( int angle) {
int result_angle;
float l_arc = 2*3.14*12*angle/360;
 float circumference = (wheeldiameter * 3.14)/10 ; // Calculate wheel circumference in cm shayleen el 10
  float cm_step = circumference / stepcount;  // CM per Step
  
  float a_result = l_arc / cm_step;  // Calculate result as a float
  result_angle = (int) a_result; // Convert to an integer (note this is NOT rounded)
 
  return result_angle;  // End and return result

}

// Function to Move right in phase 3
void MoveRight(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero
   digitalWrite (motor2b,LOW);    //10
     digitalWrite (motor2f,HIGH); //11
     digitalWrite (motor1b,HIGH);  //12 motor A yemeen el robot  
     digitalWrite (motor1f,LOW); //13  motor A uemeen el robot
 
     
   // Go right until step value is reached
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(spd2, mspeed);
    } else {
    analogWrite(spd2, 0);
    }
    if (steps > counter_B) {
    analogWrite(spd1, mspeed);
    } else {
    analogWrite(spd1, 0);
    }
   }
    
  // Stop when done
  analogWrite(spd2, 0);
  analogWrite(spd1, 0);
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero 

}







// Function to Move Forward in phase 3
void MoveForward(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero
   
     digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);
     
   // Go forward until step value is reached
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(spd2, mspeed);
    } else {
    analogWrite(spd2, 0);
    }
    if (steps > counter_B) {
    analogWrite(spd1, mspeed);
    } else {
    analogWrite(spd1, 0);
    }
   }
    
  // Stop when done
  analogWrite(spd2, 0);
  analogWrite(spd1, 0);
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero 

}

// Function to Move in Reverse in phase 3
void MoveReverse(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero
   
     digitalWrite (motor1b,HIGH);
     digitalWrite (motor1f,LOW);
     digitalWrite (motor2b,HIGH);
     digitalWrite (motor2f,LOW);
   
   // Go in reverse until step value is reached
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(spd2, mspeed);
    } else {
    analogWrite(spd2, 0);
    }
    if (steps > counter_B) {
    analogWrite(spd1, mspeed);
    } else {
    analogWrite(spd1, 0);
    }
    }
    
  // Stop when done
  analogWrite(spd2, 0);
  analogWrite(spd1, 0);
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero 

}
  void MoveLeft(int steps, int mspeed) 
{
     counter_A = 0;  //  reset counter A to zero
     counter_B = 0;  //  reset counter B to zero
     digitalWrite (motor2b,HIGH);  //10
     digitalWrite (motor2f,LOW); //11
     digitalWrite (motor1b,LOW);  //12 motor A yemeen el robot  
     digitalWrite (motor1f,HIGH); //13  motor A uemeen el robot

     
   // Go left until step value is reached
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(spd2, mspeed);
    } else {
    analogWrite(spd2, 0);
    }
    if (steps > counter_B) {
    analogWrite(spd1, mspeed);
    } else {
    analogWrite(spd1, 0);
    }
   }
   
   // Stop when done
   analogWrite(spd2, 0);
   analogWrite(spd1, 0);
   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero
}

void Circle(){
  int i;
  int j;
//  Serial.println("Please enter circle delay: ");
//  bool delayExist = false;
//  while(!delayExist)
//     {
//      if (Serial.available() > 0)
//      {
//        delayC = atoi(Serial.readString().c_str()); // to convert el string to integer 
//      
//       delayExist=true; 
//      } 
//     }
//
//   Serial.println(delayC);//DELAY 170
     
//for(j=0;j<4;j++){
  for(i=0;i<200;i++){
//    
//     MoveForward(CMtoSteps(25.0)*5,64);
//     LEFT();
digitalWrite(motor1f, HIGH);
 digitalWrite(motor1b, LOW);
 digitalWrite(motor2f, HIGH);
 digitalWrite(motor2b, LOW);
 analogWrite(spd1,90);
 analogWrite(spd2, 128);     
   //  delay(delayC);
     //Serial.println(delayC);
     
}
//MoveRight(angle_steps(50),64);

  //}
}



void infinity(){
  int i;
  for(i=0;i<25;i++){
     MoveForward(CMtoSteps(25.0)*5,64);
     LEFT();
     delay(300);
     
  }
  
    
//    FORWARD3();
//    delay(1000);
//    STOP();

     for(i=0;i<25;i++){
     MoveForward(CMtoSteps(25.0)*5,64);
     RIGHT();
     delay(300);
  }

//   FORWARD3();
//    delay(1000);
//    STOP();
  
  }


void Rectangle(){
  
int i=0;
int j=0;
for(j=0;j<4;j++)
{
for (i=0 ; i<2; i++)
{
 MoveForward(CMtoSteps(100.0)*5,64);
  RIGHT();
   delay(10);
 MoveForward(CMtoSteps(100.0)*5,64);
  
//digitalWrite(motor1f, HIGH);
// digitalWrite(motor1b, LOW);
// digitalWrite(motor2f, HIGH);
// digitalWrite(motor2b, LOW);
// analogWrite(spd1,100);
// analogWrite(spd2, 100);
//
// delay (750);   // right angle for rectangle 
//
//digitalWrite(motor1f, HIGH);
//digitalWrite(motor1b, LOW);
// digitalWrite(motor2f, LOW);
// digitalWrite(motor2b, HIGH);
//   analogWrite(spd1,100);
//  analogWrite(spd2, 100);
// delay(60);



}//
  MoveRight(angle_steps(90),  90) ;
//  digitalWrite(motor1f, HIGH);
//  digitalWrite(motor1b, LOW);
//  digitalWrite(motor2f, LOW);
//  digitalWrite(motor2b, HIGH);
//  analogWrite(spd1,100);
//  analogWrite(spd2, 100);
//  delay (450);
 
} } 



  
