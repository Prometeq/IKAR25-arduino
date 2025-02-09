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
