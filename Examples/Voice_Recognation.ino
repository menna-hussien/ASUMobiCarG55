byte RX_pin=0;

void setup(){
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
delay(2000);
Serial.write(0xAA);
Serial.write(0x37);
delay(2000);
Serial.write(0xAA);
Serial.write(0x21);
}
void LED_OFF_Mode()
{
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
void loop(){
while(Serial.available()){
  RX_pin=Serial.read();
  delay(10);
  switch(RX_pin)
  {
    case 0x11:
    LED_OFF_Mode();
    delay(40);
    digitalWrite(8,HIGH);
    break;
    
    //----------------
     case 0x12:
    LED_OFF_Mode();
    delay(40);
    digitalWrite(9,HIGH);
    break;
    
    //...............
    
     case 0x13:
    LED_OFF_Mode();
    delay(40);
    digitalWrite(10,HIGH);
    break;
    //................
    
     case 0x14:
    LED_OFF_Mode();
    delay(40);
    digitalWrite(11,HIGH);
    break;
    //................
     case 0x15:
    LED_OFF_Mode();
    delay(40);
    digitalWrite(12,HIGH);
    break;
  }
}
}
