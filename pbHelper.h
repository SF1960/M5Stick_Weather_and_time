#include "esp32-hal-gpio.h"
#pragma once

/********************************************************************************
*
* Library for Pushbutton
*
* Use functions...
*
* buttons::setup();
* if (buttons::PBhome() == PRESSED)
* if (buttons::PBreset() ==PRESSED)
*
********************************************************************************/

#define homePB 37                         // Home PB connected to GPIO Pin 37
#define resetPB 39                        // Reset PB connected to GPIO Pin 39

namespace buttons{

  void setup(){

    pinMode(homePB, INPUT_PULLUP);        // set up the large button as Home
    pinMode(resetPB,INPUT_PULLUP);        // set up the smaller button as reset

  }

  int PBhome(){

    return digitalRead(homePB);           // return the state of the PB. 0 == PRESSED

  }

  int PBreset(){

    return digitalRead(resetPB);           // return the state of the PB. 0 == PRESSED

  }

}