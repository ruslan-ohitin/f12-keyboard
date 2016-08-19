#include "DigiKeyboard.h"
#include <Bounce.h>

#define BUTTON=2
#define LED=1

Bounce bouncer = Bounce(BUTTON, 40); // Create instance of Bounce class for pin BUTTON, with 40ms period
int button_down = 0;

void setup() {
  pinMode(LED, OUTPUT);        // LED pin as output
  pinMode(BUTTON, INPUT);      // BUTTON pin as input
  digitalWrite(BUTTON, HIGH);  // Pull-up on BUTTON pin
}

void loop() {
  if (bouncer.update()) {      // button state change
    if (bouncer.read() == 0) {
      // button down (remember about pull-up)
      button_down = 1;
      digitalWrite(LED, HIGH);
      bouncer.rebounce(500);   // repeat fater 500ms
    } else {                   
      // button is up
      if (button_down) {        
        DigiKeyboard.sendKeyStroke(KEY_F12);
        button_down = 0;
        digitalWrite(LED, LOW);
      }
    }
  }
  DigiKeyboard.delay(100);
}

