#pragma once
#ifndef _config_h_
#define _config_h_

// ПАРАМЕТРЫ ПРОГРАММЫ

// Максимальное кол-во перезапусков
#define MAX_STARTS_NUM 3

// Частота обновления порта
#define SERIAL_BOT 115200

// Параметры настройки
#define SETUP_DELAY 1750  // Задежка во время настройки
#define CALIBRATION_DELAY 500  // Задержка во время калибровки

// Параметры информации
#define INFO_PERIOD 100  // Частота получения информации

// Температурные параметры
// #define TERMO_LIMIT 22  // Лимит t для старта. Не используется

// Параметры степпера
#define STP_SPEED 150 // Скорость вращения
#define ONE_STEP 1  // Размер единичного шага

#define LAST_TURN 4  // Номер последнего поворота

#define TURN_REV_STEPS 250  // Кол-во шагов поворота назад
#define TURN_FOR_STEPS 670  // Кол-во шагов поворота вперёд

#define TURN_START_DELAY 10000  // Задержка перед первым поворотом
#define TURN_REV_WAIT 1200  // Интервал (msec) между обратными поворотами
#define WAIT_BETWEEN_TURNS 5000  // Интервал между поровотоми назад и вперёд
#define TURN_FOR_WAIT 6000  // Интервал (msec) между передними поворотами

// Параметры кнопки
#define BUTTON_PERIOD 10  // Частота опроса кнопки
#define BTN_LONG_PRESS 1500  // msec

#endif
