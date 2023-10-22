#pragma once
/**********************************************************************************************
*
* Library code for the ENVIII sensor module
*
* Library uses namespaces to return temperature, humidity and pressure from sensor
*
* Use functions...
*
*  sensor::setup();
*  sensTemp  = sensor::getTemperature();
*  sensHum   = sensor::getHumidity();
*  sensPress = sensor::getPressure();
*
**********************************************************************************************/

QMP6988 qmp6988;                                             // set the pressure object

Adafruit_SHT31 sht31 = Adafruit_SHT31();                     // set the temp/hum object

namespace sensor{

  void setup(){

    Wire.begin(32,33);                                          // Wire init, adding the I2C bus.
    qmp6988.init();                                             // start the ENVIII pressure sensor
    sht31.begin(0x44);                                          // start the ENVIII temp/hum sensor

  }

  float getTemperature(){  return sht31.readTemperature();  }

  float getHumidity()   {  return sht31.readHumidity();     }

  float getPressure()   {  return qmp6988.calcPressure();   }

}