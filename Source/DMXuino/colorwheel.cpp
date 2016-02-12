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

void runColorWheelMode(unsigned int counter, unsigned int modulo, bool strobo)
{
    //const int modulo = 4096; // should be 2^x -- higher values, longer cycle
    unsigned int wheelCounter = counter % modulo; // Maybe scale time here

//    Serial.print("Wheelcounter:");
//    Serial.print(wheelCounter);
//    Serial.print("  ");

    if(!strobo || calculateStroboOn(wheelCounter))
    {
    
        //int sectionSize = 65535 / 6;
        sectionSize = modulo / 6;
    
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
    else
    {
        DmxSimple.write(BLUE,  0);
        DmxSimple.write(RED,   0);
        DmxSimple.write(GREEN, 0);
    }
          
}


void runSectionA(unsigned int counter)
{
    int value = 255l  * counter / sectionSize;
    value = correctBorders(value);
    
    DmxSimple.write(BLUE,      0);
    DmxSimple.write(RED,     255);
    DmxSimple.write(GREEN, value);

//    Serial.print("Sectoin A - ");
//    Serial.print("Green: ");
//    Serial.println(value);
    
}

void runSectionB(unsigned int counter)
{
    long value = (-255l)  * counter / sectionSize + 2 * 255;
    value = correctBorders(value);

    DmxSimple.write(GREEN, 255);
    DmxSimple.write(BLUE,    0);
    DmxSimple.write(RED, value);

//    Serial.print("Sectoin B - ");
//    Serial.print("Red: ");
//    Serial.println(value);
}

void runSectionC(unsigned int counter)
{
    int value = 255l  * counter / sectionSize - 2 * 255;
    value = correctBorders(value);

    DmxSimple.write(GREEN, 255);
    DmxSimple.write(BLUE, value);
    DmxSimple.write(RED,     0);

//    Serial.print("Sectoin C - ");
//    Serial.print("Blue: ");
//    Serial.println(value);
}

void runSectionD(unsigned int counter)
{
    int value = -255l  * counter / sectionSize + 4 * 255;
    value = correctBorders(value);
   
    DmxSimple.write(BLUE,   255);
    DmxSimple.write(RED,      0);
    DmxSimple.write(GREEN,value); 
    
//    Serial.print("Sectoin D - ");
//    Serial.print("Green: ");
//    Serial.println(value);
}

void runSectionE(unsigned int counter)
{
    int value =  255l  * counter / sectionSize - 4 * 255;
    value = correctBorders(value);
    
    DmxSimple.write(GREEN,   0);
    DmxSimple.write(BLUE,  255);
    DmxSimple.write(RED, value);
    
//    Serial.print("Sectoin E - ");
//    Serial.print("Red: ");
//    Serial.println(value);
    
}

void runSectionF(unsigned int counter)
{
    int value =  -255l  * counter / sectionSize + 6 * 255;

    value = correctBorders(value); 

    DmxSimple.write(GREEN,    0);
    DmxSimple.write(RED,    255);
    DmxSimple.write(BLUE, value);
    
//    Serial.print("Sectoin F - ");
//    Serial.print("Blue: ");
//    Serial.println(value);
}

int correctBorders(int value) 
{
    value = value < 0 ? 0 : value;
    value = value > 255 ? 255 : value;
    
    return value;
}

bool calculateStroboOn(unsigned int counter)
{
    const int stroboTime =  3; // in cycles

    int stroboCounter = counter % (2 * stroboTime);

    bool value = false; 
    if(stroboCounter > stroboTime * 1.5)
        value = true;

    return value;
}

