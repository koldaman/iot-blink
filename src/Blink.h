/**************************************************************
   Blink zajistuje blikani LED
   Je mozne nastavit PIN, delku rozviceni LED, delku zhasnuti LED a pocet opakovani
   PIN pracuje v rezimu pro zapis (OUTPUT)
 **************************************************************/

 #include <Ticker.h>

 #ifndef BLINNK
 #define BLINK

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
    Ticker _ticker;
    void init(const int pinNumber, const int ledOnMs, const int ledOffMs, const int repetitionCount);
    void callbackOn();
    void callbackOff();
};

#endif
