#include "Button.h"

Button::Button(int buttonPin, unsigned long debounceDelayMs, unsigned long doubleClickWindowMs, unsigned long longPressTimeMs) {
  //Variables Outside
  pin = buttonPin;
  debounceDelay = debounceDelayMs;
  doubleClickWindow = doubleClickWindowMs;
  longPressTime = longPressTimeMs;

  currentTime = 0;
  lastDebounceTime = 0;
  buttonState = HIGH;
  lastButtonState = HIGH;

  lastPressTime = 0;
  singleClickDetected = false;
  doubleClickDetected = false;
  longPressDetected = false;

  pinMode(pin, INPUT_PULLUP);
}

bool Button::isSingleClick() {
  currentTime = millis();
  int buttonReading = digitalRead(pin);

  if (buttonReading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (buttonReading != buttonState) {
      buttonState = buttonReading;

      if (buttonState == LOW) {
        //Pressed
        singleClickDetected = true;
        doubleClickDetected = false;

        // DoubleClick Detect
        if (singleClickDetected && (currentTime - lastPressTime) <= doubleClickWindow) {
          doubleClickDetected = true;
          singleClickDetected = false;
        }
        lastPressTime = currentTime;

      } else {
        // 按钮释放
        longPressDetected = false;  // Reset long press detection after button is released
      }
    } else if (buttonState == LOW && (currentTime - lastPressTime) > longPressTime) {
      longPressDetected = true;
    }
  }

  lastButtonState = buttonReading;

  //Single
  if (singleClickDetected) {
    singleClickDetected = false;
    return true;
  }
  return false;
}

bool Button::isDoubleClick() {
  currentTime = millis();
  int buttonReading = digitalRead(pin);

  if (buttonReading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (buttonReading != buttonState) {
      buttonState = buttonReading;

      if (buttonState == LOW) {
        //Pressed
        singleClickDetected = true;
        doubleClickDetected = false;

        // DoubleClick Detect
        if (singleClickDetected && (currentTime - lastPressTime) <= doubleClickWindow) {
          doubleClickDetected = true;
          singleClickDetected = false;
        }
        lastPressTime = currentTime;

      } else {
        // 按钮释放
        longPressDetected = false;  // Reset long press detection after button is released
      }
    } else if (buttonState == LOW && (currentTime - lastPressTime) > longPressTime) {
      longPressDetected = true;
    }
  }
  lastButtonState = buttonReading;

  //Double Click Return
  if (doubleClickDetected) {
    doubleClickDetected = false;
    return true;  //back to the whole function
  }

  return false;
}


bool Button::isLongPress() {
  currentTime = millis();
  int buttonReading = digitalRead(pin);

  if (buttonReading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (buttonReading != buttonState) {
      buttonState = buttonReading;

      if (buttonState == LOW) {
        //Pressed
        singleClickDetected = true;
        doubleClickDetected = false;

        // DoubleClick Detect
        if (singleClickDetected && (currentTime - lastPressTime) <= doubleClickWindow) {
          doubleClickDetected = true;
          singleClickDetected = false;
        }
        lastPressTime = currentTime;

      } else {
        // 按钮释放
        longPressDetected = false;  // Reset long press detection after button is released
      }
    } else if (buttonState == LOW && (currentTime - lastPressTime) > longPressTime) {
      longPressDetected = true;
    }
  }
  lastButtonState = buttonReading;

  //Long
  return longPressDetected;
}
