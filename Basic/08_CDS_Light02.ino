int cds = A0;
int led = D1;

void setup() {
   Serial.begin(9600);
   pinMode(led, OUTPUT);
}

void loop() {
   int signalLevel = analogRead(cds);
   
   if(signalLevel > 500){		    //어두워지면 (풀업저항)
      digitalWrite(led, HIGH);	//LED On
      Serial.println("LED ON");
   }else{			                  //밝아지면
      digitalWrite(led, LOW);	  //LED Off
      Serial.println("LED OFF");
   }
   delay(500);
}
 
