#include <TFT.h> // Hardware-specific library

#define CS   10
#define DC   8
#define RESET  9  

int VRx, VRy;

TFT myScreen = TFT(CS, DC, RESET);

void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  myScreen.begin();  
  myScreen.background(0,0,0); // clear the screen
  myScreen.stroke(255,0,255);
  myScreen.setTextSize(2);

  Serial.begin(9600);
}

void loop() {
    // print out and erase
    myScreen.stroke(255,255,255);

    VRx = map(analogRead(A1), 0, 1023, 0, 160);
    VRy = map(analogRead(A0), 0, 1023, 0, 128);

    Serial.print("VRx: ");
    Serial.println(VRx);
    Serial.print("VRy: ");
    Serial.println(VRy);
    
    myScreen.text("Display radi",VRx,VRy);
}
