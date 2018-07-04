long duration;
long distance;
int FORWARD ( );
int BACKWARD ( );
int RIGHT ( );
int LEFT ( );
int HALFSPEED ();
int QUARTERSPEED();
void TOTALSPEED ();
int LEFTHIGH();
int RIGHTHIGH ( );
int STOP ();
char data = 0;
int motor1f =13;
int motor1b=12;
int motor2f=11;
int motor2b =10;

//dah ell fe eh sensor aslan
int LS=24;           
int CS=23;
int RS=22;
#define spd2 6  // MOTOR_A elyemen kan 6
#define spd1 7 // MOTOR_B ELSHEMAL kan 7



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (motor1f,OUTPUT);
pinMode (motor1b,OUTPUT);
pinMode (motor2f,OUTPUT);
pinMode (motor2b,OUTPUT);
pinMode (spd1, OUTPUT);
pinMode (spd2,OUTPUT);
pinMode(LS, INPUT);
pinMode(CS, INPUT); 
pinMode(RS, INPUT);
pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    analogWrite (spd1,108);
     analogWrite (spd2,100);
     digitalWrite (motor1f,HIGH);
     digitalWrite (motor1b,LOW);
     digitalWrite (motor2f,HIGH);
     digitalWrite (motor2b,LOW);

}
