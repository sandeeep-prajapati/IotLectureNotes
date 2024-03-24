#include <SoftwareSerial.h>
#include <PMS.h>

SoftwareSerial PmsSerial(D8, D7); // (UART2 RX, UART2 TX)
 
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


    if(0 <= data.PM_AE_UG_10_0 && data.PM_AE_UG_10_0 <= 30){
      Serial.print("미세먼지 좋음, ");
    }else if(31<=data.PM_AE_UG_10_0 && data.PM_AE_UG_10_0 <= 80){
      Serial.print("미세먼지 보통, ");
    }else if(81<=data.PM_AE_UG_10_0 && data.PM_AE_UG_10_0 <= 150){
      Serial.print("미세먼지 나쁨, ");
    }else if(151<=data.PM_AE_UG_10_0){
      Serial.print("미세먼지 매우 나쁨, ");
    }

    if(0 <= data.PM_AE_UG_2_5 && data.PM_AE_UG_2_5 <= 15){
      Serial.println("초미세먼지 좋음");
    }else if(16<=data.PM_AE_UG_2_5 && data.PM_AE_UG_2_5 <= 50){
      Serial.println("초미세먼지 보통");
    }else if(51<=data.PM_AE_UG_2_5 && data.PM_AE_UG_2_5 <= 100){
      Serial.println("초미세먼지 나쁨");
    }else if(101<=data.PM_AE_UG_2_5){
      Serial.println("초미세먼지 매우 나쁨");
    }
    
    Serial.println("\n");
    delay(1000);    
  }
}//end of loop()
