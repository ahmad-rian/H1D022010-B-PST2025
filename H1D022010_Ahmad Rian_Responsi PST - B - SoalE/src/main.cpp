#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inisialisasi...");
  delay(20000);
  lcd.clear();
}

void loop()
{
  long duration;
  float distance_cm;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = duration * 0.034 / 2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance_cm, 1);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  if (distance_cm < 100.0)
    lcd.print("AREA BERBAHAYA");
  else
    lcd.print("AMAN");

  delay(1000);
}
