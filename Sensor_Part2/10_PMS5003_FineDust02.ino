#include <SoftwareSerial.h>
#include <PMS.h>

SoftwareSerial PmsSerial(D8, D7);   // (UART2 RX, UART2 TX)
 
PMS pms(PmsSerial);
PMS::DATA data;
 
void setup()
{
  PmsSerial.begin(9600);
  Serial.begin(9600);
  delay(4000);
}
 
void loop()
{
  if (pms.read(data))
  {
    Serial.println("Dust Concentration");
    //Serial.println("PM1.0 :" + String(data.PM_AE_UG_1_0) + "(ug/m3)");
    Serial.println("PM2.5 :" + String(data.PM_AE_UG_2_5) + "(ug/m3)");
    Serial.println("PM10 :" + String(data.PM_AE_UG_10_0) + "(ug/m3)");
    Serial.println("\n");
    delay(1000);
  }
}
