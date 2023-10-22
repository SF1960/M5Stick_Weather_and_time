#pragma once

#include "globals.h"

/*******************************************************************************
*
* Set up the serial monitor with BAUD rate passed from calling function
*
*******************************************************************************/

namespace serial{

  void setup(int BAUD){

    Serial.begin(BAUD);
    delay(1000);
    Serial.printf("Serial started at %d\n", BAUD);

  }

}