# Control 7 segment display with a potentiometer

This project uses a potentiometer to control a seven segment display. Using an Arduino Uno as the communication interface between the two peripherals, the potentiometer would display a single number from 0-9 on the seven segment display.

## List of components
1. Arduino Uno
2. Rotary potentiometer
3. Seven segment display (5611AS - common cathode)
4. 220 kΩ resistor

## Potentiometer pins
![alt text](pot_img.png)
The pin configuration of the potentiometer is:
1. 5V
2. slider pin
3. ground

## Seven segment display pin configuration
According to the datasheet, the seven segments of the display are labelled as pins A-G and DP show in the below image