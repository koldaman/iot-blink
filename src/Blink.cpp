/**************************************************************
  Signalizace blikanim LED;
 **************************************************************/
#include "Arduino.h"

#include "Blink.h"
#include <Ticker.h>

Blink::Blink(int pinNumber, int ledOnMs, int ledOffMs, int repetitionCount) {
  init(pinNumber, ledOnMs, ledOffMs, repetitionCount);
}

Blink::Blink(int pinNumber, int ledOnMs, int ledOffMs) {
  init(pinNumber, ledOnMs, ledOffMs, 0);
}

void Blink::init(int pinNumber, int ledOnMs, int ledOffMs, int repetitionCount) {
   _pinNumber = pinNumber;
   _ledOnMs = ledOnMs;
   _ledOffMs = ledOffMs;
   _repetitionCount = repetitionCount;
   _count = 0;
   _stopRequested = false;
   _state = LOW;
   pinMode(_pinNumber, OUTPUT);
}

void Blink::changeState(Blink *blink) {
  if (blink->_repetitionCount > 0) {
    if (blink->_count == blink->_repetitionCount) {
      blink->stop();
      return;
    }
  }

  if (blink->_state == LOW) { // ON start
    blink->_state = HIGH;
    digitalWrite(blink->_pinNumber, blink->_state);
    if (!blink->_stopRequested) {
      blink->_ticker.attach_ms(blink->_ledOnMs, &Blink::changeState, blink);
      blink->_count++;
    }
  } else {
    blink->_state = LOW;
    digitalWrite(blink->_pinNumber, blink->_state);
    blink->_ticker.attach_ms(blink->_ledOffMs, &Blink::changeState, blink);
  }
}

void Blink::stop() {
  _state = LOW;
  _stopRequested = true;
  digitalWrite(_pinNumber, _state);
  _ticker.detach();
}

void Blink::start() {
  stop();
  _stopRequested = false;
  _count = 0;
  Blink::changeState(this);
}
