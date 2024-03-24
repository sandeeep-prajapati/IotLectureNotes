int ledPin = D0;
void setup() {
   pinMode(ledPin, OUTPUT);
}

void loop() {
   int sensorValue = analogRead(A0);
   analogWrite(ledPin, sensorValue);
   delay(20);
}
   
