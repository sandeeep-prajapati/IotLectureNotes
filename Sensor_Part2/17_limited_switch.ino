#define LSWITCH 2

void setup() {
  pinMode(LSWITCH, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(LSWITCH) == HIGH){
      Serial.println("Hi");
  }
}
