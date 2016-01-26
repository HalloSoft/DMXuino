//
// controlpanel.h
//
#ifndef CONTROLPANEL   
#define CONTROLPANEL

#include "Arduino.h"

#include <LiquidCrystal.h>

#define MODE_IDLE      0
#define MODE_FADE_RED  1
#define MODE_FADE_BLUE 2
#define NO_OF_MODES    3

class ControlPanel
{
public:
    
    ControlPanel(LiquidCrystal *lcd);
    void updateControl();
    
    byte mode() const {return currentMode;}
    
private:
    enum Key{kNoKey, kUp, kDown, kRight, kLeft, kEnter};
    
    Key  readKey() const;
    void nextMode();
    void previousMode();
    void select();
    void displayMode() const;
    char* currentModeText(bool inCapitals) const;
    
    Key            lastPressedKey;
    byte           currentMode;
    byte           preselectedMode;
    LiquidCrystal *display;
    
};
#endif
