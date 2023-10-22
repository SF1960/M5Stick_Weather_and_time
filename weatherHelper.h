#include <exception>
#pragma once

#include "globals.h"
#include <ArduinoJson.h>                                //https://github.com/bblanchon/ArduinoJson.git
#include <HTTPClient.h>

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q="+townName+","+Country+"&units=metric&APPID=";
//const String key = "0b2bf4473af8e57be78b80d38d61a6f4";  // OpenWeather API Key

StaticJsonDocument<1536> doc;                           // set the Json object
//                                                      This was 1000. Json web recommends 1536
//                                                      See https://arduinojson.org/v6/assistant/#/step1

namespace ow{

  void getData() {

    if ((WiFi.status() == WL_CONNECTED)) {              //Check the current connection status
  
      HTTPClient http;
  
      http.begin(endpoint + key);                       //Specify the URL
      int httpCode = http.GET();                        //Make the request
  
      if (httpCode > 0) {                               //Check for the returning code
        Serial.println("Connected to ntp weather");
        Serial.print("Json payload :");
        M5.Lcd.printf("\nObtaining weather..");
        payload = http.getString(); 
        Serial.println(payload);
          
      } else {
        Serial.println("Error on HTTP request");
      }
  
      http.end();                                      //Free the resources

    }

    char inp[1536];                                    // was 1000                                  
    payload.toCharArray(inp,1536);                     // make a character for the payload was 1000
    deserializeJson(doc,inp);
    
    // Deserialise the OpenWeather data from Json file
    String tmp = doc["main"]["temp"];
    String tmpmin = doc["main"]["temp_min"];
    String tmpmax = doc["main"]["temp_max"];
    String tmpfeel = doc["main"]["feels_like"];
    String hum = doc["main"]["humidity"];
    String press = doc["main"]["pressure"];
    String wind = doc["wind"]["speed"];
    String deg = doc["wind"]["deg"];  
    String type = doc["weather"][0]["main"];
    String type1 = doc["weather"][0]["description"];
    String icon = doc["weather"][0]["icon"];
    String town = doc["name"];

    // set program global variables
    owTemp = tmp;
    owHum = hum;
    owWindSpeed = wind;
    owWindDirection = ""; // degreesText;
    townName = town;
    owMaxTemp = tmpmax;
    owMinTemp = tmpmin;
    owForecast = type;
    type.toUpperCase();
    owCurrentWeather = type;
    owWeatherIcon = icon;

    // display weather data on serial monitor
    Serial.printf("Temperature  :\t%sC\n", tmp);
    Serial.printf("Temp Minimum :\t%sC\n", tmpmin);
    Serial.printf("Temp Maximum :\t%sC\n", tmpmax);
    Serial.printf("Feels Like   :\t%sC\n", tmpfeel);
    Serial.printf("Pressure     :\t%shpA\n", press);
    Serial.printf("Rel Humidity :\t%s%%\n", hum);
    Serial.printf("Weather      :\t%s\n", type);
    Serial.printf("Now          :\t%s\n", type1);
    Serial.printf("Weather Icon :\t%s\n", icon);
    Serial.printf("Wind Speed   :\t%skph\n", wind);
    Serial.printf("Town/City    :\t%s\n", town);
    
    // set the weather font character to match the OpenWeather forecast
    // ** For CLEAR condition, if the icon value contains d then set day icon
    // ** if the icon value contains n then set the night icon
    // ** OpenWeather icon examples 01d 01n Clear. 10d 10n Rain. 13d 13n Snow. 
    if (owCurrentWeather == "CLEAR" && icon[2] == 'd'){
      Serial.printf("Day: CLEAR %s\n",icon);
      displayIcon = "B"; // ☼
    } else {
      Serial.printf("Night:CLEAR %s\n",icon);
      displayIcon = "C"; // ☾
    }
    if (owCurrentWeather == "CLOUDS") displayIcon = "N"; // ☁
    if (owCurrentWeather == "RAIN")   displayIcon = "R"; // 🌧
    if (owCurrentWeather == "THUNDER")displayIcon = "O"; // ⛈
    if (owCurrentWeather == "SNOW")   displayIcon = "W"; // ❅
    
  } //getData()

}
