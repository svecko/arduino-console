#include <TFT.h> // Hardware-specific library

#define CS   10
#define DC   8
#define RESET  9  

TFT myScreen = TFT(CS, DC, RESET);

// variable to keep track of the elapsed time
int counter = 0;
// char array to print time
char printout[4];

void setup(){
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  myScreen.begin();  
  myScreen.background(0,0,0); // clear the screen
  myScreen.stroke(255,0,255);
  myScreen.setTextSize(2);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void loop(){
    // print out and erase
    myScreen.stroke(255,255,255);
    myScreen.text("Display radi",0,0);
}
