#include "Serial_LCD_SparkFun-20x4/Serial_LCD_SparkFun-20x4.h"

/* 
This is a port of the wonderful library found here: http://playground.arduino.cc/Code/SerLCD
The documentation there will explain all the functions available, and I expect them all to work
EXCEPT when it says `lcd.print()` If you're copying example code, you'll need to change those to
`Serial1.print()`... and that's it!

The wiring is simple- Provide appropriate power and ground (there are 5v and 3.3v varieties
of the LCD) and connect the LCD's `RX` pin to the Core or Photon's `TX` pin!
*/

// Initialize the LCD library
Serial_LCD_SparkFun lcd = Serial_LCD_SparkFun();

void setup() {
 // Start with a blank slate
 lcd.clear();
}

// Don't need to do anything in the loop
void loop() {
	int someNumber = random(10000);

	// Always best to clear the display first
	lcd.clear();

	// We have to print to Serial1
	Serial1.print(someNumber);

	// Delay 500 milliseconds so it's not too fast
	delay(500);
}