#include <Arduino.h>

int redPin = D0;
int yellowPin = D3;
int greenPin = D5;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  randomSeed(analogRead(0));
}

void loop()
{
  int randTime = random(100, 500);

  int lampu = random(1, 4);

  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  if (lampu == 1)
  {
    digitalWrite(redPin, HIGH);
  }
  else if (lampu == 2)
  {
    digitalWrite(yellowPin, HIGH);
  }
  else
  {
    digitalWrite(greenPin, HIGH);
  }

  delay(randTime);

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(100);
  }
}