// Подключения
#include "MyLCD.h"
#include "MyMPU.h"
#include "MyStepper.h"
#include "MyTermo.h"
#include "MyTimer.h"
#include "MyButton.h"
#include "utils.h"

#include "config.h"  // Параметры программы


// Настройка
void setup() {
  Serial.begin(SERIAL_BOT);
  Wire.begin();

  programmStart();
}

// Главный цикл
void loop() {
  static Timer buttonTimer(BUTTON_PERIOD);
  static Timer infoTimer(INFO_PERIOD);
  static float temp;

  // Опрос кнопки
  if (buttonTimer.check()) {
    updateButton();

    if (programm_need_exit) programmExit();

    else if (btn_flag && !start_btn_pressed) {
      start_btn_pressed = true;

      // Оповещение о старте
      lcd.clear(); lcd.home();
      lcd.print("Starting...");
    
      stpTimer.delay(TURN_START_DELAY);
      
      delay(SETUP_DELAY);
    }
    
    buttonTimer.update();
  }

  if (start_btn_pressed) {
    // Обновление основной информации
    if (infoTimer.check()) {
      temp = getTemp();
      xyzFloat value = mpu.getAngles();
      lcdPrintInfo(temp, value);
  
      infoTimer.update();
    }
  
    if (stp_flag == true && btn_flag == false) turnLed(LOW);
  
    // Выполнение поворотов
    if (stpTimer.check() && stp_flag && btn_flag) {  // Another start way: temp >= TERMO_LIMIT && ...
      turnLed(HIGH);
      
      switch (turn_number) {
        case 1: async_turn(ONE_STEP, TURN_REV_STEPS, 0); break;  // Поворот назад
        case 2: async_turn(-ONE_STEP, TURN_REV_STEPS, WAIT_BETWEEN_TURNS); break;  // Поворот обратно
        case 3: async_turn(-ONE_STEP, TURN_FOR_STEPS, TURN_FOR_WAIT); break;  // Поворот вперёд
        case 4: async_turn(ONE_STEP, TURN_FOR_STEPS, 0); break;  // Возвращение обратно
      }
    }
  }
}
