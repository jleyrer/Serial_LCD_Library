#include "Serial_LCD_SparkFun-20x4/Serial_LCD_SparkFun-20x4.h"

/* 
This is a port of the wonderful library found here: http://playground.arduino.cc/Code/SerLCD
The documentation there will explain all the functions available, and I expect them all to work
EXCEPT when it says `lcd.print()` If you're copying example code, you'll need to change those to
`Serial1.print()`... and that's it!

The wiring is simple- Provide appropriate power and ground (there are 5v and 3.3v varieties
of the LCD) and connect the LCD's `RX` pin to the Core or Photon's `TX` pin!

If you look in Cloud functions in Dev (particle.io/dev) you'll be able to send messages to
lcdRow1 and lcdRow2.
*/


// Create two functions, one for writing on each row
int lcdMsgRow1(String command);
int lcdMsgRow2(String command);

// Initialize the LCD library
Serial_LCD_SparkFun lcd = Serial_LCD_SparkFun();

void setup() {
 // Registering our two cloud functions
 Spark.function("lcdRow1", lcdMsgRow1);
 Spark.function("lcdRow2", lcdMsgRow2);
 
 // Start with a blank slate
 lcd.clear();
}

// Don't need to do anything in the loop
void loop() {}

// Writing to row 1
int lcdMsgRow1(String command){
    
    // Clear the display
    lcd.clear();

    // Write whatever was send to the command
    Serial1.print(command);

    // Return 1 for giggles
    return 1;
}

// Writing to row 2
int lcdMsgRow2(String command){
    lcd.clear();

    // Ahhh, but this one is a little different!
    // Here we're moving the "cursor" to line 2
    lcd.selectLine(2);
    Serial1.print(command);
    return 1;
}