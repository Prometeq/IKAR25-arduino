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
