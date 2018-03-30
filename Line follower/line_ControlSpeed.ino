int FORWARD ( );
int BACKWARD ( );
int RIGHT ( );
int LEFT ( );
int HALFSPEED ();
int QUARTERSPEED();
void TOTALSPEED ();
char data = 0;
int motor1f =13;
int motor1b=12;
int motor2f=11;
int motor2b =10;
int spd1 =9;  // MOTOR ELSHEMAL 
int spd2 =6;  // motor elyemen
int LS=4;            //dah ell fe eh sensor aslan
int CS=5;
int RS=3;
int FORWARD( )
{
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
{

      digitalWrite (motor1b,HIGH);
     digitalWrite (motor1f,LOW);
     digitalWrite (motor2b,LOW);
     digitalWrite (motor2f,HIGH);
     
}
int LEFT()
{

      digitalWrite (motor1b,LOW);
     digitalWrite (motor1f,HIGH);
     digitalWrite (motor2b,HIGH);
     digitalWrite (motor2f,LOW);
     
}

void setup() {
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
}



void loop() {

if(data==7){
  if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     // STOP
  {  
     analogWrite (spd1,0);
     analogWrite (spd2,0);
     digitalWrite (motor1f,LOW);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,LOW);
     digitalWrite (motor2b,LOW);
     
     
  }
   else if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Right with slight angle Edited
  {
    
       analogWrite (spd1,255);
     analogWrite (spd2,128);
    digitalWrite (motor1f,HIGH);
    delay(1);
     digitalWrite (motor1b,LOW);
     delay(1);
     digitalWrite (motor2f,HIGH);
     delay(1);
     digitalWrite (motor2b,LOW);
    delay(1);
    
  }
    else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Forward with full speed Edited
  {
    analogWrite (spd1,255);
     analogWrite (spd2,255);
    digitalWrite (motor1f,HIGH);
    delay(1);
     digitalWrite (motor1b,LOW);
     delay(1);
     digitalWrite (motor2f,HIGH);
     delay(1);
     digitalWrite (motor2b,LOW);
    delay(1);
    }
    else if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move Right with greater angle Edited
   {   analogWrite (spd1,255);
     analogWrite (spd2,64);
     digitalWrite (motor1f,HIGH);
    delay(1);
     digitalWrite (motor1b,LOW);
     delay(1);
     digitalWrite (motor2f,HIGH);
     delay(1);
     digitalWrite (motor2b,LOW);
    delay(1);
  }
  
  else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move Left with slight angle edited
  {
     analogWrite (spd1,128);
     analogWrite (spd2,255);
    digitalWrite (motor1f,HIGH);
    delay(1);
     digitalWrite (motor1b,LOW);
     delay(1);
     digitalWrite (motor2f,HIGH);
     delay(1);
     digitalWrite (motor2b,LOW);
    delay(1);
    
  }

  else if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move left with greater angle edited
  {
      analogWrite (spd1,64);
     analogWrite (spd2,255);
   digitalWrite (motor1f,HIGH);
    delay(1);
     digitalWrite (motor1b,LOW);
     delay(1);
     digitalWrite (motor2f,HIGH);
     delay(1);
     digitalWrite (motor2b,LOW);
    delay(1);
  }

   else if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // stop
  {       analogWrite (spd1,0);
     analogWrite (spd2,0);
    digitalWrite (motor1f,LOW);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,LOW);
     digitalWrite (motor2b,LOW);
     
  }

   else 
  {
     digitalWrite (12,LOW);
     digitalWrite (13,LOW);
     digitalWrite (10,LOW);
     digitalWrite (11,LOW);
     
  }
  data =0;
}
}

void TOTALSPEED ()
{

   analogWrite (spd1,255);
  analogWrite (spd2,255);
}
int HALFSPEED ()
{
  analogWrite (spd1,128);
  analogWrite (spd2,128);
}
int QUARTERSPEED()
{ analogWrite (spd1,64);
analogWrite (spd2,64);
}

