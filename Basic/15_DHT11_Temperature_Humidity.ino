#include "DHTesp.h”

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  String thisBoard= ARDUINO_BOARD;
  Serial.println(thisBoard);

  dht.setup(2, DHTesp::DHT11); // Connect DHT sensor to D4 (GPIO2)
}


void loop()
{
  delay(2000);  //최소 샘플링 주기 2초 이상
  //delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float tmp = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(tmp, 1);
  Serial.print("\t\t");
  Serial.print(dht.toFahrenheit(tmp), 1);
  Serial.print("\t\t");
  Serial.print(dht.computeHeatIndex(tmp, humidity, false), 1);
  Serial.print("\t\t");
  Serial.println(dht.computeHeatIndex(dht.toFahrenheit(tmp), humidity, true), 1);
  delay(2000);
}
