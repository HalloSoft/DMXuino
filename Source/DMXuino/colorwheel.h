// ---------------------------
// Project: DMXuino
// colorwheel.h
// created 2016-02-05
// HalloSoft
//
//------------------------------

#ifndef COLORWHEEL   
#define COLORWHEEL

#define RED   2
#define GREEN 3
#define BLUE  4

#include "Arduino.h"

void runColorWheelMode(unsigned int counter, unsigned int modulo);

//helper
void runSectionA(unsigned int counter);
void runSectionB(unsigned int counter);
void runSectionC(unsigned int counter);
void runSectionD(unsigned int counter);
void runSectionE(unsigned int counter);
void runSectionF(unsigned int counter);
int  correctBorders(int value);
#endif
