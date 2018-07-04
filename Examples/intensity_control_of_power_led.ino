int pwmPin = 2; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int c1 = 0;   // declares variable c1
int c2 = 0;   // declares variable c2

void setup()  // setup loop
{
  pinMode(pwmPin, OUTPUT); 
  pinMode(pot, INPUT);  
  Serial.begin(9600);
}

void loop()
{

  int value = analogRead(pot);
  Serial.println(value);
  c1= value; 
  c2= 500-c1;         // subtracts c2 from 1000 ans saves the result in c1
  
  if (value < 500)
  {
  digitalWrite(pwmPin, HIGH); 
  delayMicroseconds(c2);   
  digitalWrite(pwmPin, LOW);  
  delayMicroseconds(c1);   
  }

  if (value > 500)
  {
    digitalWrite(2,LOW);
  }
  
}

