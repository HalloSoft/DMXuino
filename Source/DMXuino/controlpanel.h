// ---------------------------
// Project: DMXuino
// controlpanel.h
// created 2016-02-01
// HalloSoft
//
//------------------------------


#ifndef CONTROLPANEL   
#define CONTROLPANEL

#include "Arduino.h"

#include <LiquidCrystal.h>

#define MODE_IDLE         0
#define MODE_FADE_RED     1
#define MODE_FADE_GREEN   2
#define MODE_FADE_BLUE    3
#define MODE_STROBO_RED   4
#define MODE_STROBO_GREEN 5
#define MODE_STROBO_BLUE  6
#define NUMBER_OF_MODES   7 // <-- Here number of modes

#define DELAYTIME 300 // ms

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
    void block();
    void checkBlocking();
    
    Key  lastPressedKey;
    byte currentMode;
    byte preselectedMode;
    bool isBlocked;

    unsigned long lastKeyEvent;
    LiquidCrystal *display;
    
};
#endif
