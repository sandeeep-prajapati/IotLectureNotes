#include "Wire.h"
#define PCF8591 (0x90 >> 1)
#define ADC_CHANNEL0   0x00

void setup() {
   Wire.begin();
   Serial.begin(9600);
}

void loop() {
  byte signalLevel;
  float voltage, temperature;

  Wire.beginTransmission(PCF8591);
  Wire.write(ADC_CHANNEL0);
  Wire.endTransmission();

  Wire.requestFrom(PCF8591, 1);
  signalLevel = Wire.read();

  voltage = signalLevel * 3.3/256.0;
  temperature = 100*voltage-50;
  Serial.println( temperature );
  delay(1000);
}
