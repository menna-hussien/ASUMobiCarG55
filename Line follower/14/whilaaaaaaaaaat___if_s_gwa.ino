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

int LS=24;            //dah ell fe eh sensor aslan
int CS=23;
int RS=22;
#define spd1 7 // MOTOR ELSHEMAL kan 9
#define spd2 6  // motor elyemen kan 6



int FORWARD( )
{      analogWrite (spd1,120);
     analogWrite (spd2,120);
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
{      analogWrite (spd1,120);
     analogWrite (spd2,120);        //128

      digitalWrite (motor2b,LOW);
      
     digitalWrite (motor2f,HIGH);
     
    digitalWrite (motor1b,HIGH);     
    digitalWrite (motor1f,LOW);

    
    
     
}


int RIGHTHIGH ( )           //greater
{     

     analogWrite (spd1,120);      //255
     analogWrite (spd2,120);
          digitalWrite (motor2b,LOW);
      
     digitalWrite (motor2f,HIGH);
      
     digitalWrite (motor1b,HIGH);
      
     digitalWrite (motor1f,LOW);
    
  
     
}

int LEFT()
{
      analogWrite (spd1,120);        //128
     analogWrite (spd2,120);      //255
    digitalWrite (motor2b,HIGH);
        digitalWrite (motor2f,LOW);     
     digitalWrite (motor1b,LOW);
      digitalWrite (motor1f,HIGH);  
}


int LEFTHIGH(){
  
                          
   analogWrite (spd1,120);          //
     analogWrite (spd2,120);       //255
   digitalWrite (motor2b,HIGH);
   
     digitalWrite (motor2f,LOW);
     
     digitalWrite (motor1b,LOW);
    
     digitalWrite (motor1f,HIGH);  

    
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
 //if (Serial.available() > 0)
  //{ 
    //Serial.println("line follower mode is on");

   // data = Serial.read();
//if(data=='U'){
  
  while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     //stop //0 white
  {  
    Serial.println("STOP");
    STOP();
  }

  
   while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move  RIGHT  with slight angle Edited
    {
       RIGHT ( );
    if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)
    { 
      while( digitalRead(CS)!=1)
        RIGHT();
    }
    else RIGHT ( );
  }


  
    while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Forward with full speed Edited
  {
      FORWARD( );
     if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)
   { 
      while( digitalRead(CS)==0)
        {
          RIGHT();
          if(digitalRead(CS)==1)
          break;
          else LEFT();
        }
   }
   else FORWARD();
 
   }
     while(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Forward with full speed Edited
  {
      FORWARD( );
         if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)
   { 
      while( digitalRead(CS)==1)
        {
          RIGHT();
          if(digitalRead(CS)==0)
          break;
        else LEFT();
     
        }
   }else FORWARD();
    }
 
    
    while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Right with greater angle Edited
   {   
    
    RIGHTHIGH ( );
    if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)
   { 
      while( digitalRead(CS)!=1)
        RIGHT();
    }
    else  RIGHTHIGH ( );
  }
  
 while(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Left with slight angle edited
  {
    
     LEFT();
     if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0) 
    { 
      while( digitalRead(CS)!=1)
        LEFT();
    }
    else   LEFT();
  }

  while(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move left with greater angle edited
  {
    
     LEFTHIGH();
     
        if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0) 
    { 
      while( digitalRead(CS)!=1)
        LEFT();
    }
    else  LEFTHIGH();
  }

   while(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // forward msh 3rfa bs 5at eswd yw2fo y3ny
  {     STOP ();
     
  }


  delay(10); 
  //data =0;
}
  
//}

