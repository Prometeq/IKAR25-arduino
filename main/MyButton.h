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
#ifndef _MyButton_h_
#define _MyButton_h_

#include "utils.h"
#include "config.h"


// Параметры кнопок
#define BUTTON_PIN 9

// Параметры светодиод
#define LED_PIN 10


// Переменные
bool btn_flag = 0;
bool start_btn_pressed = false;


// Скелеты
void updateButton();

void setupLed();
void turnLed(bool value);


#endif
