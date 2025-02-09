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
