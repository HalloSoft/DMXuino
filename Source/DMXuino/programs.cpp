// ---------------------------
// Project: DMXuino
// programms.cpp
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "programs.h"
#include <DmxSimple.h>

void runBlackMode(unsigned int counter)
{
    if(counter%1000 == 0)
        Serial.println("Black Mode");
//  DmxSimple.write(1, 0);
//  DmxSimple.write(2, 0);
//  DmxSimple.write(3, 0);
//  DmxSimple.write(4, 0);
//  DmxSimple.write(5, 0);
}

void runFadeRedMode(unsigned int counter)
{
    if(counter%300 == 0)
        Serial.println("Fade Red Mode");
}

void runFadeGreenMode(unsigned int counter)
{
    if(counter%300 == 0)
        Serial.println("Fade Green Mode");
}

void runFadeBlueMode(unsigned int counter)
{
    if(counter%300 == 0)
        Serial.println("Fade Blue Mode");
}
