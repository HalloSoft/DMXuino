//
// controlpanel.h
//
#ifndef CONTROLPANEL   
#define CONTROLPANEL

#include "Arduino.h"

#include <LiquidCrystal.h>

class ControlPanel
{
public:
    enum OperationMode{ mIdle, mFadeRed, mNoOfModes};
    
    ControlPanel(LiquidCrystal *lcd);
    void updateControl();
    
    OperationMode mode() const {return currentMode;}
    
private:
    enum Key{kNoKey, kUp, kDown, kRight, kLeft, kEnter};
    
    Key  readKey() const;
    void nextMode();
    void previousMode();
    void select();
    void displayMode() const;
    char* currentModeText(bool inCapitals) const;
    
    Key            lastPressedKey;
    OperationMode  currentMode;
    OperationMode  preselectedMode;
    LiquidCrystal *display;
    
};
#endif
