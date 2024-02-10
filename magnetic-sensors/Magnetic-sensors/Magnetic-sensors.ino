/*
 Magnetic sensors
*/

/*
  IMPORTANT: To read from the sensors you need to install the Arduino_BHY2 and Arduino_BHY2Host libraries.
  We need to know the sensors ID in order to use them.
*/

/*Sensor classes:
   Sensor: This class handles sensors with a single measurement value to be read and also the event sensors. This generic sensor class provides the sensor data through the value property that returns a float.
   SensorXYZ: This class handles sensors with the XYZ format.
   SensorActivity: Use this class to handle sensors with the activity format. 

   Taken from: https://docs.arduino.cc/tutorials/nicla-sense-me/cheat-sheet#sensor-classes 
*/

#include "Arduino_BHY2.h"

// Virtual Sensor - SENSOR_ID_MAG_PASS - provides the passthrough values from the BMM150. 
SensorXYZ magn(SENSOR_ID_MAG_PASS);


void setup() {
  // Ativate the sensors
  Serial.begin(9600); // begin function: function starts the sensor by calling the configure() with default parameters, making it easy to start and use on-board sensors.
  BHY2.begin();

  magn.begin(); 
}

void loop() {
  static auto lastCheck = millis();
  
  //Uncomment for cycle if you want to take only 1000 measurements.
  //for (int measurementCounter = 0; measurementCounter < 1001; measurementCounter = measurementCounter + 1) {

    // Update function should be continuously polled
  BHY2.update();
      
  //take values of magnetic field intensity in all three directions (Bx, By and Bz)
  short bX = magn.x();
  short bY = magn.y();
  short bZ = magn.z();


      // Check sensor values every 100ms/ 0.1 sec
  if(millis() - lastCheck >= 100){
    lastCheck = millis();

    //Serial.println(lastCheck);
    Serial.println(String(magn.toString()));
  }


  //}

  //exit(0);

}
