const byte red_sensor_pin = A0;
const byte green_sensor_pin = A1;
const byte blue_sensor_pin = A2;
const byte green_led_pin = 9;
const byte blue_led_pin = 10;
const byte red_led_pin = 11;

unsigned int red_led_value      = 0;
unsigned int blue_led_value     = 0;
unsigned int green_led_value    = 0;
unsigned int red_sensor_value   = 0;
unsigned int blue_sensor_value  = 0;
unsigned int green_sensor_value = 0;

void setup() {
    pinMode(red_led_pin,OUTPUT);
    pinMode(blue_led_pin,OUTPUT);
    pinMode(green_led_pin,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    red_sensor_value = analogRead(red_sensor_pin);
    delay(50);
    blue_sensor_value = analogRead(blue_sensor_pin);
    delay(50);
    green_sensor_value = analogRead(green_sensor_pin);
    // print those values onto the serial monitor
    Serial.println("Raw Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(red_sensor_value);
    Serial.print("\t Blue: ");
    Serial.print(blue_sensor_value);
    Serial.print("\t Green: ");
    Serial.println(green_sensor_value);
    // convert from 0-1023 to 0-255
    red_led_value   = red_sensor_value / 4;   // define Red LED
    blue_led_value  = blue_sensor_value / 4;  // define Blue LED
    green_led_value = green_sensor_value / 4; // define Green LEd
    // print mapped values to serial monitor
    Serial.println("Mapped Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(red_led_value);
    Serial.print("\t Blue: ");
    Serial.print(blue_led_value);
    Serial.print("\t Green: ");
    Serial.println(green_led_value);
    // use analogWrite() to set output for RGB LED
    analogWrite(red_led_pin,red_led_value);   // indicate red LED
    analogWrite(blue_led_pin,blue_led_value);  // indicate blue LED
    analogWrite(green_led_pin,green_led_value); // indicate green 
}

