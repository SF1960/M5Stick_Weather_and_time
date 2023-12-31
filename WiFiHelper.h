#pragma once

#include "globals.h"

namespace wifi {

  // connect to ssid using password and return true or false
  bool connect(String ssid, String password){

    //connect to WiFi
    Serial.printf("Connecting to %s ", ssid);
    M5.Lcd.printf("Connecting.");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());

    int tries = 0;
    while (WiFi.status() != WL_CONNECTED) {
      M5.Lcd.printf(".");
      delay(CONN_TIMEOUT);
      if (tries++ >= CONN_ATTEMPTS){ return false; } // failed to connect
    }
    
    M5.Lcd.printf("\nStarting Arduino..");

    return true;                                     // connection successful

  } // connect()

  // error connection message
  void connectError(String ssid){

    M5.Lcd.setTextColor(RED, BLACK);         
    M5.Lcd.printf("\n\nFailed to connect to\n");
    M5.Lcd.printf("\n%s\n", ssid);

    M5.Lcd.setTextColor(WHITE, BLACK);     
    M5.Lcd.printf("\nTrying alternative.");

    delay(MESSAGE_DELAY);
    stick::cursorHome();

  } // connectError()

  // display final connections failed message
  void connectionFailed(){

    stick::cursorHome();
    M5.Lcd.setTextColor(RED, BLACK);
    M5.Lcd.printf("\n\nFAILED TO CONNECT\n\n");
    M5.Lcd.printf("TO ANY WIFI NETWORK");
    M5.Lcd.setTextColor(WHITE, BLACK);
    M5.Lcd.printf("\n\nReattempt in 10s.");

  } // connecttionFailed()

  // when connected to the internet display success
  void connected(String ssid){

    stick::cursorHome();
    M5.Lcd.setTextColor(GREEN, BLACK);         
    M5.Lcd.printf("CONNECTED to\n\n");

    M5.Lcd.setTextColor(WHITE, BLACK);         
    M5.Lcd.printf("%s\n", ssid.c_str());
    M5.Lcd.print("IP: "); M5.Lcd.println(WiFi.localIP());

  } // connected()

  // connect to the ntp server
  void ntp(){

    //init and get the time
    Serial.printf("Obtaining WWW time..\n");
    M5.Lcd.printf("\nObtaining WWW time..");
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);   // get the internet time
    delay(1000);

  } // ntp()

  void disconnect(){

    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);

  } // disconnect()

}