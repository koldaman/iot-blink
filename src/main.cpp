#include "Arduino.h"

#include <Blink.h>

const int LED_PIN = 14; // D5

// 5 repetitions
Blink blinker(
   LED_PIN /* PIN */,
   {10, 50, 10, 500} /* ON/OFF MS */,
   5 /* repetitions */
);

// repeat forever (until stop)
Blink blinker2(
   LED_PIN /* PIN */,
   {10, 50, 10, 50, 10, 1000} /* ON/OFF MS */,
   0 /* repetitions */
);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(3000);

  blinker.start();
  delay(5000);

  blinker2.start();
  delay(15000);
  blinker2.stop();
}

void loop() {

}
