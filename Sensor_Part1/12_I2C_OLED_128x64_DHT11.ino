#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//Include DHT Library
#include "DHTesp.h"
DHTesp dht;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello!");
  display.display();

  //Connect DHT sensor to D4, GPIO 2
  dht.setup(2, DHTesp::DHT11);

}

void loop() {
  // put your main code here, to run repeatedly:
  displayTempHumid();
  display.display();
}

void displayTempHumid(){
  //Delay to allow sensor to stablize
  delay(2000);
  
  //Read Humidity
  float h = dht.getHumidity();
  //Read temperature as Celsius
  float t = dht.getTemperature();

  // Clear the buffer.
  display.clearDisplay();
  display.display();
  
  display.setCursor(0,0);
  display.print("Humidity: ");
  display.println(h);

  display.setCursor(0,10);
  display.print("Temperature: ");
  display.println(t);

}
