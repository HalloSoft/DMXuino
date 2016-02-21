
// ---------------------------
// Project: DMXuino
// staticlight.h
// created 2016-02-01
// HalloSoft
//
//------------------------------

#ifndef STATICLIGHT   
#define STATICLIGHT

#define RED   2
#define GREEN 3
#define BLUE  4

#include "Arduino.h"

void staticWhiteMode(unsigned int counter);
void staticRedMode(unsigned int counter);
void staticYellowMode(unsigned int counter);
void staticGreenMode(unsigned int counter);
void staticCyanMode(unsigned int counter);
void staticBlueMode(unsigned int counter);
void staticPurpleMode(unsigned int counter);

#endif //STATICLIGHT

