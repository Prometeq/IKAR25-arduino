#include "MyTimer.h"

Timer::Timer(unsigned long period) {
  _tmr = 0;

  if (period > 0) _period = period;
  else if (period < 0) _period = -period;
  else _period = 5000;
}

uint32_t Timer::tmr() {
  return _tmr;
}

unsigned long Timer::period() {
  return _period;
}

// Проверка таймера
bool Timer::check() {
  if (millis() > _tmr) return millis() - _tmr >= _period;
  else return false;
}

// Обновление таймера
void Timer::update() {
  _tmr = millis();
}

// Задержка перед след. срабатыванием
void Timer::delay(int msec) {
  _tmr = millis() + msec;
}
