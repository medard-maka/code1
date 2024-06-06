#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo;
int targetDistance;
int pos;
long duration, distance;
const int trigPin = 2;         // Broche de déclenchement du capteur ultrasonique
const int echoPin = 3;         // Broche de réception du capteur ultrasonique
const int servoPin = 9;        // Broche de contrôle du servo-moteur

SoftwareSerial bluetooth(10, 11);  // Broches RX, TX du module Bluetooth

void mesure() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Bluetooth Distance: ");
  Serial.print(targetDistance);
  Serial.print(" cm, capteur ultrason ");
  Serial.print(distance);
  Serial.println(" cm");
}
void test () {
    if (targetDistance == distance) {
          // Arrête le servo-moteur
          servo.detach();
          Serial.println("Servo stop.");
          delay(500);
         
          }
else {
  servo.attach(9);
          Serial.println("Servo en marche.");
          delay(15);
}
          
     }


void moov() {
   
   
    if (targetDistance < distance) {
      for (int pos = 0; pos <= 180; pos += 1) {
        servo.write(pos);
        mesure();
        test ();
        delay(15);
        
        
        }
         for (int pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos);
        mesure();
         test ();
        delay(15);
        
         }
      }
    
      
      else if (targetDistance > distance) {
      for (int pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos);
        mesure();
         test ();
        delay(15);
       
      }
      for (int pos = 0; pos <= 180; pos += 1) {
        servo.write(pos);
        mesure();
         test ();
        delay(15);
        
      }
    }
        
      
      
   
  }


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);       // Attache le servo-moteur à la broche de contrôle

  Serial.begin(9600);           // Initialise la communication série avec l'ordinateur
  bluetooth.begin(9600);        // Initialise la communication série avec le module Bluetooth
}

void loop() {
  mesure();
  if (bluetooth.available()) {
    
   targetDistance = bluetooth.parseInt();
  while (targetDistance != distance) {
     
       Serial.println(distance);
    moov();
  }
  }
      
  
}
