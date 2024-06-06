#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial GSM(8, 9);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int flowMeterPin1 = 2;
const int flowMeterPin2 = 3;

volatile int flowMeterInterruptCount1 = 0;
volatile int flowMeterInterruptCount2 = 0;

float volume1 = 0.0;
float volume2 = 0.0;


void setup() {
  lcd.begin(16, 2);
  lcd.print("Volume 1: ");
  lcd.setCursor(0, 1);
  lcd.print("Volume 2: ");
  
  pinMode(flowMeterPin1, INPUT_PULLUP);
  pinMode(flowMeterPin2, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(flowMeterPin1), countPulse1, FALLING);
  attachInterrupt(digitalPinToInterrupt(flowMeterPin2), countPulse2, FALLING);
  
  
  
  Serial.begin(9600);
}

void loop() {
  float currentVolume1 = calculateVolume(flowMeterInterruptCount1);
  float currentVolume2 = calculateVolume(flowMeterInterruptCount2);
  
  if (fabs(currentVolume1 - currentVolume2) >= 2.0) {
    char message[100];
    sprintf(message, "Volume difference: %.2f ml", fabs(currentVolume1 - currentVolume2));
    sendSMS(phone_no, message);
  }
  
  volume1 = currentVolume1;
  volume2 = currentVolume2;
  
  lcd.setCursor(9, 0);
  lcd.print("     ");
  lcd.setCursor(9, 0);
  lcd.print(volume1);
  
  lcd.setCursor(9, 1);
  lcd.print("     ");
  lcd.setCursor(9, 1);
  lcd.print(volume2);
  
  delay(100);
}

void countPulse1() {
  flowMeterInterruptCount1++;
}

void countPulse2() {
  flowMeterInterruptCount2++;
}

float calculateVolume(int pulseCount) {
  // Calcul du volume en fonction du débitmètre
  // Vous devrez adapter cette formule en fonction de votre débitmètre spécifique
  float volume = pulseCount * 0.25; // Exemple de formule : 0.25 ml par impulsion
  
  return volume;
}
}
