

int motor1f = 13;
int motor1b = 12;
int motor2f = 11;
int motor2b = 10;
#define spd2 6  // MOTOR_A elyemen kan 6
#define spd1 7 // MOTOR_B ELSHEMAL kan 7

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode (motor1f, OUTPUT);
  pinMode (motor1b, OUTPUT);
  pinMode (motor2f, OUTPUT);
  pinMode (motor2b, OUTPUT);
  pinMode (spd1, OUTPUT);
  pinMode (spd2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int i=0;
int j=0;
for(j=0;j<4;j++)
{
for (i=0 ; i<4; i++)
{


digitalWrite(motor1f, HIGH);
 digitalWrite(motor1b, LOW);
 digitalWrite(motor2f, HIGH);
 digitalWrite(motor2b, LOW);
 analogWrite(spd1,100);
 analogWrite(spd2, 100);

 delay (750);   // right angle for rectangle 





}
 
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  analogWrite(spd1,100);
  analogWrite(spd2, 100);
  delay (470);
 
} 
digitalWrite(motor1f,LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, LOW);
  delay (25000);
}
