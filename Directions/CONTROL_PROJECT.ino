
char data = 0;
int motor1f =13;
int motor1b=12;
int motor2f=11;
int motor2b =10;
int spd1 =8;
int spd2 =7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (motor1f,OUTPUT);
pinMode (motor1b,OUTPUT);
pinMode (motor2f,OUTPUT);
pinMode (motor2b,OUTPUT);
pinMode (spd1, OUTPUT);
pinMode (spd2,OUTPUT);
}
int FORWARD ( );
int BACKWARD ( );
int RIGHT ( );
int LEFT ( );
int HALFSPEED ();
int QUARTERSPEED();
int TOTALSPEED ();


void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() >0)
{

  data =Serial.read();
  
  if (data  == '1')
  { TOTALSPEED ();
    FORWARD ();
   }
    else if (data == '2')
    {
      TOTALSPEED();
      BACKWARD();
    }
    else if (data == '3')
    {TOTALSPEED();
      RIGHT();
     
    }
     else if (data == '4')
    {TOTALSPEED();
      LEFT();
     
    }
    

  else 
  {
     digitalWrite (12,LOW);
     digitalWrite (13,LOW);
     digitalWrite (10,LOW);
     digitalWrite (11,LOW);
     
  }

}}
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
int LEFT( )
{

      digitalWrite (motor1b,LOW);
     digitalWrite (motor1f,HIGH);
     digitalWrite (motor2b,HIGH);
     digitalWrite (motor2f,LOW);
     
}
int TOTALSPEED ()
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

