int LED1 =4;


void setup() {
  
  
  pinMode(LED1 , OUTPUT);
 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1 , HIGH); 
  delay(500);                       
  digitalWrite(LED1, LOW);    
  delay(1500); 
}
