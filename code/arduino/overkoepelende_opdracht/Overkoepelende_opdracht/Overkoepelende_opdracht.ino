#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int piezoPin = A0;          //pin waar het piezo element op wordt ingelezen
int piezoWaarde = 0;        //waarde van de piezo
int maxPiezowaarde = 0;     //max waarde piezo
int PIR_inputPin = 2;       //pin waar pir sensor op aangesloten is 
int drukknopPin = 3;        // pin waarop drukknop is aangesloten
unsigned long startTijd = 0;    // tijd waarop de pir de detectie begon
unsigned long eindTijd = 0;     // tijd waarop de knop wordt ingedrukt
unsigned long intervalTijd = 0;  //tijd tussen de detectie en het indrukken van de knop


LiquidCrystal_I2C lcd(0x3E, 16, 2);  //aanmaken van een lcd object met een i2c adress = 0x3E, en de 16x2 zijn de pixels van het lcd scherm)

void setup() {
  Serial.begin(9600);     // aanzetten van de seriele monitor op 9600 baud
  pinMode(PIR_inputPin, INPUT);       //pir als input
  pinMode(drukknopPin, INPUT_PULLUP);   //drukknop met interne pullup weerstand
  lcd.begin(16,2);                      //initialiseren van het lcd scherm
  lcd.setBacklight(1);                  //Zet achtergrondverlichting aan.
  delay(5000);                          // delay zodat de pir tijd heeft om zich te initialiseren
  lcd.print("U mag slaan!");     //geeft weer wanneer de pir geïnitialiseerd is 

}

void loop() {
//continu piezo uitlezen en piekwaarde onthouden
  piezoWaarde = analogRead(piezoPin);
  if (piezoWaarde > maxPiezowaarde){
    maxPiezowaarde = piezoWaarde;
  }
//eerste fase: wacht op pir detectie
  if(digitalRead(PIR_inputPin) == HIGH) {    //indien er detectie is van de pir sensor begin de timer dan
    if(startTijd == 0){                      //start timer als pir voor het eerst detecteerd, zo wordt vermeden dat de timer constant reset bij een continue beweging. 
    startTijd = millis();                    //zet starttijd van de timer
    lcd.clear();                             //cleared het lcd scherm
    lcd.setCursor(0, 0);                     //zet de cursor naar de eerste regel
    lcd.print("Berekenen...");
    Serial.print("Berekenen");
    }

  }
//tweede fase: wacht op drukknop
  if(digitalRead(drukknopPin) == HIGH) {     //knop wordt ingedrukt, geeft low aan bij interne pull up 
    if(startTijd != 0){                     //Alleen als de timer al gestart is.
      eindTijd = millis();                  //zet eindtijd van de timer
      intervalTijd = eindTijd - startTijd;   //verstreken tijd wordt bepaald door de eindtijd min de starttijd te doen 

      //weergave op het lcd scherm
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tijd=");
      lcd.print(intervalTijd);
      lcd.print("ms");

      //Seriele debug info
      Serial.print("Tijd = ");
      Serial.print(intervalTijd);
      Serial.print(" ms | Kracht = ");
      Serial.println(maxPiezowaarde);      
      //de timers moeten geresed worden
      startTijd = 0;
      maxPiezowaarde = 0;
      delay(1000);
      lcd.clear();
      lcd.print("U mag slaan")
    }
  }
// opmerking na beeindigen van de sessie op 07/05/2025: vanaf de drukknop wordt ingedrukt zal de timer weergegeven worden en dan ook de kracht, maar dit zorgt er wel voor dat misschien
//de maximale impact niet wordt berekent aangezien de piezo niet volledig kan ingedrukt worden vooraleer de knop al ingedrukt is. vb: je slaat en duwt op de drukknop, je verwacht
//dat dan ook de max piezowaarde zal berkeent worden maar het kan zijn dat het niet meer uitgemeten wordt en dat net voor je je volledige kracht op die piezo zet de drukknop al ingedrukt
//zal zijn en dus de arduino niet meer verder rekent welke de hoogste piezo waarde is omdat het al in de loop van het displayen beland. weet niet of dit echt zo is dit is een hypothese.
}

