// ---------------------------
// Project: DMXuino
// strobomodes.cpp
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "strobomodes.h"
#include <DmxSimple.h>

byte flashColor = RED;
bool lightIsOn = false;


void rgbStoboMode(unsigned int counter)
{
    byte redValue = 0;
    byte greenValue = 0;
    byte blueValue = 0;

    if(flashColor == RED)
        redValue = 255;
    if(flashColor == GREEN)
        greenValue = 255;
    if(flashColor == BLUE)
        blueValue = 255;

    if(!lightIsOn)
    {
        redValue = 0;
        greenValue = 0;
        blueValue = 0;
    }
        
    DmxSimple.write(RED,   redValue);
    DmxSimple.write(GREEN, greenValue);
    DmxSimple.write(BLUE,  blueValue);

    byte stroboCounter = counter % 5;
    if(stroboCounter == 0)
    {
        lightIsOn = true;
        flashColor = nextFlashColor(flashColor);
    }
    else
        lightIsOn = false;
}

byte nextFlashColor(byte currentColor)
{
    byte result;
    
    if(currentColor != BLUE)
        result = currentColor + 1;
    else
        result = RED;
        
    return result;
}
