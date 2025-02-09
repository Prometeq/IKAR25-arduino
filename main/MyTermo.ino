#include "MyTermo.h"

// Получение температуры
float getTemp() {
  // читаем значение с А0
  int a = analogRead(anlPIN);
  return BETA / (log((1025.0 * 10 / a - 10) / 10) + BETA / 298.0) - 273.0;
}
