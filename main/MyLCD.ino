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

#include "MyLCD.h"

////////////////////////////////////////
// Методы класса                      //
////////////////////////////////////////

ProgresBar::ProgresBar(int allIteration) {
  _precent = 1000 / allIteration;
  _lcdDiv = LCD_COLS /  allIteration;
  _curPos = 13;

  lcd.setCursor(14, 0);
  lcd.print("0%");

  delay(CALIBRATION_DELAY);
}

// Обновление информации
void ProgresBar::update(int iteration) {
  int percent = (_precent * iteration) / 10;

  if (percent < 10) _curPos = 14;
  else if (percent > 99) _curPos = 12;

  Serial.print(percent);
  Serial.println('%');

  lcd.setCursor(_curPos, 0);
  lcd.print(percent);

  lcd.setCursor((iteration - 1) * _lcdDiv, 1);
  for (int i = 0; i < _lcdDiv; i++) {
    lcd.print((char)255);
    delay(CALIBRATION_DELAY / 2);
  }

  delay(CALIBRATION_DELAY);
}

////////////////////////////////////////
// Функции                            //
////////////////////////////////////////

// Подключение LCD
bool setupLCD() {
  /*
   * Проверяет состояние LCD. Пытается подключить его. 
   * В случае удачи возвращает true, иначе false.
   * 
   * Returns:
   *  bool
   */
  
  Wire.begin();
  Wire.beginTransmission(LCD_ADDR);

  // Проверка подключения дисплея
  if (Wire.endTransmission() == 0) {
    delay(50);

    lcd.init(); // Инициализация дисплея
    lcd.backlight(); // Включение подсветки

    Serial.println("Дисплей подключён");
    lcdPrintSetup(LCDSetupInfo::LCD);

    return true;
  }
  else {
    Serial.println("Ошибка! Дисплей не отвечает"); 
    Serial.println("Вызовите мастера");
    
    return false;
  }
}

// Показ уведомлений о настройке
void lcdPrintSetup(LCDSetupInfo mode) {
  lcd.clear(); lcd.home();
  lcd.print("Setuping...");
  lcd.setCursor(0, 1);

  switch (mode) {
    case LCDSetupInfo::LCD: lcd.print("LCD conected"); break;
    case LCDSetupInfo::MPU: lcd.print("MPU6500 conected"); break;
    case LCDSetupInfo::MPUCALIBR: lcd.print("MPU calibrated"); break;
    case LCDSetupInfo::STEPPER: lcd.print("Stepper setuped"); break;
  }

  delay(SETUP_DELAY);
}

void lcdPressBTN() {
  lcd.clear(); lcd.home();
  lcd.print("Press button to");
  lcd.setCursor(0, 1);
  lcd.print("start");
}

// Вывод критической ошибки
void lcdCriticalError() {
  lcd.clear(); lcd.home();
  lcd.print("Critical Error!!");
  lcd.setCursor(0, 1);
  lcd.print("Stoping...");

  delay(SETUP_DELAY);
}

// Сообщение о завершении
void lcdGameOver() {
  lcd.clear(); lcd.home();
  lcd.print("Stopping...");

  delay(SETUP_DELAY);
}

// Выключение дисплея
void lcdEnd() {
  lcd.clear();
  lcd.noBacklight();
}

// Ошибка MPU
void lcdMPUError() {
  lcd.clear(); lcd.home();
  lcd.print("Error! MPU6500");
  lcd.setCursor(0, 1);
  lcd.print("does not respond");

  delay(SETUP_DELAY);
}

// Вывод основной информации (t и xyz)
void lcdPrintInfo(float temp, xyzFloat value) {
  lcd.clear(); lcd.home();
  
  // Вывод температуры в ºC и наклона
  lcd.print("Temp: "); lcd.print(temp); lcd.print("C");
  
  lcd.setCursor(0, 1);

  // Информация о наклоне
  lcd.print("X:"); lcd.print(round(value.x)); lcd.print(" ");
  lcd.print("Y:"); lcd.print(round(value.y)); lcd.print(" ");
  lcd.print("Z:"); lcd.print(round(value.z));
}
