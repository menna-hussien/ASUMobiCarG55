
int FORWARD ( );
int BACKWARD ( );
int RIGHT ( );
int LEFT ( );
int HALFSPEED ();
int QUARTERSPEED();
void TOTALSPEED ();
int LEFTHIGH();
int RIGHTHIGH ( );
int STOP ();
char data = 0;
int motor1f =13;
int motor1b=12;
int motor2f=11;
int motor2b =10;

//dah ell fe eh sensor aslan
int LS=24;           
int CS=23;
int RS=22;
#define spd2 6  // MOTOR_A elyemen kan 6
#define spd1 7 // MOTOR_B ELSHEMAL kan 7


const byte MOTOR_A = 3;  // Motor 2 Interrupt Pin - INT 1 - Right Motor
const byte MOTOR_B = 2;  // Motor 1 Interrupt Pin - INT 0 - Left Motor

// Constant for steps in disk
const float stepcount = 20.00;  // 20 Slots in disk

// Constant for wheel diameter
const float wheeldiameter = 66.10; // Wheel diameter in millimeters

// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;

//m for distance entered by the user in phase 3
float m =0.0;
//data2 is for direction entered in phase 3
char data2=0;

int FORWARD( )
{    analogWrite (spd1,90);
     analogWrite (spd2,90);
     digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);
}
int BACKWARD( )
{  
     digitalWrite (motor1b,HIGH);
     digitalWrite (motor1f,LOW);
     digitalWrite (motor2b,HIGH);
     digitalWrite (motor2f,LOW);
     
}
int RIGHT ( )
{    analogWrite (spd1,90);
     analogWrite (spd2,90);        //128
     digitalWrite (motor2b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor1b,HIGH);     
     digitalWrite (motor1f,LOW);
}

int RIGHTHIGH ( )           //greater
{     

     analogWrite (spd1,90);      //255
     analogWrite (spd2,90);
     digitalWrite (motor2b,LOW); 
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor1b,HIGH);
     digitalWrite (motor1f,LOW);
}

int LEFT()
{
    analogWrite (spd1,90);        //128
    analogWrite (spd2,90);      //255
    digitalWrite (motor2b,HIGH);
    digitalWrite (motor2f,LOW);     
    digitalWrite (motor1b,LOW);
    digitalWrite (motor1f,HIGH);  
}

int LEFTHIGH(){                     
     analogWrite (spd1,90);          //
     analogWrite (spd2,90);       //255
     digitalWrite (motor2b,HIGH);
     digitalWrite (motor2f,LOW);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor1f,HIGH);  
  }
int STOP () 
   {
     analogWrite (spd1,0);
     analogWrite (spd2,0);
     digitalWrite (motor1f,LOW);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,LOW);
     digitalWrite (motor2b,LOW);
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
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = (int) f_result; // Convert to an integer (note this is NOT rounded)
 
  return result;  // End and return result
}
int angle_steps ( int angle) {
int result_angle;
float l_arc = 2*3.14*r*angle/360;
 float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float a_result = l_arc / cm_step;  // Calculate result as a float
  result_angle = (int) a_result; // Convert to an integer (note this is NOT rounded)
 
  return result_angle;  // End and return result

}

// Function to Move Forward in phase 3
void MoveForward(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero

     //Set Motor to move Forward
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
   
     //Set Motor to move Backward
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



void setup(void) {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (motor1f,OUTPUT);
pinMode (motor1b,OUTPUT);
pinMode (motor2f,OUTPUT);
pinMode (motor2b,OUTPUT);
pinMode (spd1, OUTPUT);
pinMode (spd2,OUTPUT);
pinMode(LS, INPUT);
pinMode(CS, INPUT); 
pinMode(RS, INPUT);

// Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  // Increase counter B when speed sensor pin goes High
  
}


void loop(void) 
{
if (Serial.available() > 0)
{ 
   data = Serial.read();
 if(data=='A'){
   Serial.println("Accurate movement mode is on");
   Serial.println("Please enter forward (F) or backward(B) ");
   delay(5000);
   data2 = Serial.read();
   if(data2=='F')
   {
   Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.read();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   MoveForward(CMtoSteps(m), 90);  // Forward distance(m) a metre at 90 speed  
   }

 if(data2=='B')
 {
   Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.read();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   MoveReverse(CMtoSteps(m), 90);  // Reverse distance(m) steps at 90 speed
 }
   data2=0;    //Reset the bluetooth received data in phase 3 
 }
   data=0;    //Reset the bluetooth received data for all phases
} 
} 


//void loop() {
// //if (Serial.available() > 0)
//  //{ 
//    //Serial.println("line follower mode is on");
//
//   // data = Serial.read();
////if(data=='U'){
//  
//  while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     //stop //0 white
//  {  
//    Serial.println("STOP");
//    STOP();
////    analogWrite (spd1,64);
////    analogWrite (spd2,64);        //128
////
////    digitalWrite (motor2b,LOW);
////    digitalWrite (motor2f,HIGH);
////    digitalWrite (motor1b,HIGH);     
////    digitalWrite (motor1f,LOW);
////
////    if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)
////     FORWARD();
////    else if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)
////    {  analogWrite (spd1,64);
////    analogWrite (spd2,64);
////     digitalWrite (motor2b,HIGH);
////        digitalWrite (motor2f,LOW);     
////     digitalWrite (motor1b,LOW);
////      digitalWrite (motor1f,HIGH); 
////    }
////   else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)
////   {   analogWrite (spd1,64);
////    analogWrite (spd2,64);        //128
////
////    digitalWrite (motor2b,LOW);
////    digitalWrite (motor2f,HIGH);
////    digitalWrite (motor1b,HIGH);     
////    digitalWrite (motor1f,LOW);
////   }
////  else STOP();
////     
//  }
//   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move  RIGHT  with slight angle Edite
//    {
//       RIGHT ( );
//    
//    
//  }
//    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Forward with full speed Edited
//  {
//      FORWARD( );
// 
//    }
//     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Forward with full speed Edited
//  {
//      FORWARD( );
// 
//    }
//    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Right with greater angle Edited
//   {   
//    RIGHTHIGH ( );
//  }
//  
// while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Left with slight angle edited
//  {
//    
//     LEFT();
//    
//    
//  }
//
//  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move left with greater angle edited
//  {
//    
//     LEFTHIGH();
//  }
//
//   while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // forward
//  {     FORWARD ();
//     
//  }
//
//
//  //delay(10); 
//  //data =0;
//}
//  
////}

