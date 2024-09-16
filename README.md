# Control 7 segment display with a potentiometer

This project uses a potentiometer to control a seven segment display. Using an Arduino Uno as the communication interface between the two peripherals, the potentiometer would display a single number from 0-9 on the seven segment display.

## List of components
1. Arduino Uno
2. Rotary potentiometer
3. Seven segment display (5611AS - common cathode)
4. 220Ω resistor

## Potentiometer pins
![Potentiometer Pins](pot_img.png)
The pin configuration of the potentiometer is:
1. 5V
2. slider pin
3. ground

## Seven segment display pin configuration
According to the datasheet, the seven segments of the display are labelled as pins A-G and DP show in the below image <br>
![Seven Segment Pins](<7seg_pinout.png>)
<br>These segments are mapped onto the external pins of the display as shown below
![Seven Segment External Pins](<7seg_ext_pinout.png>)

## Connection Diagram
![Connection Diagram](<Connection_Diagram.png>)
As can be seen in the above connection diagram, the driving pin of the potentiometer is connected to A0 in the Arduino. This is an analog input pin that reads the output from the potentiometer into a number in the range of 0-1024. This number is then scaled down to a number in the range between 0 and 9, which is then used to control the seven segment display. A current limiting resistor is also added between the common cathode terminals and ground of the seven segment display to prevent the LEDs from burning out.

## Electrical Schematic
![Electrical Schematic](<Electrical_Schematic.png>)

## The code
<br>

```
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
```
This sketch uses the SevSeg library to control the seven segment display. A seven segment object is created on line 3 right after the include statement. The display is initialized with the ```sevseg.begin()``` function on line 17 of the code. The other functions are described below:
<br><br>
```hardwareConfig = COMMON_CATHODE;``` : This sets the type of display of the seven segment display. Since this display is of a common-cathode type, I have set it to COMMON_CATHODE. <br><br>
```byte numDigits = 1;``` : This sets the number of digits on the display. Since I am using a single-digit display, I have set it to 1. <br><br>
```byte digitPins[] = {};``` : This function creates an array that defines the ground pins when using a multi-digit display. Since this project uses a seven-segment display, I have left it empty. <br><br>
```byte segmentPins[] = {7,6,4,2,1,9,10,5};``` This declares an arry which defines which Arduino pins are connected to the segment pins from A-G, DP. For example, segment A is connected to pin 7 and DP is connected to pin 5. <br><br>
```bool resistorsOnSegments = true;``` This needs to be set to true if current limiting resistors are connected in series with the segment pins. In this project, I have connected the common cathode pin to a current limiting resistor. Since the common cathode terminal is connected to each of the segment pins, set this flag to be true. <br><br>
```sevseg.setBrightness(90)``` : This function sets the brightness of the display. It can be adjusted from 0 to 100. <br><br>
```int potentValue = analogRead(A0);``` This function reads the value from the potentiometer driving pin to a number in the range of 0 to 1024. <br><br>
```int value = map(potentValue, 0, 1023, 0, 9);``` This function scales the value from the potentiometer down to an equivalent value in the range of 0-9. <br><br>
```sevseg.setNumber(value);``` : This function sets the number on the display. For example, if value was set to 4, the display would show the number 4. <br><br>
```sevseg.refreshDisplay();``` : This function is required at the end of the loop section to keep displaying and updating the number.<br><br>