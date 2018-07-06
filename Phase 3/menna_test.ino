#include<NewPing.h>
const int trigger = 5;
const int echo = 2;
NewPing ultrasonic(trigger, echo);
char data = 0;
int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
long duration;
long distance;
char data3=0;
#define spd2 6  // MOTOR_A elyemen kan 6
#define spd1 7 // MOTOR_B ELSHEMAL kan 7

int delayC= 10000;
int delayR= 10000;
int LS=22;            //dah ell fe eh sensor aslan
int CS=23;
int RS=24;



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
        FORWARD(90);                
        break;

      case 'B' :
        Serial.println("\nbackward");
        BACKWARD(90);
        break;

      case 'R' :
        Serial.println("\nright");
        RIGHT(90);
        break;

      case 'L' :
        Serial.println("\nleft");
        LEFT(90);
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



/// obstacle avoidance system
 if (distance <= 20)
  {
  RIGHT(90);
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
      Serial.println("\ndata3= ");
    Serial.println(data3);
    Serial.println("\nSTOP");
    STOP();
   data3=Serial.read(); 
   if(data3!='T')
   break; 


//  //IN ORDER NOT TO STOP
//    RIGHT(64);
//    delay(750);
//    Serial.println("\nTurned right in order not to stop ");
//    if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)
//     {
//      FORWARD(64);
//      break;
//     }
//    else if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)
//    {
//      LEFT(64);
//      break;
//    }
//   else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)
//   {  
//    RIGHT(64);
//    break;
//   }
//  else if( digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0){
//    LEFT(64);
//    delay(1000);
//    break;
//  }
//  else STOP();
  }
  
   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0 && data3=='T')     // Move  RIGHT  with slight angle Edite
    {
      Serial.println("\nright");
       RIGHT (64);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }
    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD(64);
       data3=Serial.read(); 
   if(data3!='T')
   break; 

    }
     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Forward with full speed Edited
  {
      Serial.println("\nforward");
      FORWARD(64);
       data3=Serial.read(); 
   if(data3!='T')
   break; 
 
    }
    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0 && data3=='T')     // Move Right with greater angle Edited
   {   
    Serial.println("\nright");
    RIGHT (64);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
  }
  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1 && data3=='T')     // Move Left with slight angle edited
  {
    Serial.println("\nleft");
     LEFT(64);
     data3=Serial.read(); 
   if(data3!='T')
   break; 
    
  }

  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1 && data3=='T')     // Move left with greater angle edited
  {
    Serial.println("\nleft");
     LEFT(64);
      data3=Serial.read(); 
   if(data3!='T')
   break; 
  }

   while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1 && data3=='T')     // forward
  {     Serial.println("\nforward");
    FORWARD(64);
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
   MoveForward(CMtoSteps(m)*5, 90);  // Forward distance(m) a metre at 90 speed
   Serial.println(CMtoSteps(m));  
   }

 else if(data2=='B')
 {
  Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.parseInt();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   MoveReverse(CMtoSteps(m)*5, 90);  // Reverse distance(m) steps at 90 speed
}
else if (data2=='R')
{  
   Serial.println("Please enter angle");
   delay(10000);
   m=Serial.parseInt();
   Serial.println("the angle enetered is ");
   Serial.println(m);
   MoveRight(angle_steps(0.75*m) , 128);
  }
  else if (data2=='L')
{  
   Serial.println("Please enter angle");
   delay(10000);
   m=Serial.parseInt();
   Serial.println("the angle enetered is ");
   Serial.println(m);
   MoveLeft(angle_steps(m)*0.5 , 128);
  }
 
else if(data2=='C')
{ 
  Serial.println("\nThe shapes are ready to be drawn");

   Serial.println("\nCircle starts ...");
   Circle();
   Serial.println("\nCircle ends ...");
   STOP(); 
  delay(25000);

  Serial.println("\nInfinity starts ...");
  infinity();
  Serial.println("\nInfinity ends ...");
  STOP();
  delay(25000);

//  Serial.println("\nRectangle starts ...");
//  Rectangle3();
//  Serial.println("\nRectangle ends ...");
//  STOP();  
//  delay(25000); 
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
  
  
 //NOTHING OF PHASES
  else 
  { 
    Serial.println("\nSORRY,NOT AVAILABLE MODE");
    Serial.println("\nPlease enter (U,T,A)");
    delay(10000);
    STOP();
  }


  
}  
 //data3=0; 
}
void FORWARD(int  mspeed)
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  analogWrite(spd1, mspeed);
  analogWrite(spd2,  mspeed);
}
void FORWARD3()
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  analogWrite(spd1,64);
  analogWrite(spd2, 64);
}

void LEFT(int  mspeed)
{
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  analogWrite(spd1,  mspeed);
  analogWrite(spd2, mspeed);
  
}
void RIGHT(int mspeed)
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, HIGH);
  analogWrite(spd1,  mspeed);
  analogWrite(spd2,  mspeed);
}

