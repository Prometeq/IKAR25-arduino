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

#include "MyButton.h"

// Опрос кнопки
void updateButton() {
  static bool last_btn = 0;
  static int press_time = 0;

  bool cur_btn = digitalRead(BUTTON_PIN);
  if (last_btn == 0 && cur_btn == 1) {
    while(digitalRead(BUTTON_PIN) == 1 && press_time < BTN_LONG_PRESS) {
      press_time++;
      delay(1);
    }
    if (press_time < BTN_LONG_PRESS) {
      btn_flag = !btn_flag;
    }
    else {
      if (programm_off) programm_off = false;
      else programm_need_exit = true;
    }
    press_time = 0;
  }
  
  last_btn = cur_btn;
}

void setupLed() {
  pinMode(LED_PIN, OUTPUT);
}

void turnLed(bool value) {
  if (value != digitalRead(LED_PIN)) digitalWrite(LED_PIN, value);
}
