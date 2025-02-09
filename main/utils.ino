#include "utils.h"

void setupAll() {
  /*
   * Производит подключение и настройку всех основных компонентов. 
   * При не удаче сообщает об этом и останавливает работу.
   */
  
  Serial.println("Идёт настройка, ожидайте...");

  LCD_res = setupLCD();
  MPU_res = setupMPU(LCD_res);

  if (LCD_res && MPU_res) {
    setupStp();
    setupLed();

    Serial.println("Настройка прошла успешно!");

    lcd.clear(); lcd.home();
    lcd.print("Setup success!");

    delay(SETUP_DELAY);
  }
  else programmExit();
}

// Запуск программы
void programmStart() {
  setupAll();  // Настройка всех компенентов

  // Напоминане о кнопке
  Serial.println("Нажмите кнопку, чтобы начать");
  lcdPressBTN();
}

// Ожидание перезапуска программы
void programmWaitRestart() {
  while (programm_off) updateButton();
  programm_restarts++;
  
  programm_need_exit = false;
  
  turn_number = 1;
  stp_flag = true;
  
  btn_flag = 0;
  start_btn_pressed = false;
  
  programmStart();
}

// Завершение программы
void programmExit() {
  if (LCD_res && MPU_res && programm_restarts < MAX_STARTS_NUM - 1) {
    Serial.println("Выкючение...");
    lcdGameOver();
    
    lcdEnd();
    stpEnd();
    turnLed(LOW);
    
    programm_off = true;
    programmWaitRestart();
  }
  else {
    Serial.println("Критическая ошибка, завершаю работу!");
    if (LCD_res) lcdCriticalError();

    lcdEnd();
    stpEnd();
    turnLed(LOW);
    Wire.end();
    Serial.end();
  
    exit(0);
  }
}

// Единичные шаг поворота
void async_turn(int one_step, int turn_steps, int wait_time) {
  // Статичная переенная пройденных шагов
  static int steps = 0;

  if (wait_time != 0) wait_time = wait_time - stpTimer.period();
  
  // Если поворот ещё не завершён
  if (steps < turn_steps) {
    stp.step(one_step);
    if (one_step >= 0) steps += one_step;
    else steps -= one_step;
  }
  // Если обратное
  else {
    if (turn_number == LAST_TURN) {
      turnLed(LOW);
      steps = 0;
      stp_flag = false;
    }
    else {
      steps = 0;
      turn_number++;
      stpTimer.delay(wait_time);
    }
  }
}
