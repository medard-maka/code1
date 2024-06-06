int R=10;
int J=11;
int G=12;
boolean cap=1;
void setup() {
  pinMode(R,OUTPUT);
  pinMode(J,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(1,INPUT);
  Serial.begin(9600);
}

void loop() {
 

   if(digitalRead(cap)==1)
   {
  digitalWrite (G,HIGH);
  digitalWrite (J,LOW);
  digitalWrite (R,LOW);
  delay(1000);
    digitalWrite (G,HIGH);
    digitalWrite (J,HIGH);
    digitalWrite (R,LOW);
    delay(100);
    digitalWrite (G,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (R,LOW);
    delay(100);
    digitalWrite (G,HIGH);
    digitalWrite (J,HIGH);
    digitalWrite (R,LOW);
    delay(100);
    digitalWrite (G,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (R,LOW);
    delay(100);
    digitalWrite (G,HIGH);
    digitalWrite (J,HIGH);
    digitalWrite (R,LOW);
    delay(100);
    digitalWrite (G,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (R,LOW);
    delay(100);
    

  digitalWrite (R,LOW);
  digitalWrite (J,HIGH);
  digitalWrite (G,LOW);
  delay(500);


  digitalWrite (G,LOW);
  digitalWrite (J,LOW);
  digitalWrite (R,HIGH);
  delay(1000);
  digitalWrite (R,HIGH);
    digitalWrite(J,HIGH);
    digitalWrite (G,LOW);
    delay(100);
    digitalWrite (R,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (G,LOW);
    delay(100);
    digitalWrite (R,HIGH);
    digitalWrite (J,HIGH);
    digitalWrite (G,LOW);
    delay(100);
    digitalWrite (R,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (G,LOW);
    delay(100);
    digitalWrite (R,HIGH);
    digitalWrite (J,HIGH);
    digitalWrite (G,LOW);
    delay(100);
    digitalWrite (R,HIGH);
    digitalWrite (J,LOW);
    digitalWrite (G,LOW);
    delay(100);
    
}
else {  
  digitalWrite (G,HIGH);
  digitalWrite (J,HIGH);
  digitalWrite (R,HIGH);
  }
  
}
