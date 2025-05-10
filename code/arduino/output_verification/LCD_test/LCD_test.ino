#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.print("Powercube");
    delay(1000);
}
void loop() 
{
    // set the cursor to column 0, line 1
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);
    delay(100);
}