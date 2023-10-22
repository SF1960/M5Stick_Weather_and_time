# weather_time
Obtain weather and time data from the internet and display on an M5StickCPlus together with data from an ENVIII sensor  
It also allows for connection to Arduino IOT

## Description
M5 Stick code for weather, battery, time display and Arduino IOT Integration.
The program obtains the time from the internet ntp servers and the weather data from OpenWeather.
It uses a connected ENVIII sensor for temperature, humidity and pressure for local data.

## Requirements
1. A free Arduino IOT account [Account](https://cloud.arduino.cc/plans)
2. An API key from OpenWeather using free account [Sign Up](https://openweathermap.org/api/one-call-3)
3. An ENVIII sensor from M5 [Shop](https://shop.m5stack.com/products/env-iii-unit-with-temperature-humidity-air-pressure-sensor-sht30-qmp6988)
4. A connection with an ntp time server [ntp server](https://europe.pool.ntp.org)
5. Arduino IDE programming environment [Get IDE](https://docs.arduino.cc/software/ide-v2)

## Program Setup
You will need to set **local parameters** to make the code work properly
1. Your WiFi credentials. The code allows for 3 networks to be connected.
2. Your OpenWeather API key
3. Your Town and Country for the weather forecast
4. How often you would like the weather to be updated
5. How often the Arduino IOT should be updated

In the **globals.h** tab change the following WEATHER data

> const String key = "0b2bf4473af8e57be78b80d38d61a6f4";     
> #define TOWN "Crawley"  
> #define COUNTRY "GB"  
> #define GMT_OFFSET 3600  
> #define SUMMER_TIME_OFFSET 0  

In the **globals.h** tab change how often the code asks for updates from the internet

> #define OW_INTERVAL_MINS 1   
> #define IOT_INTERVAL_SECS 5  

In the **globals.h** tab change enter your WiFi credentials within the double-quotes  

> const char* ssid       = "SSID";  
> char* char* password   = "PASSWORD";  
> const char* ssid2      = "SSID2";  
> const char* password2  = "PASSWORD2";  
> const char* ssid3      = "SSID3";  
> const char* password3  = "PASSWORD3";

## Arduino IOT Setup
1. Obtain a free IOT account (see link above)
2. **Connect** your M5 to Arduino using CREATE in the **Devices** tab
3. Setup a **Thing** using CREATE in the **Things** tab. Use the following variables..  

ADD Arduino Cloud Variables to your **Thing**.  
Select each variable type as ***float*** and then enter the **EXACT** variable name as shown here.  
***Observe case rules for the names***  

> float chargeBAT  
  float dischargeBAT  
  float sensorHUM  
  float sensorPRES  
  float sensorTEMP  
  float tempBAT  
  float voltageBAT  
  float voltageUSB  
>

Set up a **Dashboard** using CREATE in the **Dasboards** tab.  

## Installation
1. Connect the USB to your IDE and the M5
2. Connect the ENVIII module to the M5
3. Upload the code to the M5
4. View data on screen
5. View data on Arduino Dashboard or mobile device

## Operation
1. Press the home button to scroll through the screens
2. Press the reset button to change the brightness of the screen

## Powering the M5
The M5 can be powered by USB  
It also has an internal battery which can power the device for around an hour using this code.  
To power down the device press the On/Off button for 6 seconds.   
To power on the device press the On/Off button for 2 seconds.  
The M5 will automatically connect to an available WiFi connection and obtain the time and weather.   

## Fault Finding and Correction
The most common issues with a malfunctioning unit are...    
1. The WiFi is unable to connect due to...
  - No WiFi signal available
  - Incorrect WiFi credentials
2. Incorrect Cloud Variables added to Arduino Thing

 
