//
// controlpanel.cpp
//
#include "controlpanel.h"

ControlPanel::ControlPanel(LiquidCrystal *lcd) :
  lastPressedKey(ControlPanel::kNoKey),
  currentMode(MODE_IDLE),
  display(lcd)
{
  // set up the LCD's number of columns and rows:
  display->begin(16, 2);
  // Welcome message
  display->setCursor(0, 0);
  display->print("Welcome, this is");
  display->setCursor(0, 1);
  display->print("SCARY PAR   V0.1");
}

void ControlPanel::updateControl()
{
  Key key = readKey();

  if ((key != lastPressedKey) && (key != kNoKey))
  {
    if (key == ControlPanel::kUp)
      nextMode();
    if (key == ControlPanel::kDown)
      previousMode();
    if (key == ControlPanel::kEnter)
      select();

    displayMode();
  }
  // update last key
  if (key != ControlPanel::kNoKey)
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

  // Debug
  if (pressedKey != lastPressedKey)
  {
    if (pressedKey == kRight) Serial.println("Key Right");
    if (pressedKey == kUp)    Serial.println("Key Up");
    if (pressedKey == kDown)  Serial.println("Key Down");
    if (pressedKey == kLeft)  Serial.println("Key Left");
    if (pressedKey == kEnter) Serial.println("Enter");
  }

  return pressedKey;
}

void ControlPanel::nextMode()
{
  if (preselectedMode < NO_OF_MODES - 1)
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

  Serial.print(preselectedMode);
  Serial.print(" ");
  Serial.println(currentMode);
}

void ControlPanel::displayMode() const
{
  char *modeText;
  if (currentMode == preselectedMode)
    modeText = currentModeText(true);
  else
    modeText = currentModeText(false);

  display->clear();
  display->setCursor(0, 0);
  display->print(modeText);
  Serial.print("Text: ");
  Serial.println(modeText);
}

char* ControlPanel::currentModeText(bool inCapitals) const
{
  if (inCapitals)
  {
    switch (preselectedMode)
    {
      case MODE_IDLE:      return "IDLE";
      case MODE_FADE_RED:  return "FADE RED";
      case MODE_FADE_BLUE: return "FADE BLUE";
    }
  }
  else
  {
    switch (preselectedMode)
    {
      case MODE_IDLE:      return "idle";
      case MODE_FADE_RED:  return "fade red";
      case MODE_FADE_BLUE: return "fade blue";
    }
  }
}
