const int piezoPin = A1;  // Analoge pin waar piezo op zit

void setup() {
  Serial.begin(9600);     // Start seriële communicatie
  pinMode(piezoPin, INPUT);
  Serial.println("start");
}

void loop() {
  int piezoWaarde = analogRead(piezoPin);  // Lees de huidige waarde
  Serial.println(piezoWaarde);             // Toon deze in de seriële monitor
  delay(10);                         // Kleine vertraging voor stabiliteit
}
