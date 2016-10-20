#include "Arduino.h"

#include <Blink.h>

Blink blinker(4 /* PIN */, 20 /* ON MS */, 500 /* OFF MS */, 5 /* repetitions */); // D2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //set led pin as output
  pinMode(0, OUTPUT);

  blinker.start();
}

void loop() {

}
