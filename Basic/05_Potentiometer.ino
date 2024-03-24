void setup() {
   Serial.begin(9600);
}

void loop() {
   int signalLevel = analogRead(A0);
   Serial.println( signalLevel );
}
