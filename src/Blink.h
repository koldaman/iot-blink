/**************************************************************
   Blink zajistuje blikani LED
   Je mozne nastavit PIN, delku rozviceni LED, delku zhasnuti LED a pocet opakovani
   PIN pracuje v rezimu pro zapis (OUTPUT)
 **************************************************************/

 #include <Ticker.h>

 #ifndef BLINK_H
 #define BLINK_H

 class Blink {
  public:
    Blink(const int pinNumber, const int ledOnMs, const int ledOffMs, const int repetitionCount);
    Blink(const int pinNumber, const int ledOnMs, const int ledOffMs);

    void start();
    void stop();
  private:
    int    _pinNumber;
    int    _ledOnMs;
    int    _ledOffMs;
    int    _repetitionCount;
    int    _count;
    bool   _stopRequested;
    int    _state;
    Ticker _ticker;
    void init(const int pinNumber, const int ledOnMs, const int ledOffMs, const int repetitionCount);
    static void changeState(Blink *blink);
};

#endif
