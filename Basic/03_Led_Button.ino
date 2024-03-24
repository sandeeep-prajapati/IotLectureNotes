void setup() {
   Serial.begin(9600);
   pinMode(D3, OUTPUT);
   pinMode(D1, INPUT);
}

void loop() {
   int swState = digitalRead(D1);
   digitalWrite(D3, swState);
   Serial.println( swState );
}
   
