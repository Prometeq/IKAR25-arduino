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
