void setup() {

pinMode (0,INPUT);
pinMode (1,INPUT);
pinMode (2,INPUT);
pinMode (3,INPUT);
pinMode (4,INPUT);
pinMode (5,INPUT);
pinMode (6,INPUT);
pinMode (13,OUTPUT);
pinMode (12,OUTPUT);
pinMode (11,OUTPUT);
pinMode (10,OUTPUT);
pinMode (9,OUTPUT);
pinMode (8,OUTPUT);
pinMode (7,OUTPUT);


}

void loop() {


if ( digitalRead (0)==0 &&     digitalRead (1)==1 && digitalRead (2)==1 && digitalRead (3)==1 && digitalRead (4)==1 && digitalRead (5)==1 && digitalRead (6)==1       )
{
digitalWrite (13,HIGH);
digitalWrite (12,HIGH);
digitalWrite (11,HIGH);
digitalWrite (10,HIGH);
digitalWrite (9,HIGH);
digitalWrite (8,HIGH);
digitalWrite (7,LOW);

}
else if (digitalRead (0)==1 &&     digitalRead (1)==0 && digitalRead (2)==1 && digitalRead (3)==1 && digitalRead (4)==1 && digitalRead (5)==1 && digitalRead (6)==1  )
{

digitalWrite (13,LOW);
digitalWrite (12,HIGH);
digitalWrite (11,HIGH);
digitalWrite (10,LOW);
digitalWrite (9,LOW);
digitalWrite (8,HIGH);
digitalWrite (7,HIGH);
  
}
else if (digitalRead (0)==1 &&     digitalRead (1)==1 && digitalRead (2)==0 && digitalRead (3)==1 && digitalRead (4)==1 && digitalRead (5)==1 && digitalRead (6)==1)
{

digitalWrite (13,HIGH);
digitalWrite (12,LOW);
digitalWrite (11,HIGH);
digitalWrite (10,HIGH);
digitalWrite (9,LOW);
digitalWrite (8,HIGH);
digitalWrite (7,HIGH);
  
}
else if (digitalRead (0)==1 &&     digitalRead (1)==1 && digitalRead (2)==1 && digitalRead (3)==0 && digitalRead (4)==1 && digitalRead (5)==1 && digitalRead (6)==1)
{

  digitalWrite (13,HIGH);
digitalWrite (12,LOW);
digitalWrite (11,HIGH);
digitalWrite (10,HIGH);
digitalWrite (9,HIGH);
digitalWrite (8,HIGH);
digitalWrite (7,HIGH);
}
else if (digitalRead (0)==1 &&     digitalRead (1)==1 && digitalRead (2)==1 && digitalRead (3)==1 && digitalRead (4)==0 && digitalRead (5)==1 && digitalRead (6)==1)
{

  digitalWrite (13,LOW);
digitalWrite (12,HIGH);
digitalWrite (11,HIGH);
digitalWrite (10,LOW);
digitalWrite (9,LOW);
digitalWrite (8,LOW);
digitalWrite (7,LOW);
}
else if (digitalRead (0)==1 &&     digitalRead (1)==1 && digitalRead (2)==1 && digitalRead (3)==1 && digitalRead (4)==1 && digitalRead (5)==0 && digitalRead (6)==1)
{
  digitalWrite (13,HIGH);
digitalWrite (12,HIGH);
digitalWrite (11,LOW);
digitalWrite (10,HIGH);
digitalWrite (9,HIGH);
digitalWrite (8,LOW);
digitalWrite (7,HIGH);
}
else if (digitalRead (0)==1 &&     digitalRead (1)==1 && digitalRead (2)==1 && digitalRead (3)==1 && digitalRead (4)==1 && digitalRead (5)==1 && digitalRead (6)==0)
{

  digitalWrite (13,HIGH);
digitalWrite (12,HIGH);
digitalWrite (11,HIGH);
digitalWrite (10,HIGH);
digitalWrite (9,LOW);
digitalWrite (8,LOW);
digitalWrite (7,HIGH);
}
else {

  digitalWrite (13,HIGH);
digitalWrite (12,HIGH);
digitalWrite (11,HIGH);
digitalWrite (10,HIGH);
digitalWrite (9,HIGH);
digitalWrite (8,HIGH);
digitalWrite (7,HIGH);
}









  
 

}
