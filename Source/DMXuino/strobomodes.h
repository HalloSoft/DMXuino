// ---------------------------
// Project: DMXuino
// strobomodes.h
// created 2016-02-21
// HalloSoft
//
//------------------------------

#ifndef STROBOMODES  
#define STROBOMODES

#define BLACK 0
#define RED   2
#define GREEN 3
#define BLUE  4

#include "Arduino.h"

void rgbStoboMode(unsigned int counter);

// Helper
byte nextFlashColor(byte currentColor);

#endif //STROBOMODES
