/* Welcome to DmxSimple. This library allows you to control DMX stage and
** architectural lighting and visual effects easily from Arduino. DmxSimple
** is compatible with the Tinker.it! DMX shield and all known DIY Arduino
** DMX control circuits.
**
** DmxSimple is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/dmxsimple       */

/* To use DmxSimple, you will need the following line. Arduino will
** auto-insert it if you select Sketch > Import Library > DmxSimple. */

#include <DmxSimple.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(2);
  DmxSimple.maxChannel(4);

  resetChannels();

  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome, this is");
  lcd.setCursor(0,1);
  lcd.print("SCARY PAR   V0.1");
}

void loop() {
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
}

void resetChannels()
{
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 0);
  DmxSimple.write(3, 0);
  DmxSimple.write(4, 0);
  DmxSimple.write(5, 0);
}
