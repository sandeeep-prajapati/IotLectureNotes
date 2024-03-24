#include "DHT.h"
#define DHTPIN 2     // D4, GPIO2 Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourSSID";
char pass[] = "YourPW";

DHT dht(DHTPIN, DHTTYPE);
float h;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop()
{
  Blynk.run();

  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println("%");
  
}

BLYNK_READ(V4){
  Blynk.virtualWrite(4, h);
}
