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
#ifndef _MyMPU_h_
#define _MyMPU_h_

#include <MPU9250_WE.h>
#include <Wire.h>
#include "MyLCD.h"

// Параметры MPU6500
#define MPU_ADDR 0x68

// МПЮшка
MPU6500_WE mpu = MPU6500_WE(MPU_ADDR);

bool setupMPU(bool LCD_res);

#endif
