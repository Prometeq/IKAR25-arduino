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

#pragma once
#ifndef _MyLCD_h_
#define _MyLCD_h_

#include <LiquidCrystal_I2C_Hangul.h>
#include <MPU9250_WE.h>
#include <Wire.h>

// Параметры дисплея
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

// Дисплей
LiquidCrystal_I2C_Hangul lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// Варианты информации для отображения
enum LCDSetupInfo {
  LCD,
  MPU,
  MPUCALIBR,
  STEPPER
};

// Прогрессбар
class ProgresBar {
  private:
    int _precent;
    int _lcdDiv;
    int _curPos;

  public:
    ProgresBar(int allIteration);
    void update(int iteration);
};

bool setupLCD();
void lcdPrintSetup(LCDSetupInfo mode);
void lcdPressBTN();
void lcdPrintInfo(float temp, xyzFloat value);
void lcdMPUError();
void lcdCriticalError();
void lcdGameOver();
void lcdEnd();

#endif
