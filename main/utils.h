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
#ifndef _utils_h_
#define _utils_h_

#include "MyLCD.h"
#include "MyMPU.h"
#include "MyStepper.h"
#include "MyButton.h"
#include "config.h"


// Глобальные переменные
bool LCD_res = false;
bool MPU_res = false;

bool programm_off = false;
bool programm_need_exit = false;
unsigned int programm_restarts = 0;

Timer stpTimer(TURN_REV_WAIT);  // "Шаговый" таймер

int turn_number = 1;  // Номер поворота
bool stp_flag = true;  // Разрешение на поворот


void setupAll();
void programmStart();
void programmWaitRestart();
void programmExit();
void async_turn(int one_step, int turn_steps, int wait_time);

#endif
