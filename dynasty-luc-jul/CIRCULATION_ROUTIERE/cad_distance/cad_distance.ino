#include <SoftwareSerial.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int trigPin = 13; // Capteur voyage broche reliée à Arduino pin 13
int echoPin = 11; // Capteur Echo broche reliée à Arduino broche 11
int val; // la valeur en degré

float pingTime; // temps de ping voyager de capteur à la cible et retour
float targetDistance; // Distance à la cible en pouces
float speedOfSound = 776.5; // Vitesse du son en miles / heure lorsque la température est 77 degrés.

void setup() {
  myservo.attach(9); // servo connecté à la broche 9
  
  Serial.begin(9600);

  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Distance cible");
  lcd.setCursor(12, 1);
  lcd.print("cm");

  pinMode(trigPin, OUTPUT); // niveau haut
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW); // initialiser cette broche à 0
  delayMicroseconds(2000);

  digitalWrite(trigPin, HIGH); // Set trigPin haute
  delayMicroseconds(15); // Delay en état haut
  digitalWrite(trigPin, LOW); // ping a maintenant été envoyé
  delayMicroseconds(10); // Delay en état de haute

  pingTime = pulseIn(echoPin, HIGH); // pingTime est présentée en microsecondes
  pingTime = pingTime / 1000000.0; // convertir pingTime en secondes en divisant par 1000000 (microsecondes par seconde)
  pingTime = pingTime / 3600.0; // convertir pingTime en heures en divisant par (3600 secondes en une heure)
  targetDistance = speedOfSound * pingTime;
  // Cette valeur est en miles, la vitesse du son étant en miles par heure

  targetDistance = targetDistance / 2.0; // prendre en compte le trajet aller-retour du ping, donc diviser par 2 pour obtenir la distance réelle jusqu'à la cible.
  targetDistance = targetDistance * 63360.0; // convertir les miles en pouces en multipliant par 63360 (pouces par mile)
  lcd.setCursor(1, 0); // Placer le curseur à la première colonne de la deuxième rangée
  lcd.print("la cible est : "); // Effacer la ligne
  lcd.setCursor(0, 1); // Placer le curseur à nouveau à la première colonne de la deuxième rangée
  lcd.print(targetDistance); // Afficher la distance mesurée
  lcd.print(""); // unités
  delay(250); // faire une pause pour permettre l'ajustement

  if (Serial.available()) {
    int data = Serial.parseInt(); // Lire la valeur entière reçue via Bluetooth
    val = map(data, 0, 180, 0, 90); // Mapper la valeur du slider de 0-100 à 0-180 (plage acceptée pour le servo moteur)
    
    myservo.write(val); // Définir la position du servo moteur en fonction de la valeur reçue
    delay(20);
  }
}
