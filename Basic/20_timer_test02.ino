#include <Event.h>
#include <Timer.h>

Timer t;
int ledState = LOW;

void flip(void){
  ledState = !ledState;
  digitalWrite(LED_BUILTIN, ledState);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  t.every(1000, flip);  
}

void loop() {
  // put your main code here, to run repeatedly:
  t.update();
}