void RIGHT3()
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, LOW);
  digitalWrite (motor2f, HIGH);
  analogWrite(spd1, 128);
  analogWrite(spd2, 128);
}
void BACKWARD(int mspeed)
{
  digitalWrite (motor1b, HIGH);
  digitalWrite (motor1f, LOW);
  digitalWrite (motor2b, HIGH);
  digitalWrite (motor2f, LOW);
  analogWrite(spd1,  mspeed);
  analogWrite(spd2,  mspeed);
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
float l_arc = 2*PI*14*angle/360;
 float circumference = (wheeldiameter * PI)/10 ; // Calculate wheel circumference in cm shayleen el 10
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
  int itrC=1000;
 Serial.println("Please enter circle delay:Mostly 110 ");
  bool delayExist = false;
  while(!delayExist)
     {
      if (Serial.available() > 0)
      {
          
        delayC = atoi(Serial.readString().c_str()); // to convert el string to integer 
        Serial.println("Please enter circle iteration :Mostly 46 ");
        delay(1000);
        itrC = atoi(Serial.readString().c_str()); // to convert el string to integer 
       delayExist=true; 
       
      } 
     }

   Serial.println(delayC);
    Serial.println(itrC); 

  for(i=0;i<itrC;i++){
    
     MoveForward(CMtoSteps(22.0)*5,64);
     LEFT(90);
     
     delay(delayC);
     Serial.println(delayC);
     
}
  }



void infinity(){
  int i;
  int itrI1=1000;
  int itrI2=1000;
   Serial.println("Please enter infinity iteration 1 :Mostly 17 ");
  bool delayExist = false;
  while(!delayExist)
     {
      if (Serial.available() > 0)
      {
          
        itrI1 = atoi(Serial.readString().c_str()); // to convert el string to integer 
        Serial.println("Please enter iteration iteration 2 :Mostly 16 ");
        delay(1000);
        itrI2 = atoi(Serial.readString().c_str()); // to convert el string to integer 
       delayExist=true; 
       
      } 
     }
Serial.println(itrI1);
Serial.println(itrI2);
   
  for(i=0;i<itrI1;i++){
     MoveForward(CMtoSteps(25.0)*5,64);
     LEFT(90);
     delay(300);
     
  }
  
    
//    FORWARD3();
//    delay(1000);
//    STOP();

     for(i=0;i<itrI2;i++){
     MoveForward(CMtoSteps(25.0)*5,64);
     RIGHT(90);
     delay(300);
  }

//   FORWARD3();
//    delay(1000);
//    STOP();
  
  }


 

void Rectangle2(){
   
  int i;
  int j;
  Serial.println("Please enter Rectangle delay: Mostly 45 ");
  bool delayExist = false;
  while(!delayExist)
     {
      if (Serial.available() > 0)
      {
        delayR = atoi(Serial.readString().c_str()); // to convert el string to integer 
       delayExist=true; 
      } 
     }

   Serial.println(delayR);
     
for(j=0;j<4;j++){
  for(i=0;i<8;i++){
    
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR);
     Serial.println(delayR);
     
}
MoveLeft( angle_steps(90)*0.5,128);
//RIGHT(90);
//delay(950);

  }
}
  



 void Rectangle3() {
  int i;
  int delayAngle=1000;
  Serial.println("Please enter Rectangle delay: Mostly 45 ");
  bool delayExist = false;
  while(!delayExist)
     {
      if (Serial.available() > 0)
      {
        delayR = atoi(Serial.readString().c_str()); // to convert el string to integer
        Serial.println("Please enter Rectangle Angle delay: Mostly 960 ");
       delayAngle = atoi(Serial.readString().c_str()); // to convert el string to integer
       delay(2000);
        delayExist=true; 
      } 
     }

   Serial.println(delayR);

 //STEPS TO DRAW RECTANGLE
    for(i=0;i<4;i++){
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR);
     Serial.println(delayR);
    }
     
// MoveRight( angle_steps(0.75*90),128);
  RIGHT(90);
  delay(delayAngle);
  STOP();
  //delay(5000);
 
     for(i=0;i<4;i++){
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR+3);
     Serial.println(delayR);
    }

// MoveRight( angle_steps(0.75*90),128);
RIGHT(90);
  delay(delayAngle);
  STOP();
  delay(10000);

     for(i=0;i<8;i++){
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR);
     Serial.println(delayR);
    }

 //MoveRight( angle_steps(0.75*90),128);
  RIGHT(90);
  delay(delayAngle);
  STOP();
  delay(5000);
   for(i=0;i<4;i++){
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR);
     Serial.println(delayR);
    }

//MoveRight( angle_steps(0.75*90),128);
  RIGHT(90);
  delay(delayAngle);
  STOP();
  delay(5000);  
  for(i=0;i<4;i++){
     MoveForward(CMtoSteps(25.0)*5,90);
     LEFT(90);
     
     delay(delayR);
     Serial.println(delayR);
    }
    
 }
  
  


