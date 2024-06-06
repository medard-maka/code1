#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GAS_SENSOR_PIN A0   // Broche analogique pour le capteur de gaz
#define LED_PIN 13          // Broche de la LED

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C de l'écran LCD

void setup() {
  pinMode(LED_PIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Detection d'eau");
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(GAS_SENSOR_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);  // Conversion de la valeur analogique en tension
  
  // Si la tension est en dessous d'un seuil spécifique, considérez qu'il s'agit d'eau
  float waterThreshold = 2.0;  // Seuil de tension pour l'eau (ajustez selon vos besoins)
  
  if (voltage < waterThreshold) {
    digitalWrite(LED_PIN, HIGH);  // Allumer la LED si c'est de l'eau
    lcd.setCursor(0, 1);
    lcd.print("Eau detectee    ");
    Serial.println("C'est de l'eau !");
  } else {
    digitalWrite(LED_PIN, LOW);   // Éteindre la LED si ce n'est pas de l'eau
    lcd.setCursor(0, 1);
    lcd.print("Pas d'eau      ");
    Serial.println("Ce n'est pas de l'eau.");
  }
  
  delay(1000);  // Délai entre les mesures (ajustez selon vos besoins)
}
