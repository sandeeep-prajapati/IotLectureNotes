#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

int r, g, b;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V5)
{
  r = param.asInt();
  Serial.print("R: ");
  Serial.println(r);
}

BLYNK_WRITE(V6)
{
  g = param.asInt();
  Serial.print(“G: ");
  Serial.println(g);
}

BLYNK_WRITE(V7)
{
  b = param.asInt();
  Serial.print(“B: ");
  Serial.println(b);
}

