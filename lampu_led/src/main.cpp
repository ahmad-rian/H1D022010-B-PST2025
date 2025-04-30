#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int SDA_PIN = D2;
const int SCL_PIN = D7;

LiquidCrystal_I2C lcd(0x27, 16, 2);
String line1 = "Halo Jokowi";
String line2 = "Iya saya Keren ";

void setup()
{
  Wire.begin(SDA_PIN, SCL_PIN);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void loop()
{
  lcd.scrollDisplayLeft();
  delay(300);
}
