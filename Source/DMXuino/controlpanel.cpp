//
// controlpanel.cpp
//
#include "controlpanel.h"

ControlPanel::ControlPanel(LiquidCrystal *lcd) :
    lastPressedKey(ControlPanel::kNoKey),
    currentMode(mIdle),
    display(lcd)
{
  // set up the LCD's number of columns and rows:
  display->begin(16, 2);
  // Welcome message
  display->setCursor(0,0);
  display->print("Welcome, this is");
  display->setCursor(0,1);
  display->print("SCARY PAR   V0.1");
}

void ControlPanel::updateControl()
{
    Key key = readKey();
    
    if(key != lastPressedKey)
    {
        if(key == ControlPanel::kUp)
            nextMode();
        if(key == ControlPanel::kDown)
            previousMode();
        if(key == ControlPanel::kEnter)
            select();
           
        displayMode();
    }            
    // update last key
    if(key != ControlPanel::kNoKey)
        lastPressedKey = key;
}

ControlPanel::Key ControlPanel::readKey() const
{
  Key pressedKey = kNoKey;
    
  int inValue = analogRead(0);
  
 if      (inValue <  50)  pressedKey = kRight;  
 else if (inValue < 250)  pressedKey = kUp; 
 else if (inValue < 450)  pressedKey = kDown; 
 else if (inValue < 650)  pressedKey = kLeft; 
 else if (inValue < 850)  pressedKey = kEnter;  
    
 return pressedKey;
}

void ControlPanel::nextMode()
{
    if(preselectedMode < mNoOfModes - 1)
        preselectedMode++;
}

void ControlPanel::previousMode()
{
    if(preselectedMode > 0)
        preselectedMode--;
}

void ControlPanel::select()
{
    currentMode = preselectedMode;
}

void ControlPanel::displayMode() const
{
    char *modeText;
    if(actualMode == preselectedMode)
        modeText = currentModeText(true);
    else
        modeText = currentModeText(false);
    
    lcd->setCursor(0,0);
    lcd->print(modeText);
}

char* ControlPanel::currentModeText(bool inCapitals) const
{
    if(inCapitals)
    {
        switch(preselectedMode)
        {
        case mIdle: return "";
        case mFadeRed: return "fade red";
        }
    }
    else
    {
        switch(preselectedMode)
        {
        case mIdle: return "";
        case mFadeRed: return "FADE RED";
        }
    }
}
