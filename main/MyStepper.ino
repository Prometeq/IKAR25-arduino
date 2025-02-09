#include "MyStepper.h"

// Настройка
void setupStp() {
  pinMode(digPIN1, OUTPUT);
  pinMode(digPIN2, OUTPUT);
  pinMode(digPIN3, OUTPUT);
  pinMode(digPIN4, OUTPUT);
  
  stp.setSpeed(STP_SPEED);

  Serial.println("Мотор настроен");
  lcdPrintSetup(LCDSetupInfo::STEPPER);
}

// Выключение двигателя
void stpEnd() {
  pinMode(digPIN1, LOW);
  pinMode(digPIN2, LOW);
  pinMode(digPIN3, LOW);
  pinMode(digPIN4, LOW);
}
