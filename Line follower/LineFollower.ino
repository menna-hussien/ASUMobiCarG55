int left = 5;
int mid = 6;
int right = 7;

int l = 1;
int m = 1;
int r = 1;

int ll = 0;
int mm = 0;
int rr = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  
  pinMode(left, INPUT);
  pinMode(mid, INPUT);
  pinMode(right, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  l = digitalRead(left);
  m = digitalRead(mid);
  r = digitalRead(right);
  
  Serial.print(l);
  Serial.print(m);
  Serial.println(r);
  
  if(l==1&&m==1&&r==1) {
    l = ll;
    m = mm;
    r = rr;
  }
  
  if(l==0&&m==1&&r==1||l==0&&m==0&&r==1) {
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    analogWrite(3, 140);
    
    digitalWrite(8, HIGH);
  }
  
  else if(l==1&&m==1&&r==0||l==1&&m==0&&r==0) {
    digitalWrite(13, HIGH);
    digitalWrite(8, LOW);
    analogWrite(11, 140);
    
    digitalWrite(9, HIGH);
  }
  
  else if(l==0&&m==1&&r==0) {
    digitalWrite(12, HIGH);  //Establishes backward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 140);    //Spins the motor on Channel A at half speed
    
    //Motor B forward @ full speed
    digitalWrite(13, HIGH); //Establishes forward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 140);
  }
 
  else if(l==0&&m==0&&r==0) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  
  ll=l;
  mm=m;
  rr=r;
}
