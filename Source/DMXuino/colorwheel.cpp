// ---------------------------
// Project: DMXuino
// colorwheel.cpp
// created 2016-02-05
// HalloSoft
//
//------------------------------

#include "colorwheel.h"
#include <DmxSimple.h>

int sectionSize = 1; 

void runColorWheelMode(unsigned int counter)
{
    unsigned int wheelCounter = counter % 512; // Maybe scale time here

    Serial.print("Wheelcounter:");
    Serial.print(wheelCounter);
    Serial.print("  ");
    

    //int sectionSize = 65535 / 6;
    sectionSize = 512 / 6;

    if(wheelCounter < sectionSize)
        runSectionA(wheelCounter);

    if((wheelCounter >= sectionSize) && (wheelCounter < sectionSize *2))
        runSectionB(wheelCounter);

    if((wheelCounter >= sectionSize * 2) && (wheelCounter < sectionSize * 3))
        runSectionC(wheelCounter);

    if((wheelCounter >= sectionSize * 3) && (wheelCounter < sectionSize * 4))
        runSectionD(wheelCounter);

    if((wheelCounter >= sectionSize * 4) && (wheelCounter < sectionSize * 5))
        runSectionE(wheelCounter);

    if(wheelCounter >= sectionSize * 5)
        runSectionF(wheelCounter);
         
    
}


void runSectionA(unsigned int counter)
{
    int value = 255  * counter / sectionSize;
    
    DmxSimple.write(BLUE,      0);
    DmxSimple.write(RED,     255);
    DmxSimple.write(GREEN, value);

    Serial.print("Sectoin A - ");
    Serial.print("Green: ");
    Serial.println(value);
    
}

void runSectionB(unsigned int counter)
{
    long value = (-255l)  * counter / sectionSize + 2 * 255;

    DmxSimple.write(GREEN, 255);
    DmxSimple.write(BLUE,    0);
    DmxSimple.write(RED, value);

    Serial.print("Sectoin B - ");

    Serial.print("sectionsize; ");
    Serial.print(sectionSize);
    Serial.print("Red: ");
    Serial.println(value);
}

void runSectionC(unsigned int counter)
{
    int value = 255  * counter / sectionSize - 2 * 255;

    DmxSimple.write(GREEN, 255);
    DmxSimple.write(BLUE, value);
    DmxSimple.write(RED,     0);

    Serial.print("Sectoin C - ");
    Serial.print("Blue: ");
    Serial.println(value);
}

void runSectionD(unsigned int counter)
{
    Serial.print("Sectoin D - ");
    Serial.println();
}

void runSectionE(unsigned int counter)
{
    Serial.print("Sectoin E - ");
    Serial.println();
    
}

void runSectionF(unsigned int counter)
{
    Serial.print("Sectoin F - ");
    Serial.println();
    
}

