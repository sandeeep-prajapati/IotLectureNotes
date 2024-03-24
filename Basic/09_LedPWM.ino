int ledPin = D0;
void setup() {
   pinMode(ledPin, OUTPUT);
}

void loop() {
   analogWrite(ledPin, 512);
   delay(2000);
   analogWrite(ledPin, 1023);
   delay(2000);
}
