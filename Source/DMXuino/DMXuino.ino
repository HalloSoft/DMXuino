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

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
ControlPanel *panel;
unsigned int liveCounter;
byte cycles;

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
    // End of the main-loop
    ++liveCounter;
    panel->updateControl();

    if (liveCounter == 0)
        ++cycles;

    if(panel->mode() == MODE_IDLE)
        
        
    if(panel->mode() == MODE_FADE_RED)
        runFadeRedMode(liveCounter);

    switch(panel->mode())
    {
    case MODE_IDLE:
        runBlackMode(liveCounter);
        break;
    case MODE_FADE_RED:
        runFadeRedMode(liveCounter);
        break;
    case MODE_FADE_GREEN:
        runFadeGreenMode(liveCounter);
        break;
    case MODE_FADE_BLUE:
        runFadeBlueMode(liveCounter);
        break;    
    }

    // Cycle delay
    delay(1);

}

void resetChannels()
{
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 0);
  DmxSimple.write(3, 0);
  DmxSimple.write(4, 0);
  DmxSimple.write(5, 0);
}
