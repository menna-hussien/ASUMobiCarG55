//Code to test motor control using serial
//asumming L298 Motor Driver

/* edit "MOD R1":
Made it char based serial control for motor 
added function change_speed()  STOP();
mod return type of all function 
removed old speed control mechanism

TODO: 
    1)  Check and report/change syntax and compile/run time errors. 
    2)  Add test cases 
            serial_check() to test serial connection
            motor_check() to test motor connections 
*/


//pinnames
#define MOTOR_1F 13
#define MOTOR_1B 12
#define MOTOR_2F 11
#define MOTOR_2B 10
#define SPEED_1 8
#define SPEED_2 7

void setup() {
 
//Intitiate serial communication
Serial.begin(9600);
while (! Serial); 

pinMode (MOTOR_1F,OUTPUT);
pinMode (MOTOR_1B,OUTPUT);
pinMode (MOTOR_2F,OUTPUT);
pinMode (MOTOR_1B,OUTPUT);
pinMode (SPEED_1, OUTPUT);
pinMode (SPEED_2,OUTPUT);

Serial.println("Speed 0 to 5 or F B L R");
}

//functions
void FORWARD();
void BACKWARD();
void RIGHT();
void LEFT();
void STOP()

void change_speed(int speed)

void loop() {

  if (Serial.available())
    {
    
      char data = Serial.read();
             
      if(isAlpha(data))
        {
          //call the direction fuctions with F B L R as serial input checks
          
            switch (data) {
                case 'F':
                case 'f':
                        int FORWARD();
                        break;
                case 'B':
                case 'b':
                        int BACKWARD();
                        break;
                case 'L':
                case 'l':
                        int LEFT();
                        break;
                case 'R':
                case 'r':
                        int RIGHT();
                        break;
  
                default:
                 Serial.println("Error 0001: Char not recognised");
                 change_speed(0);
                 STOP(); 
                }
        }
      else change_speed(data);
      
      delay(1000);  //wait 1 sec before checking next input
    }
    
} 



void change_speed(int speed){
  
      speed = map(speed, 0, 5, 0, 255); // converting 0-5 to 0-255
      speed = constain(speed, 0, 255); // just to make sure enterd value does not go beyond limit
    
      analogWrite(SPEED_1, speed);  //writting the spee value to pins
      analogWrite(SPEED_2, speed);
       
}


void FORWARD()
{
     digitalWrite (MOTOR_1F,HIGH);
     digitalWrite (MOTOR_1B,LOW);
     digitalWrite (MOTOR_2F,HIGH);
     digitalWrite (MOTOR_2B,LOW);
}

void BACKWARD()
{
     digitalWrite (MOTOR_1B,HIGH);
     digitalWrite (MOTOR_1F,LOW);
     digitalWrite (MOTOR_2B,HIGH);
     digitalWrite (MOTOR_2F,LOW);
}

void RIGHT ()
{
     digitalWrite (MOTOR_1B,HIGH);
     digitalWrite (MOTOR_1F,LOW);
     digitalWrite (MOTOR_2B,LOW);
     digitalWrite (MOTOR_2F,HIGH);
}

void LEFT()
{
     digitalWrite (MOTOR_1B,LOW);
     digitalWrite (MOTOR_1F,HIGH);
     digitalWrite (MOTOR_2B,HIGH);
     digitalWrite (MOTOR_2F,LOW);
}

void STOP()
{
     digitalWrite (MOTOR_1B,LOW);
     digitalWrite (MOTOR_1F,LOW);
     digitalWrite (MOTOR_2B,LOW);
     digitalWrite (MOTOR_2F,LOW);
}

