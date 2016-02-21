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

void staticRedMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,   255);
        DmxSimple.write(GREEN,   0);
        DmxSimple.write(BLUE,    0);
    }
}

void staticYellowMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,   255);
        DmxSimple.write(GREEN, 255);
        DmxSimple.write(BLUE,    0);
    }
}

void staticGreenMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,     0);
        DmxSimple.write(GREEN, 255);
        DmxSimple.write(BLUE,    0);
    }
}

void staticCyanMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,     0);
        DmxSimple.write(GREEN, 255);
        DmxSimple.write(BLUE,  255);
    }   
}

void staticBlueMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,     0);
        DmxSimple.write(GREEN,   0);
        DmxSimple.write(BLUE,  255);
    }
}

void staticPurpleMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
        DmxSimple.write(RED,   255);
        DmxSimple.write(GREEN,   0);
        DmxSimple.write(BLUE,  255);
    }
}

