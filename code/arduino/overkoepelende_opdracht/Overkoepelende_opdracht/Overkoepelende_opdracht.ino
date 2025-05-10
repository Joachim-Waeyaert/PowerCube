#include <Wire.h>
#include <rgb_lcd.h>

int piezoPin = A0;          // pin waar het piezo element op wordt ingelezen
int piezoWaarde = 0;        // waarde van de piezo
int maxPiezowaarde = 0;     // max waarde piezo
int PIR_inputPin = 2;       // pin waar pir sensor op aangesloten is 
int drukknopPin = 3;        // pin waarop drukknop is aangesloten
int piezobuzzPin = 4;
unsigned long startTijd = 0;    // tijd waarop de pir de detectie begon
unsigned long eindTijd = 0;     // tijd waarop de knop wordt ingedrukt
unsigned long intervalTijd = 0; // tijd tussen detectie en knopdruk
rgb_lcd lcd; // lcd object

void setup() {
  Serial.begin(9600);
  pinMode(PIR_inputPin, INPUT);
  pinMode(drukknopPin, INPUT_PULLUP);
  pinMode(piezobuzzPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0);
  delay(3000);

  lcd.print("GOOOOOOO00000000");
  Serial.println("Systeem klaar: U mag slaan!");
  digitalWrite(piezobuzzPin, HIGH);
  delay(500); // korte piep van 1000 ms
  digitalWrite(piezobuzzPin, LOW);
}

void loop() {
  // Lees piezo en update max
  piezoWaarde = analogRead(piezoPin);
  if (piezoWaarde > maxPiezowaarde) {
    maxPiezowaarde = piezoWaarde;
  }

  // PIR-detectie
  if (digitalRead(PIR_inputPin) == HIGH) {
    if (startTijd == 0) {
      startTijd = millis();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("...");
      lcd.setRGB(255, 165, 0); // Oranje
    }
  }

  // Drukknop-ingedrukt
  if (digitalRead(drukknopPin) == HIGH) {
    if (startTijd != 0) {
      eindTijd = millis();
      intervalTijd = eindTijd - startTijd;
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tijd=");
      lcd.print(intervalTijd);
      lcd.print("ms");

      lcd.setCursor(0, 1);
      lcd.print("kracht=");
      
      lcd.print(maxPiezowaarde);

      lcd.setRGB(0, 0, 255); // blauw

      Serial.print("Snelheid: ");
      Serial.print(intervalTijd);
      Serial.println(" ms");

      Serial.print("Max piezo kracht: ");
      Serial.println(maxPiezowaarde);

      delay(5000);

      // Reset voor volgende meting
      startTijd = 0;
      maxPiezowaarde = 0;

      lcd.clear();
      lcd.setRGB(0, 255, 0); // groen
      lcd.print("U mag slaan!");

      Serial.println("Klaar voor volgende meting");
      digitalWrite(piezobuzzPin, HIGH);
      delay(500); 
      digitalWrite(piezobuzzPin, LOW);
    }
  }
}

