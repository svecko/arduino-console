#include <TFT.h>
#include "Joystick.h"

#define CS 10
#define DC 8
#define RESET 9

struct Point
{
  float x, y;
  float xPrev, yPrev;
};

TFT myScreen = TFT(CS, DC, RESET);

Joystick joystick;
Point point;

void setup()
{
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  myScreen.begin();
  myScreen.background(0, 0, 0);

  point.x = 80;
  point.y = 64;
}

void loop()
{
  joystick.x = map(analogRead(A1), 0, 1023, 0, 160);
  joystick.y = map(analogRead(A0), 1023, 0, 0, 128);
  joystick.buttonState = analogRead(A2);

  point.x = joystick.x;
  point.y = joystick.y;

  if (point.x != point.xPrev || point.y != point.yPrev)
  {
    myScreen.stroke(0, 0, 0);
    myScreen.rect(point.xPrev, point.yPrev, 3, 3);
  }

  if (joystick.isPressed())
  {
    myScreen.stroke(0, 0, 255);
    myScreen.rect(point.x, point.y, 3, 3);
  }
  else
  {
    myScreen.stroke(255, 255, 255);
    myScreen.rect(point.x, point.y, 3, 3);
  }

  point.xPrev = point.x;
  point.yPrev = point.y;
}
