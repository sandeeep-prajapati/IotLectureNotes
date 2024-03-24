
void setup() {
   pinMode(16, OUTPUT);
}

void loop() {
   digitalWrite(16, LOW);
   delay(1000);
   digitalWrite(16, HIGH);
   delay(1000);
}
