#include <stdint.h>
#pragma once
#ifndef _MyTimer_h_
#define _MyTimer_h_

// Класс таймера
class Timer {
  /*
   * При ините указывается период срабатывание.
   * Для проверки таймера, вызывается функция update.
   * Если с момента инита или прошлой проверки установленное время прошло,
   * возвращается true, иначе - false.
   * 
   * Note:
   *  Класс нужен для более удобной реализации асинхронности.
   * 
   * Args:
   *  period: Частота срабатывания таймера
   */
  
  private:
    uint32_t _tmr;
    unsigned long _period;
  
  public:
    Timer(unsigned long period);

    uint32_t tmr();
    unsigned long period();
    bool check();
    void update();
    void delay(int msec);
};

#endif
