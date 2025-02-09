#pragma once
#ifndef _MyTermo_h_
#define _MyTermo_h_

// Параметры термистора
#define anlPIN A0 // Термистор подключаем к А0
#define BETA 3950 // Значение беты термистора
#define RESISTANCE 10 // Значение подтягивающего резистора

float getTemp();

#endif
