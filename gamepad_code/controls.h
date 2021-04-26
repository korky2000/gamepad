#include <Bounce2.h>
Bounce * buttons = new Bounce[4];
int debounce = 10;
int buttonPins[4] = {0, 1, 2, 3};
int buttonBuffer[4] = {0, 0, 0, 0};
int joystick[2] = {A0, A1};
int joyBuffer[2] = {0, 0};
int timerInterval = 100;
#include <Metro.h>
Metro times = Metro(timerInterval);
//ok lets try this
void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(debounce);
  }
}
void getControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].fell()) {
      buttonBuffer[i] = 1;
    }
    if (buttons[i].rose()) {
      buttonBuffer[i] = 0;
    }
  }
  int joyX = analogRead(joystick[0]);
  int joyY = analogRead(joystick[1]);
  Serial.println(joyX);
  Serial.println(joyY);
  if (joyX > 700) {
    joyBuffer[0] = -1;
  } else if (joyX < 300) {
    joyBuffer[0] = 1;
  }
  else {
    joyBuffer[0] = 0;
  }
  if (joyY > 700) {
    joyBuffer[1] = -1;
  } else if (joyY < 300) {
    joyBuffer[1] = 1;
  }
  else {
    joyBuffer[1] = 0;
  }
}
