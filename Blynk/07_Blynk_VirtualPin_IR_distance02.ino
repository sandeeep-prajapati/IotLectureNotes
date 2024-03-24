#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

int irPin = A0;
int dist;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  float val = analogRead(irPin);
  dist = 27.728 * pow(map(val,0,1023,0,3300)/1000.0, -1.2045); 
  Serial.print(dist);
  Serial.println(" cm");
  delay(500);
}

BLYNK_READ(V3){
  Blynk.virtualWrite(3, dist);
}
