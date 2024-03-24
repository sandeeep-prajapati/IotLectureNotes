int rLedPin = 13;
int gLedPin = 8;
int buttonPin = 2;

unsigned long int preTime = 0;
unsigned long int interval = 1000;
int ledState = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long int currentTime = millis();

  if(currentTime - preTime > interval){
    preTime = currentTime;
    ledState = !ledState;
    digitalWrite(rLedPin, ledState);
  }

  int buttonState = digitalRead(buttonPin);
  digitalWrite(gLedPin, buttonState);
}
