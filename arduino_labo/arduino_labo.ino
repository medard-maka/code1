 
#include <SoftwareSerial.h>

int data;

int led1 = 2;
int led2 = 3;
int led3 = 4; 

void setup() {


  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();

    delay(100);

    if (data == 'a') {
      digitalWrite(led1, HIGH);
    } else if (data == 'b') {
      digitalWrite(led1, LOW);
    } else if (data == 'c') {
      digitalWrite(led2, HIGH);
    } else if (data == 'd') {
      digitalWrite(led2, LOW);
    } else if (data == 'e') {
      digitalWrite(led3, HIGH);
    } else if (data == 'f') {
      digitalWrite(led3, LOW);
    }  else if (data == 's') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    delay(100);
  }
}
