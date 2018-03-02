
int LM1=4;       // left motor
//int LM2=5;       
int RM1=6;       // right motor
//int RM2=7;
int LS=4;            //dah ell fe eL sensor aslan
int CS=3;
int RS=2;


void setup()
{
  pinMode(LS, INPUT);
   pinMode(CS, INPUT); 
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
 // pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
 // pinMode(RM2, OUTPUT);

}
void loop() {
  


  if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==0)     // STOP
  {
    digitalWrite(LM1, LOW);
    //digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
   // digitalWrite(RM2, LOW);
  }
    if(digitalRead(RS)==0 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Left
  {
    digitalWrite(LM1, HIGH);
   // digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
   // digitalWrite(RM2, LOW);
  }
    if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Forward
  {
    digitalWrite(LM1, HIGH);
   // digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
   // digitalWrite(RM2, HIGH);
  }
    if(digitalRead(RS)==0 && digitalRead(CS)==1 && digitalRead(LS)==1)     // Move Left
  {
    digitalWrite(LM1, HIGH);
    //digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
   // digitalWrite(RM2, LOW);
  }
    if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==0)     // Move Rght
  {
    digitalWrite(LM1, LOW);
   // digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
   // digitalWrite(RM2, LOW);
  }
    if(digitalRead(RS)==1 && digitalRead(CS)==0 && digitalRead(LS)==1)     // Move Left
  {
    digitalWrite(LM1, HIGH);
   // digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    //digitalWrite(RM2, LOW);
  }
    if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==0)     // Move Right
  {
    digitalWrite(LM1, LOW);
   // digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
   // digitalWrite(RM2, LOW);
  }

   if(digitalRead(RS)==1 && digitalRead(CS)==1 && digitalRead(LS)==1)     // stop
  {
    digitalWrite(LM1, LOW);
    //digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
   // digitalWrite(RM2, LOW);
  }
 
}
