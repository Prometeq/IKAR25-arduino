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

#include "MyMPU.h"

// Подключение и настройка MPU
bool setupMPU(bool LCD_res) {
  /* 
   * Проверяет готовность MPU и подключает его. 
   * При неудаче возвращает false, иначе - true.
   * После производит его настройку
   * 
   * Returns:
   *  bool
   */
  
  bool MPU_res = mpu.init();

  if (MPU_res && LCD_res) {
    Serial.println("MPU6500 подключён");
    lcdPrintSetup(LCDSetupInfo::MPU);

    Serial.println("Калибровка MPU6500");
    lcd.clear(); lcd.home();
    lcd.print("Calibration:");
    ProgresBar calibrBar(8);

    // Обновление прогрессбара
    for (int i = 1; i <= 8; i++) {
      switch (i) {
        case 1: 
          mpu.autoOffsets();
          break;
        case 2:
          mpu.setAccRange(MPU6500_ACC_RANGE_2G);
          break;
        case 3:
          mpu.enableAccDLPF(true);
          break;
        case 4:
          mpu.setAccDLPF(MPU6500_DLPF_3);
          break;
      }

      calibrBar.update(i);
    }

    Serial.println("MPU6500 успешно откалиброван");
    lcdPrintSetup(LCDSetupInfo::MPUCALIBR);

    return true;
  }
  else {
    if (!MPU_res) {
      Serial.println("Ошибка! MPU6500 не отвечает");
      Serial.println("Где мастер?");

      if (LCD_res) lcdMPUError();
    }

    return false;;
  }
}
