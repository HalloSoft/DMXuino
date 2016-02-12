// ---------------------------
// Project: DMXuino
// programms.cpp
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "programs.h"
#include <DmxSimple.h>

bool isFadingIn = true;

void resetChannels()
{
    DmxSimple.write(1, 0);
    DmxSimple.write(RED, 0);
    DmxSimple.write(GREEN, 0);
    DmxSimple.write(BLUE, 0);
    DmxSimple.write(5, 0);
}

void runBlackMode(unsigned int counter)
{
    if(counter%50 == 0)
    {
//        Serial.println("Black Mode");
        
        DmxSimple.write(1, 0);
        DmxSimple.write(RED, 0);
        DmxSimple.write(GREEN, 0);
        DmxSimple.write(BLUE, 0);
        DmxSimple.write(5, 0);
    }
}

void runFadeRedMode(unsigned int counter)
{       
    int fadeValue = calculateFadeValue(counter);     
    DmxSimple.write(RED, fadeValue);
    DmxSimple.write(GREEN, 0);
    DmxSimple.write(BLUE, 0);
    
}

void runFadeGreenMode(unsigned int counter)
{         
    int fadeValue = calculateFadeValue(counter);
    DmxSimple.write(RED, 0);
    DmxSimple.write(GREEN, fadeValue);
    DmxSimple.write(BLUE, 0);
    
//    if(counter%300 == 0)
//        Serial.println("Fade Green Mode");
}

void runFadeBlueMode(unsigned int counter)
{
    int fadeValue = calculateFadeValue(counter);
    DmxSimple.write(RED, 0);
    DmxSimple.write(GREEN, 0);
    DmxSimple.write(BLUE, fadeValue);
        
//    if(counter%300 == 0)
//        Serial.println("Fade Blue Mode");
}

void runStroboRedMode(unsigned int counter)
{   
    int value = calculateStroboValue(counter);
    DmxSimple.write(RED, value);
    DmxSimple.write(GREEN, 0);
    DmxSimple.write(BLUE, 0);    
}

void runStroboGreenMode(unsigned int counter)
{   
    int value = calculateStroboValue(counter);
    DmxSimple.write(RED, 0);
    DmxSimple.write(GREEN, value);
    DmxSimple.write(4, 0);
    
}

void runStroboBlueMode(unsigned int counter)
{   
    int value = calculateStroboValue(counter);
    DmxSimple.write(RED, 0);
    DmxSimple.write(GREEN, 0);
    DmxSimple.write(4, value);
    
}

void runStroboWhiteMode(unsigned int counter)
{   
    int value = calculateStroboValue(counter);
    DmxSimple.write(RED, value);
    DmxSimple.write(GREEN, value);
    DmxSimple.write(4, value);
    
}

// Helper
int calculateFadeValue(unsigned int counter)
{
    const int moduloValue = 512; // should be 2^x
    
    int fadeCounter = counter % moduloValue;

    if(!isFadingIn)
        fadeCounter = moduloValue - fadeCounter - 1;
        
    int fadeValue = fadeCounter * 256 / moduloValue;

    bool fadeInAtEnd = (fadeCounter == moduloValue -1) && isFadingIn;
    bool fadeOutAtEnd = (fadeCounter == 0) && !isFadingIn;

//    Serial.print(counter);
//    Serial.print(" - ");
//    Serial.print(fadeCounter);
//    if(isFadingIn) Serial.println(" - Fading in");
//    else           Serial.println(" - Fading out");

    if(fadeInAtEnd || fadeOutAtEnd)
    {
        if(isFadingIn) isFadingIn = false;
        else           isFadingIn = true;
    }

    return fadeValue;
}

int calculateStroboValue(unsigned int counter)
{
    const int stroboTime =  3; // in cycles

    int stroboCounter = counter % (2 * stroboTime);

    int value = 0; 
    if(stroboCounter > stroboTime * 1.5)
        value = 255;

    return value;
}


