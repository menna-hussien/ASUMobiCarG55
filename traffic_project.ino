int yellow =13 ;
int green =12;
int red =11;


void setup() {
  // put your setup code here, to run once:
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (yellow , HIGH);
  digitalWrite (green .LOW);
  digitalWrite (red ,LOW);
  delay (2000);
  
 digitalWrite (yellow , LOW);
  digitalWrite (green .HIGH);
  digitalWrite (red ,LOW);
  delay (2000);

   digitalWrite (yellow , LOW);
  digitalWrite (green .LOW);
  digitalWrite (red ,HIGH);
  delay (2000);
  

}
