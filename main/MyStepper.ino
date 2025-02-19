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

#include "MyStepper.h"

// Настройка
void setupStp() {
  pinMode(digPIN1, OUTPUT);
  pinMode(digPIN2, OUTPUT);
  pinMode(digPIN3, OUTPUT);
  pinMode(digPIN4, OUTPUT);
  
  stp.setSpeed(STP_SPEED);

  Serial.println("Мотор настроен");
  lcdPrintSetup(LCDSetupInfo::STEPPER);
}

// Выключение двигателя
void stpEnd() {
  pinMode(digPIN1, LOW);
  pinMode(digPIN2, LOW);
  pinMode(digPIN3, LOW);
  pinMode(digPIN4, LOW);
}
