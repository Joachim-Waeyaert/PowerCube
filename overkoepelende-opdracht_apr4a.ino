#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x3F als jouw scherm een ander adres heeft

#define LOAD_PIN A0  // Sensor aangesloten op analoge pin A0

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);  // Correcte initialisatie van LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Power Cube!");
  delay(1500);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(LOAD_PIN); // 10-bit resolutie: 0–1023

  // Remap naar krachtpercentage (gewoon visueel, niet fysiek correct)
  int kracht = map(rawValue, 0, 1023, 0, 100);

  // Toon de waarden op de LCD
  lcd.setCursor(0, 0);
  lcd.print("Kracht:");
  lcd.setCursor(0, 1);
  lcd.print(kracht);
  lcd.print(" /100   ");

  // Simuleer micro-eenheden voor seriële weergave
  float spanning_mV = (rawValue * 5.0 / 1023.0) * 1000.0; // mV
  float spanning_uV = spanning_mV * 1000.0; // µV

  Serial.print("Ruwe waarde: ");
  Serial.print(rawValue);
  Serial.print(" | Spanning: ");
  Serial.print(spanning_uV, 1);  // 1 decimaal
  Serial.println(" µV");

  delay(200);  // kort pauze tussen metingen
}

