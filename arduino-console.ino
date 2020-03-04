// Display header
#include <TFT.h>

#define CS 10
#define DC 8
#define RESET 9

struct Joystick
{
  int x, y;
  int buttonPin, buttonState;

  bool isPressed()
  {
    return buttonState == 0 ? true : false;
  }

  void PrintState()
  {
    Serial.print("x: ");
    Serial.println(x);

    Serial.print("y: ");
    Serial.println(y);

    Serial.print("button state: ");
    Serial.println(buttonState == 0 ? "button is pressed" : "button is not pressed");
  }
};

struct Point
{
  int x, y;
  int xPrev, yPrev;
};

// TFT display
TFT myScreen = TFT(CS, DC, RESET);

// Joystick
Joystick joystick;
Point point;
joystick.buttonPin = A2;

void setup()
{
  // TFT display
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  myScreen.begin();
  myScreen.background(0, 0, 0);

  Serial.begin(9600);
}

void loop()
{
  // Get joystick data
  joystick.x = map(analogRead(A1), 0, 1023, 0, 160);
  joystick.y = map(analogRead(A0), 1023, 0, 0, 128);
  joystick.buttonState = analogRead(joystick.buttonPin);

  // Update point position
  point.x = joystick.x;
  point.y = joystick.y;

  // Update previous point position
  point.xPrev = point.x;
  point.yPrev = point.y;

  // Clean previous point position
  if (point.x != point.xPrev || point.y != point.yPrev)
  {
    myScreen.stroke(0, 0, 0);
    myScreen.point(point.xPrev, point.yPrev);
  }

  if (joystick.isPressed())
  {
    // Fill red and display point
    myScreen.stroke(0, 0, 255);
    myScreen.point(point.x, point.y);
  }
  else
  {
    // Fill white and display point
    myScreen.stroke(255, 255, 255);
    myScreen.point(point.x, point.y);
  }
}
