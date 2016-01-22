
#include <DmxSimple.h>
#include <LiquidCrystal.h>
#include "controlpanel.h"

//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
ControlPanel *panel;
int liveCounter;
byte cycles;

void setup() 
{
  DmxSimple.usePin(2);
  DmxSimple.maxChannel(4);
  resetChannels();

  Serial.begin(9600);
  
  panel = new ControlPanel(&lcd);
  
  liveCounter = 0;
  cycles      = 0;
}

void loop() 
{  
  panel->updateControl();
  
  for(int channel = 2; channel <= 4; ++channel)
  { 
    resetChannels();
    
    for (int brightness = 0; brightness <= 255; brightness++) 
    {  
      /* Update DMX channel 1 to new brightness */
      DmxSimple.write(channel, brightness);
      Serial.println(brightness);
      Serial.println("Here");
      
      /* Small delay to slow down the ramping */
      delay(20);
    }
  }
  
  // End of the main-loop
  ++liveCounter;
  
  if(liveCounter == 0)
      ++cycles;
}

void resetChannels()
{
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 0);
  DmxSimple.write(3, 0);
  DmxSimple.write(4, 0);
  DmxSimple.write(5, 0);
}
