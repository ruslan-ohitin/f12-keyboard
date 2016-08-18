#include "DigiKeyboard.h"
#include <Bounce.h>

Bounce bouncer = Bounce(2, 40); //создаем экземпляр класса Bounce для 2 вывода
int key_down = 0;

void setup()
{
  pinMode(1, OUTPUT);   //переключаем 1 вывод в режим выхода
  pinMode(2, INPUT);   //переключаем 2 вывод в режим входа
  digitalWrite(2, HIGH);  //включаем на нем подтягивающий резистор
}

void loop()
{
  if (bouncer.update()) {     //если произошло событие
    if (bouncer.read()==0) {    //если кнопка нажата
      key_down = 1;
      digitalWrite(1, HIGH);
      bouncer.rebounce(500);      //повторить событие через 500мс
    } else {
      // Кнопка отпущена
      if (key_down) {
        DigiKeyboard.sendKeyStroke(KEY_F12);
        key_down = 0;
        digitalWrite(1, LOW);
      }
    }
  }
  DigiKeyboard.delay(100);
}

