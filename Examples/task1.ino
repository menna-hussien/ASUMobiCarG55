const int data = 13 ;
const int latch = 12;
const int clck = 11 ;
byte led []={B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B01000111};

void setup() {
  // put your setup code here, to run once:
pinMode(data ,OUTPUT );
pinMode(latch ,OUTPUT );
pinMode(clck ,OUTPUT );
}
void loop() {
  // put your main code here, to run repeatedly:
for(int i =0 ; i < sizeof(led) ; i++ )
{digitalWrite(latch,0);
shiftOut(13,11,MSBFIRST,led [i]);
digitalWrite(latch,1);
delay(1000);
}}
