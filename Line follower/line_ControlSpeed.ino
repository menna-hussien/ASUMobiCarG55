
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

int LS=4;            //dah ell fe eh sensor aslan
int CS=7;
int RS=6;
#define spd1 8 // MOTOR ELSHEMAL

#define spd2 7  // motor elyemen
int FORWARD( )
{      analogWrite (spd1,255);
     analogWrite (spd2,255);
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
{      analogWrite (spd1,255);
     analogWrite (spd2,128);


      digitalWrite (motor1f,HIGH);
   
     digitalWrite (motor1b,LOW);
     
     digitalWrite (motor2f,HIGH);
     
     digitalWrite (motor2b,LOW);
     
}


int RIGHTHIGH ( )
{     

     analogWrite (spd1,255);
     analogWrite (spd2,64);
     digitalWrite (motor1f,HIGH);
   
     digitalWrite (motor1b,LOW);
     
     digitalWrite (motor2f,HIGH);
     
     digitalWrite (motor2b,LOW);
    
     
}

int LEFT()
{
      analogWrite (spd1,128);
     analogWrite (spd2,255);
    digitalWrite (motor1f,HIGH);
    
     digitalWrite (motor1b,LOW);
     
     digitalWrite (motor2f,HIGH);
     
     digitalWrite (motor2b,LOW);
     
}


int LEFTHIGH(){
  
  
   analogWrite (spd1,64);
     analogWrite (spd2,255);
   digitalWrite (motor1f,HIGH);

     digitalWrite (motor1b,LOW);
     
     digitalWrite (motor2f,HIGH);

     digitalWrite (motor2b,LOW);
    
  }
   int STOP () {
    
     analogWrite (spd1,0);
     analogWrite (spd2,0);
    digitalWrite (motor1f,LOW);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,LOW);
     digitalWrite (motor2b,LOW);
    
    
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
 if (Serial.available() > 0)
  {

    data = Serial.read();
if(data=='U'){
  if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     // STOP
  {  
    STOP ();
     
     
  }
   else if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Right with slight angle Edited
  {
    
      int RIGHT ( );
    
    
  }
    else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Forward with full speed Edited
  {
   FORWARD( );
 
    }
    else if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move Right with greater angle Edited
   {   
    RIGHTHIGH ( );
  }
  
  else if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move Left with slight angle edited
  {
     LEFT();
    
    
  }

  else if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move left with greater angle edited
  {
    
     LEFTHIGH();
  }

   else if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // stop
  {     STOP ();
     
  }

   else 
  {
       STOP ();
     
  } delay(10); 
  data =0;
}
  }
}
