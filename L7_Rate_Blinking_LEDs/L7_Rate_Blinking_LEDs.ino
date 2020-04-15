#include "Blinker.h"

// Specifiy pins and blink intervals (ms).
Blinker _led1Blinker(2, 200); // red
Blinker _led2Blinker(5, 333); // blue
Blinker _led3Blinker(9, 1111); // yellow

void setup() {}

void loop() {
  _led1Blinker.update();
  _led2Blinker.update();
  _led3Blinker.update();
}
