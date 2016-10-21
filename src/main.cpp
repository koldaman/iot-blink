#include "Arduino.h"

#include <Blink.h>

const int LED_PIN = 14; // D5

// 5 repetitions
Blink blinker(LED_PIN /* PIN */, 10 /* ON MS */, 500 /* OFF MS */, 5 /* repetitions */);

// repeat forever (until stop)
Blink blinker2(LED_PIN /* PIN */, 20 /* ON MS */, 1000 /* OFF MS */, 4);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(2000);

  blinker.start();
  delay(4000);
  blinker.stop();

  blinker2.start();
  delay(15000);
  blinker2.stop();
}

void loop() {

}
