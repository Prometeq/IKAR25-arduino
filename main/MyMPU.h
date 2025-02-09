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
