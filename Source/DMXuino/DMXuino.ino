// ---------------------------
// Project: DMXuino
// DMXuino.ino
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include <DmxSimple.h>
#include <LiquidCrystal.h>

#include "controlpanel.h"
#include "programs.h"
#include "colorwheel.h"
#include "staticlight.h"



LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
ControlPanel *panel;
unsigned int liveCounter;
byte cycles;

unsigned long lastTimeStamp = 0;

void setup()
{
  DmxSimple.usePin(2);
  DmxSimple.maxChannel(4);
  resetChannels();

  Serial.begin(9600);
  Serial.println("Scary Par");

  panel = new ControlPanel(&lcd);

  liveCounter = 0;
  cycles      = 0;
}

void loop()
{
    panel->updateControl();

    if (liveCounter == 0)
        ++cycles;


    switch(panel->mode())
    {
    case MODE_IDLE:
        runBlackMode(liveCounter);
        break;
    case MODE_STATIC_WHITE:
        staticWhiteMode(liveCounter);
        break;
    case MODE_STATIC_RED:
        staticRedMode(liveCounter);
        break;
    case MODE_STATIC_YELLOW:
        staticYellowMode(liveCounter);
        break;    
    case MODE_STATIC_GREEN:
        staticGreenMode(liveCounter);
        break;
    case MODE_STATIC_CYAN:
        staticCyanMode(liveCounter);
        break;
    case MODE_STATIC_BLUE:
        staticBlueMode(liveCounter);
        break;
    case MODE_STATIC_PURPLE:
        staticPurpleMode(liveCounter);
        break;
    case MODE_COLORWHEEL_SLOW:
        runColorWheelMode(liveCounter, 16384);
        break;
    case MODE_COLORWHEEL_NORMAL:
        runColorWheelMode(liveCounter, 4096);
        break;
    case MODE_COLORWHEEL_FAST:
        runColorWheelMode(liveCounter, 128);
        break;
    case MODE_STROBO_RED:
        runStroboRedMode(liveCounter);
        break;
    case MODE_STROBO_GREEN:
        runStroboGreenMode(liveCounter);
        break;
    case MODE_STROBO_BLUE:
        runStroboBlueMode(liveCounter);
        break;
    case MODE_COLORSTROBO:
        runColorWheelMode(liveCounter, 4096, true);
        break;
    }


    // End of the main-loop
    ++liveCounter;
    
    // Cycle delay
    delay(20);

    // Measureing time
//    unsigned long currentTimeStamp = millis();
//    unsigned long loopTime = currentTimeStamp - lastTimeStamp;
//    lastTimeStamp = currentTimeStamp; 
//    Serial.print("Looptime :");
//    Serial.print(loopTime);
//    Serial.println(" ms");

}


