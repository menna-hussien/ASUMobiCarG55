// 1 LED

 int led = 4 ;
 void setup() {

  pinMode(4,OUTPUT);

  }
  void loop() {
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    delay(1500);
  }


