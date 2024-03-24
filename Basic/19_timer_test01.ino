#include <Event.h>
#include <Timer.h>

Timer t;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  t.oscillate(LED_BUILTIN, 1000, LOW);  
}

void loop() {
  // put your main code here, to run repeatedly:
  t.update();
}
