
int ledRed = 4;
int ledYellow =5;
int ledGreen = 6;
int ledBlue = 7 ;

void setup() {
  // put your setup code here, to run once:
pinMode (ledRed, OUTPUT);
pinMode (ledYellow, OUTPUT);
pinMode (ledGreen, OUTPUT);
pinMode (ledBlue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (ledRed,HIGH);
delay (1000);
digitalWrite (ledRed,LOW);
digitalWrite (ledYellow,HIGH);
delay (1000);
digitalWrite (ledYellow,LOW);
digitalWrite (ledGreen,HIGH);
delay (1000);
digitalWrite (ledGreen,LOW);
digitalWrite (ledBlue,HIGH);
delay (2000);
digitalWrite (ledBlue,LOW);

digitalWrite (ledGreen,HIGH);
delay (1000);
digitalWrite (ledGreen,LOW);
digitalWrite (ledYellow,HIGH);
delay (1000);
digitalWrite (ledYellow,LOW);
digitalWrite (ledRed,HIGH);
delay (1000);
digitalWrite (ledRed,LOW);

}
