void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
if(Serial.available()>0){
  char r=Serial.read();
  switch (r) {
    case 'F' : //forward
     digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,0);
    break;
    case 'B' : //backward
    digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,0);
  digitalWrite(10,1);
    break;
    case 'R' : //right
    digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
    break;
    case '4' : //left
    digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
    break;
    default: //stop
    digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,0);
  }
}
}

