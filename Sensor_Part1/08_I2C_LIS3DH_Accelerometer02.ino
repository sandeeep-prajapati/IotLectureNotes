#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU; //Default constructor is I2C, addr 0x19.

void setup() {
  Serial.begin(9600);
  delay(1000);
  //Serial.println("Processor came out of reset.\n");
  myIMU.begin();
}

void loop()
{
  //Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.print(myIMU.readFloatAccelX(), 4);
  Serial.print(" Y = ");
  Serial.print(myIMU.readFloatAccelY(), 4);
  Serial.print(" Z = ");
  Serial.println(myIMU.readFloatAccelZ(), 4);
  delay(40);    // f = 1/40 x 1000 = 약 25Hz
}
