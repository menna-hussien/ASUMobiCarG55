// 4 leds 
int led1 = 4 ;
int led2 = 5 ;
int led3 = 6 ;
int led4 = 7 ;


    void setup() {

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
     
    }
     void loop () {

       digitalWrite(4,HIGH);
       delay(100);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        delay(100);
         digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(100);
        
        digitalWrite(6,LOW);
         digitalWrite(7,HIGH);
         delay(100);
         digitalWrite(7,LOW);
          digitalWrite(7,HIGH);
       delay(100);
        digitalWrite(7,LOW);
        digitalWrite(6,HIGH);
        delay(100);
        digitalWrite(6,LOW);
        digitalWrite(5,HIGH);
        delay(100);
        digitalWrite(5,LOW);
        digitalWrite(4,HIGH);
        delay(100);
        digitalWrite(4,LOW);
        
        
      
     }

