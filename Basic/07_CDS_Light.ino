void setup() {
   Serial.begin(9600);
}

void loop() {
   delay(2000);
   int signalLevel = analogRead(A0);
   Serial.println( signalLevel );
}
