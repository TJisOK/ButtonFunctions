#include <Arduino.h>

#include "Button.h"

//----- Buttons -----
//Button button1(3, 5, 260, 500);
Button button1(4, 5, 180, 500);////pin, debounce time, double click window, long press //4, 5, 150, 500

void setup() {
  Serial.begin(115200);

}

void loop() {

    if (button1.isSingleClick()) {  // single
      Serial.println("isSingleClick");
    }

    if (button1.isDoubleClick()) {  // single
      Serial.println("isDoubleClick");
    }

    if (button1.isLongPress()) {  // single
      Serial.println("isLongPressed");
    }


    delay(1);
}
