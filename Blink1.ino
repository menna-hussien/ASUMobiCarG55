int LED1 =4;
  int LED2=5;
  int LED3=6;
  int LED4=7;

void setup() {
  
  
  pinMode(LED1 , OUTPUT);
   pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1 , HIGH); 
  delay(1000);                       
  digitalWrite(LED1, LOW);    
  delay(50); 
  digitalWrite(LED2 , HIGH); 
  delay(1000);                       
  digitalWrite(LED2, LOW);    
  delay(50); 
  digitalWrite(LED3, HIGH);   
  delay(1000);                      
  digitalWrite(LED3, LOW);    
  delay(50); 
   digitalWrite(LED4, HIGH);   
  delay(1000);                      
  digitalWrite(LED4, LOW);    
  delay(50);
   digitalWrite(LED4, HIGH);   
  delay(1000);                      
  digitalWrite(LED4, LOW);    
  delay(50);
  digitalWrite(LED3, HIGH);   
  delay(1000);                      
  digitalWrite(LED3, LOW);    
  delay(50);
  digitalWrite(LED2 , HIGH); 
  delay(1000);                       
  digitalWrite(LED2, LOW);    
  delay(50); 
  digitalWrite(LED1 , HIGH); 
  delay(1000);                       
  digitalWrite(LED1, LOW);    
  delay(50);
  
          
}
