

 
/*Code for MQ-2 Smoke Sensor Circuit Built with an Arduino Board*/

const int sensorPin= A0;
const int buzzerPin= A1;
int smoke_level;

//light follower code
int sensorPinRight =A2; // Right sensor pin
int sensorPinCenter =A3; // Center sensor pin
int sensorPinLeft = A4; // Left sensor pin

int lightReadingRight;
int lightToleranceRight = 1000; // Sensor reading needed to trigger right turn

int lightReadingCenter;
int lightToleranceCenter = 1000; // Sensor reading needed to trigger forward movement

int lightReadingLeft;
int lightToleranceLeft = 1000; // Sensor reading needed to trigger left turn

int readingDelay = 100; // Delay between readings

//RAIN SENSOR
int BLUE_LED = 36;

//Ultrasonic LED
int ORANGE_LED= 37;

//temperature sensor

int input_temp = A6; 
int readingtemp ; 
float temp;

//temperature sensor
int RED_LED= 38; 

void setup() {
pinMode(sensorPin, INPUT);//the smoke sensor will be an input to the arduino
pinMode(buzzerPin, OUTPUT);//the buzzer serves an output in the circuit
pinMode(BLUE_LED, OUTPUT);
pinMode(ORANGE_LED, OUTPUT);
pinMode(input_temp , INPUT) ;
pinMode(RED_LED, OUTPUT);
}

void loop() {
 
  //SMOKE LEVEL SENSOR
  
smoke_level= analogRead(sensorPin); //arduino reads the value from the smoke sensor
Serial.println(smoke_level);//prints just for debugging purposes, to see what values the sensor is picking up
if(smoke_level > 200){ //if smoke level is greater than 200, the buzzer will go off
digitalWrite(buzzerPin, HIGH);
}
else{
digitalWrite(buzzerPin, LOW);
}


//light follower sensor

// Take reading from right sensor
lightReadingRight = analogRead(sensorPinRight);
Serial.print("Right Sensor Reading :");
Serial.println(lightReadingRight);

// Take reading from center sensor
lightReadingCenter = analogRead(sensorPinCenter);
Serial.println("Center Sensor Reading :");
Serial.println(lightReadingCenter);

// Take reading from left sensor
lightReadingLeft = analogRead(sensorPinLeft);
Serial.print("Left Sensor Reading :");
Serial.println(lightReadingLeft);


// Move forward if enought light is detected from center sensor
if (lightReadingCenter > lightToleranceCenter)
{  
  digitalWrite(BLUE_LED, LOW);
  Serial.println("da5l:");
  delay(readingDelay);
// Stop
}

// Turn right if enough light is detected from right sensor
if (lightReadingRight > lightToleranceRight)
{
  delay(readingDelay);
// Stop
}


// Turn left if enough light is detected from left sensor
if (lightReadingLeft > lightToleranceLeft)
{
  delay(readingDelay);
// Stop
}


//RAIN DROP SENSOR
// read the input on analog pin A5:

  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue > 50){
  digitalWrite(BLUE_LED, HIGH);
  }
  else digitalWrite(BLUE_LED, LOW);



//TEMPERATURE SENSOR

 readingtemp  = analogRead(input_temp);
  temp = (readingtemp * (5.0/1024))*100 - 2.5 ; 
  Serial.println(temp);
  //Serial.println(readingtemp);
  delay(500) ;
  if(temp>25){
    digitalWrite(RED_LED, LOW);
    }
  else digitalWrite(RED_LED, LOW); 

}






