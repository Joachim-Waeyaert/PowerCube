const int piezoPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(piezoPin, INPUT);
  Serial.println("Start Piezo uitlezing");
}

void loop() {
  int value = analogRead(piezoPin);
  Serial.println(value);  // één waarde per regel = grafiek in plotter
  delay(10);              // update elke 10 ms (100 metingen per seconde)
}