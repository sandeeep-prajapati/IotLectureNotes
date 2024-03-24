#include <Wire.h>

#define BH1750_POWER_DOWN 0x00
#define BH1750_POWER_ON 0x01
#define BH1750_RESET_0x07

#define CONTINUOUS_HIGH_RES_MODE 0x10 //1 lux resolution *120ms
#define CONTINUOUS_HIGH_RES_MODE_2 0x11 //0.5 lux resolution *120ms
#define CONTINUOUS_LOW_RES_MODE 0x13 //4 lux resolution *16ms
#define ONE_TIME_HIGH_RES_MODE 0x20 //1 lux resolution
#define ONE_TIME_HIGH_RES_MODE 0x21 //0.5 lux resolution
#define ONE_TIME_LOW_RES_MODE 0x23 //4 lux resolution

//I2C Address
#define BH1750_1_ADDRESS 0x23 //sensor 1 to GND
#define BH1750_2_ADDRESS 0x5C //sensor 2 to VCC

//LED Blink
#define LED_PIN 13

//Def of Variable
int16_t RawData;
int16_t SensorValue[2];
boolean blinkState = false;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  init_BH1750(BH1750_1_ADDRESS, CONTINUOUS_HIGH_RES_MODE);
  delay(120);
  RawData_BH1750(BH1750_1_ADDRESS);
  SensorValue[0] = RawData/1.2;

  init_BH1750(BH1750_2_ADDRESS, CONTINUOUS_HIGH_RES_MODE);
  delay(120);
  RawData_BH1750(BH1750_2_ADDRESS);
  SensorValue[1] = RawData/1.2;

  Serial.print("Sensor_1 = ");
  Serial.print(SensorValue[0]);
  Serial.print(", Sensor_2 = ");
  Serial.println(SensorValue[1]);

  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
}

void init_BH1750(int ADDRESS, int MODE) {
   Wire.beginTransmission(ADDRESS);
   Wire.write(MODE);
   Wire.endTransmission(true);
}

void RawData_BH1750(int ADDRESS){
  Wire.beginTransmission(ADDRESS);
  Wire.requestFrom(ADDRESS,2,true);
  RawData = Wire.read() << 8 | Wire.read();
  Wire.endTransmission(true);
}
