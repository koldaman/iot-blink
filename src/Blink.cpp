/**************************************************************
  Signalizace blikanim LED;
 **************************************************************/
#include "Arduino.h"

#include "Blink.h"
#include <Ticker.h>
//#include <functional>

Blink::Blink(int pinNumber, int ledOnMs, int ledOffMs, int repetitionCount) {
  _pinNumber = pinNumber;
  _ledOnMs = ledOnMs;
  _ledOffMs = ledOffMs;
  _repetitionCount = repetitionCount;
  _count = 0;
  Ticker _tickerOn;
  Ticker _tickerOff;
  pinMode(_pinNumber, OUTPUT);
}

void Blink::callbackOn() {
  digitalWrite(_pinNumber, HIGH);
  static Blink *obj = this;
  _tickerOff.attach_ms(_ledOnMs, []() { obj->callbackOff(); });
}

void Blink::callbackOff() {
  digitalWrite(_pinNumber, LOW);
  static Blink *obj = this;
  _tickerOn.attach_ms(_ledOffMs, []() { obj->callbackOn(); });
  if (_repetitionCount > 0) {
    _count++;
    if (_count == _repetitionCount) {
      stop();
    }
  }
}

void Blink::stop() {
   _tickerOn.detach();
   _tickerOff.detach();
   digitalWrite(_pinNumber, LOW);
}

void Blink::start() {
  stop();
  _count = 0;
  callbackOn();
}
