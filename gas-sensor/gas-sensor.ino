/*
  Gas sensors
*/

/*
  IMPORTANT: To read from the sensors you need to install the Arduino_BHY2 and Arduino_BHY2Host libraries.
  We need to know the sensors ID in order to use them.
  For module #3, the library Bosch Software Environmental Cluster is used. 
*/

/*Sensor classes:
   Sensor: This class handles sensors with a single measurement value to be read and also the event sensors. This generic sensor class provides the sensor data through the value property that returns a float.
   SensorActivity: Use this class to handle sensors with the activity format. 

   Taken from: https://docs.arduino.cc/tutorials/nicla-sense-me/cheat-sheet#sensor-classes 
*/

#include "Arduino_BHY2.h"

// Virtual Sensor - SENSOR_ID_GAS - provides the direct readout of the MOX from the BME688. 
Sensor gas(SENSOR_ID_GAS);
// Virtual Sensor - SENSOR_ID_BSEC
SensorBSEC bsec(SENSOR_ID_BSEC);


void setup() {
  // Ativate the sensors
  Serial.begin(9600); // begin function: function starts the sensor by calling the configure() with default parameters, making it easy to start and use on-board sensors.

  BHY2.begin();
  gas.begin();
  bsec.begin(); 
}

void loop() {
  static auto lastCheck= millis();
   // Update function should be continuously polled
  BHY2.update();
  // returns the resistance in Ohms
  float resistanceValue = gas.value(); 
  

  // Check sensor values every 10 second  
  if (millis() - lastCheck >= 10000) {
    lastCheck = millis();
    //Serial.println(String("gas: ") + String(gas.value()));
    Serial.println(bsec.toString());
  }

}
