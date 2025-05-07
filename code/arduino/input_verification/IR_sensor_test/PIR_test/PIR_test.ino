int PIR_inputPin = 2;



void setup() {
  Serial.begin(9600);
  pinMode(PIR_inputPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR Sensor Test Start");
  delay(5000);
  Serial.println("Sensor klaar!");

}

void loop() {
  int motion = digitalRead(PIR_inputPin);

  if(motion == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("beweging gedetecteerd");
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Niets gedetecteerd");
  }

}
