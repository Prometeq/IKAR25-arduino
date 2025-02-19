/*
Copyright (C) 2025  Vyacheslav Pervakov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
