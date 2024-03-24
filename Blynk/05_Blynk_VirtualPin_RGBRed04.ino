#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "yourAuth";
char ssid[] = "yourSsid";
char pass[] = "yourPass";

int r, g, b;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  analogWrite(D5, r);
  analogWrite(D6, g);
  analogWrite(D7, b);
}

BLYNK_WRITE(V8)
{
  r = param[0].asInt();
  g = param[1].asInt();
  b = param[2].asInt();
  Serial.print("R: ");
  Serial.println(r);
  Serial.print("G: ");
  Serial.println(g);
  Serial.print("B: ");
  Serial.println(b);  
} 
