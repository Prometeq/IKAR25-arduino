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
