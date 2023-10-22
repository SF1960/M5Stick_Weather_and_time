#include "rom/rtc.h"
#pragma once

#include "globals.h"

namespace stick {

  void setup(){

    M5.begin();
    M5.Lcd.setTextSize(2);                    // set text size
    M5.Lcd.setRotation(3);                    // Rotate the screen.

  } // setup()

  void LcdDefault(){

    M5.Lcd.setRotation(4);                    // rotate to vertical

  } // LcdDefault

  void getM5BatteryData(){

    M5VBat = M5.Axp.GetVbatData() * 1.1 / 1000;
    intCharge = M5.Axp.GetBatCurrent();
    USBVin = M5.Axp.GetVBusVoltage();
    M5BatTemp = M5.Axp.GetTempData()*0.1-144.7;
    batchargeCurrent = M5.Axp.GetBatChargeCurrent();

  }

  /* set the cursor to home position and set default text parameters */
  void cursorHome(){

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE, BLACK);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0, 1);

  }

}