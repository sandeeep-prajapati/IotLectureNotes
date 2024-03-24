#include <Wire.h>
#include <APDS9960.h>

// Pins
//#define APDS9960_INT    D6 // GPIO12 Needs to be an interrupt pin
#define APDS9960_SDA    D3 // GPIO0
#define APDS9960_SCL    D1 // GPIO5

// Constants

// Global Variables
APDS9960 apds = APDS9960();
//int isr_flag = 0;

void setup() {
  Wire.begin(APDS9960_SDA, APDS9960_SCL);
  // Set interrupt pin as input
  //  pinMode(APDS9960_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600); 

  // Initialize interrupt service routine
  //  attachInterrupt(0, interruptRoutine, FALLING);

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Start running the APDS-9960 gesture sensor engine
  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("Gesture sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }

}

void loop() {
if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        Serial.println("UP");
        break;
      
      case DIR_DOWN:
        Serial.println("DOWN");
        break;

      case DIR_LEFT:
        Serial.println("LEFT");
        break;

      case DIR_RIGHT:
        Serial.println("RIGHT");
        break;

      case DIR_NEAR:
        Serial.println("NEAR");
        break;

      case DIR_FAR:
        Serial.println("FAR");
        break;

      default:
        Serial.println("NONE");
    }
  }
delay(1000);
}
