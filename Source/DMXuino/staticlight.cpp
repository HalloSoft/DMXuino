// ---------------------------
// Project: DMXuino
// staticlight.cpp
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "staticlight.h"
#include <DmxSimple.h>

void staticWhiteMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,   255);
        DmxSimple.write(GREEN, 255);
        DmxSimple.write(BLUE,  255);
    }
}

