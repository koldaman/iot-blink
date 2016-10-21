/**************************************************************
  Signalizace blikanim LED;
 **************************************************************/
#include "Arduino.h"

#include "Blink.h"
#include <Ticker.h>
//#include <functional>

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
   pinMode(_pinNumber, OUTPUT);
}

void Blink::callbackOn() {
  digitalWrite(_pinNumber, HIGH);
  Serial.print("ON ");
  Serial.println(_ledOnMs);
  if (!_stopRequested) {
    static Blink *obj = this;
    _ticker.attach_ms(_ledOnMs, []() { obj->callbackOff(); });
  }
}

void Blink::callbackOff() {
  digitalWrite(_pinNumber, LOW);
  Serial.print("OFF ");
  Serial.println(_ledOnMs);

  if (!_stopRequested) {
    static Blink *obj = this;
    _ticker.attach_ms(_ledOffMs, []() { obj->callbackOn(); });
  }

  if (_repetitionCount > 0) {
    _count++;
    if (_count == _repetitionCount) {
      stop();
    }
  }
}

void Blink::stop() {
   _stopRequested = true;
   _ticker.detach();
   digitalWrite(_pinNumber, LOW);
}

void Blink::start() {
  stop();
  _stopRequested = false;
  _count = 0;
  callbackOn();
}
