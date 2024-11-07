#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {

private:
  int pin;

  unsigned long lastDebounceTime;
  int buttonState;
  int lastButtonState;
  unsigned long debounceDelay;

  unsigned long currentTime;
  unsigned long lastPressTime;
  unsigned long doubleClickWindow;
  unsigned long longPressTime;

  bool singleClickDetected;
  bool doubleClickDetected;
  bool longPressDetected;


public:
  Button(int buttonPin, unsigned long debounceDelayMs, unsigned long doubleClickWindowMs, unsigned long longPressTimeMs);
  
  bool isSingleClick();
  bool isDoubleClick();
  bool isLongPress();
};

#endif