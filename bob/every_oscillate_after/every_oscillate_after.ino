#include <Timer.h>

#define LED_L 13

Timer t;

int ledEvent;

void setup()
{
  Serial.begin(115200);
  Serial.println("----=====----=====----=====----=====----=====");

  //every(Microsecond, call_back_func);
  //every Microsecond ms do call_back_func once.
  int tickEvent = t.every(500, doSomething);
  Serial.print("0.5 second tick started id=");
  Serial.println(tickEvent);

  pinMode(LED_L, OUTPUT);
  //oscillate(uint8_t pin, unsigned long period, uint8_t startingValue, -1)   //forever
  ledEvent = t.oscillate(LED_L, 50, HIGH);
  Serial.print("LED event started id=");
  Serial.println(ledEvent);

  //after (Microsecond, call_back_func);
  //after boot Microsecond ms do call_back_func once.
  int afterEvent = t.after(3000, doAfter);
  Serial.print("After event started id=");
  Serial.println(afterEvent);
}

void doSomething()
{
  Serial.print("[doSomething]0.5 second tick: millis()=");
  Serial.println(millis());
}

void doAfter()
{
  Serial.println("[doAfter]stop the led event");
  t.stop(ledEvent);
  //oscillate(uint8_t pin, unsigned long period, uint8_t startingValue, int repeatCount)
  t.oscillate(LED_L, 500, HIGH, 3);
}

void loop()
{
  t.update();
}

