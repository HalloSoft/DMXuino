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

#define MODE_IDLE              0
#define MODE_STATIC_WHITE      1
#define MODE_STATIC_RED        2
#define MODE_STATIC_YELLOW     3
#define MODE_STATIC_GREEN      4
#define MODE_STATIC_CYAN       5
#define MODE_STATIC_BLUE       6
#define MODE_STATIC_PURPLE     7
#define MODE_COLORWHEEL_SLOW   8
#define MODE_COLORWHEEL_NORMAL 9
#define MODE_COLORWHEEL_FAST  10
#define MODE_STROBO_RED       11
#define MODE_STROBO_GREEN     12
#define MODE_STROBO_BLUE      13
#define MODE_COLORSTROBO      14
#define MODE_COLORSTROBO2     15

#define NUMBER_OF_MODES       16 // <-- Here number of modes

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
