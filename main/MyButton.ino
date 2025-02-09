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
