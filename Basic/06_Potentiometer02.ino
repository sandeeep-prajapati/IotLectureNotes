void setup() {
   Serial.begin(9600);
}

void loop() {
   int signalLevel = analogRead(A0);
   float voltage = signalLevel * 3.3/1024.0;
   Serial.println( voltage, 4 );
}
   
