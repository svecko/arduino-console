#include "Joystick.h"
#include <Arduino.h>

bool Joystick::isPressed()
{
  return buttonState == 0 ? true : false;
}

void Joystick::PrintState()
{
  Serial.print("x: ");
  Serial.println(x);

  Serial.print("y: ");
  Serial.println(y);

  Serial.print("button state: ");
  Serial.println(buttonState == 0 ? "button is pressed" : "button is not pressed");
}