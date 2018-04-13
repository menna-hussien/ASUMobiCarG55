int motor1f =13;
int motor1b=12;
int motor2f=11;
int motor2b =10;

int LS=4;            //dah ell fe eh sensor 
int CS=7;
int RS=3;
int spd1=7;
int spd2=6;

void setup()
{
  
  pinMode(LS, INPUT);
   pinMode(CS, INPUT); 
  pinMode(RS, INPUT);
  pinMode (motor1f, OUTPUT);
  pinMode (motor1b, OUTPUT);
  pinMode (motor2f, OUTPUT);
  pinMode (motor2b, OUTPUT);

}
void loop() {
  
analogWrite(spd1,100);
analogWrite(spd2,100);

  if(digitalRead(RS)==0 && digitalRead(CS)==0 )     // right
  {
      digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);

  }
  else  if(digitalRead(RS)==0 && digitalRead(CS)==1 )     // Move right
  {
      digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);

  }
  else if(digitalRead(RS)==1 && digitalRead(CS)==1)     // Move Forward
  {
 digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);
 }
   else if(digitalRead(RS)==1 && digitalRead(CS)==0 )     // Move Left
  {  digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH); 
     digitalWrite (motor2b,LOW);
  }
}
