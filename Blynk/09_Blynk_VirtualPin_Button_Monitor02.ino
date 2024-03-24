#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

BlynkTimer timer;
WidgetLED led1(V2);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, blinkLed);
  pinMode(D1, INPUT);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}

void blinkLed(){
  int st = digitalRead(D1);
  //Serial.println(st);
  if(st == HIGH){
     //Blynk.virtualWrite(2, 255);
     led1.on();
   }else {
     //Blynk.virtualWrite(2, 0);
     led1.off();  
   }
}
