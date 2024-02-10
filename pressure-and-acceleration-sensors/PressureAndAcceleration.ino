/*
  Pressure and Acceleration sensors
*/

/*
  IMPORTANT: To read from the sensors you need to install the Arduino_BHY2 and Arduino_BHY2Host libraries.
  We need to know the sensors ID in order to use them.
*/

/*Sensor classes:
   Sensor: This class handles sensors with a single measurement value to be read (pressure) and also the sensors. This generic sensor class provides the sensor data through the value property that returns a float.
   SensorXYZ: handles accelerometer and gyroscope.
   SensorActivity: Use this class to handle sensors with the activity format. 

   Taken from: https://docs.arduino.cc/tutorials/nicla-sense-me/cheat-sheet#sensor-classes 
*/

#include "Arduino_BHY2.h"

//Virtual Sensor - SENSOR_ID_BARO - provides the values from the BMP390.
Sensor barometer(SENSOR_ID_BARO);
// Virtual Sensor - SENSOR_ID_ACC_PASS - provides the values from the BHI260AP. 
SensorXYZ accelerometer(SENSOR_ID_ACC_PASS);

void setup() {
  // Ativate the sensors
  Serial.begin(9600); // begin function: function starts the sensor by calling the configure() with default parameters, making it easy to start and use on-board sensors.
  BHY2.begin();

  barometer.begin(); 
  accelerometer.begin();
}

void loop() {
  static auto lastCheck = millis();
  
  //Uncomment for cycle if you want to take only 1000 measurements.
  //for (int measurementCounter = 0; measurementCounter < 1001; measurementCounter = measurementCounter + 1) {

    // Update function should be continuously polled
       BHY2.update();

      //take values of accelerometer in all three axis + adjust sensitivity 
      //To obtain the acceleration, you must divide the raw value by 4096 and multiply by 9.81 m s–2. 
      short accX = ((accelerometer.x())/4096)*(9.81);
      short accY = ((accelerometer.y())/4096)*(9.81);
      short accZ = ((accelerometer.z())/4096)*(9.81);

      // Check sensor values every 100ms/ 0.1 sec
      if(millis() - lastCheck >= 100){
        lastCheck = millis();
      }
  
    Serial.println(String(barometer.value()));
    Serial.println(String(accelerometer.toString()));
    Serial.println(millis());

  //}

  //exit(0);

}
