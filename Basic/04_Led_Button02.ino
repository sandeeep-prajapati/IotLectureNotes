void setup() {
   Serial.begin(9600);
   pinMode(0, OUTPUT);	//D3 – GPIO0
   pinMode(5, INPUT);	  //D1 – GPIO5
}

void loop() {
   int swState = digitalRead(5);
   digitalWrite(0, swState);
   Serial.println( swState );
}
   
