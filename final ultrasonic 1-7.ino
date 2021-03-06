#include<NewPing.h>
const int trigger = 5;
const int echo = 2;
NewPing ultrasonic(trigger, echo);
char data = 0;
int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
int spd1 = 9;
int spd2 = 6;
long duration;
long distance;
char data3=0;
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



distance = USReadings();
Serial.print("\nDistance: ");
Serial.println(distance);

if (distance <= 30)
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
        forward();                
        break;

      case 'B' :
        Serial.println("\nbackward");
        backward();
        break;

      case 'R' :
        Serial.println("\nright");
        right();
        break;

      case 'L' :
        Serial.println("\nleft");
        left();
        break;

      default:
        Serial.println("\nstop");
        STOP();
        break;
      }
}



/// obstacle avoidance system
 if (distance <= 30)
  {
  right();
  Serial.println("\nrotate right"); 
  delay(500); // equal to ~20°
  data = 'F';
  }
else if(data3=='T')
{
  Serial.println("\nLINE TRACKER MODE IS ON");
  while(data3=='T')
{  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     //stop //0 white
  {  
   
    Serial.println("\ndata3= ");
    Serial.println(data3);
    Serial.println("\nSTOP");
    STOP();
   data3=Serial.read(); 
   if(data3!='T')
   break; 
   
    Serial.println("STOP");
    STOP();
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
//    {  analogWrite (spd1,64);
//    analogWrite (spd2,64);
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
//     
  }
   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move  RIGHT  with slight angle Edite
    {
       RIGHT ( );
    
    
  }
    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Forward with full speed Edited
  {
      FORWARD( );
 
    }
     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Forward with full speed Edited
  {
      FORWARD( );
 
    }
    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Right with greater angle Edited
   {   
    RIGHTHIGH ( );
  }
  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Left with slight angle edited
  {
    
     LEFT();
    
    
  }

  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move left with greater angle edited
  {
    
     LEFTHIGH();
  }

   while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // forward
  {     STOP ();
     
  }

}
}
  else if (data3=='A')
{
  
    Serial.println("\nAccurate Mode Is On");
   
   
  
  
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


