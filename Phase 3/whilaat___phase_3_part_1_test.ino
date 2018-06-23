
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

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
#define spd1 7 // MOTOR ELSHEMAL kan 9
#define spd2 6  // motor elyemen kan 6

//betoo3 phase 3
float m,data2;
float X1,Y1,X2,Y2;


int FORWARD( )
{      analogWrite (spd1,90);
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
{      analogWrite (spd1,90);
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
   
 float get_headingX() {
  // Get a new sensor event 
  sensors_event_t event; 
  mag.getEvent(&event);
  // Calculate headingX based on magnetic intensity in X & Y axis
 float  headingX = event.magnetic.x ;
  return headingX;
}


 float get_headingY() {
  // Get a new sensor event 
  sensors_event_t event; 
  mag.getEvent(&event);
  // Calculate headingY based on magnetic intensity in X & Y axis
   float headingY = event.magnetic.y ;
  return headingY;
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
Serial.println("HMC5883 Magnetometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
}


void loop(void) 
{
if (Serial.available() > 0)
{ 
   data = Serial.read();
 if(data=='A'){
   Serial.println("Accurate movement mode is on");
   Serial.println("Please enter forward or backward");
   delay(5000);
   data2 = Serial.read();
   if(data2=='F')
   {
   Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.read();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   X1 = get_headingX();
   Y1 = get_headingY(); 
   do{
       FORWARD();
       //delay((m/36));
       X2 = get_headingX();
       if(X2>X1)
       {
        do{
            LEFT();
            X2=get_headingX();
          }while(X2!=X1);
       }

        if(X2<X1)
       {
        do{
            RIGHT();
            X2=get_headingX();
          }while(X2!=X1);
       }
       Y2 = get_headingY();
     }
   while( Y2>Y1 && Y2!=Y1+m );
}
 if(data2=='B')
 {
  Serial.println("Please enter distance in cm");
   delay(10000);              
   m = Serial.read();
   Serial.println("the distance enetered is ");
   Serial.println(m);
   X1 = get_headingX();
   Y1 = get_headingY(); 
 do{
       BACKWARD();
       //delay((m/36));
       X2 = get_headingX();
       if(X2>X1)
       {
        do{
            LEFT();
            X2=get_headingX();
          }while(X2!=X1);
       }

        if(X2<X1)
       {
        do{
            RIGHT();
            X2=get_headingX();
          }while(X2!=X1);
       }
       Y2 = get_headingY();
     }
   while( Y2<Y1 && Y2!=Y1-m );
}
 }
      
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

