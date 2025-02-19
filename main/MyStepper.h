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
#ifndef _MyStepper_h_
#define _MyStepper_h_

#include <Stepper.h>
#include "config.h"

// Параметры для шагового двигателя
#define STEP_RES 200
#define digPIN1 4
#define digPIN2 5
#define digPIN3 6
#define digPIN4 7

// СТПешка
Stepper stp(STEP_RES, digPIN4, digPIN2, digPIN3, digPIN1);

void setupStp();
void stpEnd();

#endif
