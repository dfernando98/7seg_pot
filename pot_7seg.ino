// Include seven segment library to control the seven segment display
#include <SevSeg.h>
SevSeg sevseg;
/*
This sketch aims to control a seven segment display with a potentiometer
*/

void setup() {
  // This sets the number of segments on display. Set it to 1 since we are using a single-digit seven segment display
  byte numDigits = 1;
  //Leave this array empty if using a single-digit seven segment display
  byte digitPins[] = {};
  byte segmentPins[] = {7,6,4,2,1,9,10,5};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  
}

void loop() {
  int potentValue = analogRead(A0);
  int value = map(potentValue, 0, 1023, 0, 9);
  sevseg.setNumber(value);
  sevseg.refreshDisplay();
}
