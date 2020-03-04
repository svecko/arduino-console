#ifndef Joystick_h
#define Joystick_h

struct Joystick
{
  int x, y;
  int buttonState;

  bool isPressed();
  void PrintState();
};

#endif