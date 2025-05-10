int piezobuzzPin = 4;

void setup() {
  pinMode(piezobuzzPin, OUTPUT);
}

void loop() {
  digitalWrite(piezobuzzPin, HIGH),
  delay(1000);
  digitalWrite(piezobuzzPin, LOW);
}
