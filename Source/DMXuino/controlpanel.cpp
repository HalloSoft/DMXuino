
// ---------------------------
// Project: DMXuino
// controlpanel.cpp
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "controlpanel.h"

ControlPanel::ControlPanel(LiquidCrystal *lcd) :
  lastPressedKey(ControlPanel::kNoKey),
  currentMode(MODE_IDLE),
  preselectedMode(MODE_IDLE),
  isBlocked(false),
  display(lcd)
{
    lastKeyEvent = millis();
  
    // set up the LCD's number of columns and rows:
    display->begin(16, 2);
  
    // Welcome message
    display->setCursor(0, 0);
    display->print("Welcome, this is");
    display->setCursor(0, 1);
    display->print("SCARY PAR   V0.4");
}

void ControlPanel::updateControl()
{
    if(!isBlocked)
    {
        Key key = readKey();

        if (key != kNoKey)
        {
            if (key == ControlPanel::kUp)
                nextMode();
            if (key == ControlPanel::kDown)
                previousMode();
            if (key == ControlPanel::kEnter)
                select();

            displayMode();
            block();
        }
        
        // update last key
        if (key != ControlPanel::kNoKey)
            lastPressedKey = key;
    }

    checkBlocking();
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

  // Debug
//  if (pressedKey != lastPressedKey)
//  {
//    if (pressedKey == kRight) Serial.println("Key Right");
//    if (pressedKey == kUp)    Serial.println("Key Up");
//    if (pressedKey == kDown)  Serial.println("Key Down");
//    if (pressedKey == kLeft)  Serial.println("Key Left");
//    if (pressedKey == kEnter) Serial.println("Enter");
//  }

  return pressedKey;
}

void ControlPanel::nextMode()
{
  if (preselectedMode < NUMBER_OF_MODES - 1)
    preselectedMode++;
}

void ControlPanel::previousMode()
{
  if (preselectedMode > 0)
    preselectedMode--;
}

void ControlPanel::select()
{
  currentMode = preselectedMode;
  displayMode();
}

void ControlPanel::displayMode() const
{
//    Serial.print(preselectedMode);
//    Serial.print(" ");
//    Serial.println(currentMode);  
    display->setCursor(0, 0);

    if(preselectedMode == 0)
        display->print("Black           ");
  
    if(preselectedMode == 1)
        display->print("White           ");

    if(preselectedMode == 2)
        display->print("Red             ");
    
    if(preselectedMode == 3)
        display->print("Yellow          ");
        
    if(preselectedMode == 4)
        display->print("Green           ");

    if(preselectedMode == 5)
        display->print("Cyan            ");

    if(preselectedMode == 6)
        display->print("Blue            ");

    if(preselectedMode == 7)
        display->print("Purple          ");

    if(preselectedMode == 8)
        display->print("ColorWheel slow ");

    if(preselectedMode == 9)
        display->print("ColorWheel norm ");

    if(preselectedMode == 10)
        display->print("ColorWheel fast ");

    if(preselectedMode == 11)
        display->print("Red Strobo      ");

    if(preselectedMode == 12)
        display->print("Green Strobo    ");

    if(preselectedMode == 13)
        display->print("Blue Strobo     ");

    if(preselectedMode == 14)
        display->print("Color Strobo    ");

    if(preselectedMode == 15)
        display->print("Color Strobo RGB");
    
    display->setCursor(0, 1); // Goto second row
    
    if (preselectedMode == currentMode)
        display->print("Selected        ");
    else
        display->print("                ");

    
}

void ControlPanel::block()
{
    lastKeyEvent = millis();
    isBlocked = true;
}

void ControlPanel::checkBlocking()
{
    unsigned long currentTime = millis();

    if((currentTime - lastKeyEvent) > DELAYTIME)
        isBlocked = false;  
}

