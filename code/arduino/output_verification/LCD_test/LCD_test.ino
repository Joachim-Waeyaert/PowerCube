#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//initialiseren van de display.
//lcd(adress, lengte, breedte)
LiquidCrystal_I2C lcd(0x3E, 16, 2);
void setup() {

  lcd.init();           //initialiseren van de lcd
  lcd.backlight();      //Zet backlight aan
  lcd.print("PowerCube");       //Schrijf tekst
}

void loop() {
//voor test niets nodig hier 


}
