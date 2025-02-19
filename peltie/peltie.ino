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

#define BTN_PIN 7
#define LED_PIN 8
#define PELTIE_PIN 6
#define BTN_PERIOD 10

bool btn_flag = 0;

void updateBtn();
void turnPins(bool led_value, int peltie_value);

void setup() {
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  static uint32_t btn_tmr = 0;
  
  if (millis() - btn_tmr >= BTN_PERIOD) {
    updateBtn();
    btn_tmr = millis();
  }

  if (btn_flag) turnPins(HIGH, 120);
  else turnPins(LOW, 0);

  delay(10);
}

void updateBtn() {
  static bool last_btn = 0;

  bool cur_btn = digitalRead(BTN_PIN);
  if (last_btn == 0 && cur_btn == 1) btn_flag = !btn_flag;

  last_btn = cur_btn;
}

void turnPins(bool led_value, int peltie_value) {
  if (digitalRead(LED_PIN) != led_value) digitalWrite(LED_PIN, led_value);
  if (analogRead(PELTIE_PIN) != peltie_value) analogWrite(PELTIE_PIN, peltie_value);
}
