
// ---------------------------
// Project: DMXuino
// programms.h
// created 2016-02-01
// HalloSoft
//
//------------------------------

#include "Arduino.h"

void resetChannels();
void runBlackMode(unsigned int counter);
void runFadeRedMode(unsigned int counter);
void runFadeGreenMode(unsigned int counter);
void runFadeBlueMode(unsigned int counter);
void runStroboRedMode(unsigned int counter);
void runStroboGreenMode(unsigned int counter);
void runStroboBlueMode(unsigned int counter);

// Helper
int calculateFadeValue(unsigned int counter);
int calculateStroboValue(unsigned int counter);

