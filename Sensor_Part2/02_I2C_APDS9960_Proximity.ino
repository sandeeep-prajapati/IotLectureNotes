#include <Wire.h>
#include <APDS9960.h>

#define APDS9960_SDA    D3 // GPIO0
#define APDS9960_SCL    D1 // GPIO5

// Global Variables
APDS9960 apds = APDS9960();
uint8_t proximity_data = 0;

void setup() {
  Wire.begin(APDS9960_SDA, APDS9960_SCL);
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println(F("SparkFun APDS-9960 - ProximitySensor"));  

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

}

void loop() {
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
  }
  
  // Wait 250 ms before next reading
  delay(1000);
}
