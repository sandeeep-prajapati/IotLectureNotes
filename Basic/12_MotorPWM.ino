int motorPin = D0;
void setup() {
   pinMode(motorPin, OUTPUT);
}

void loop() {
   analogWrite(motorPin, 512);
   delay(2000);
   analogWrite(motorPin, 1023);
   delay(2000);
}
   
