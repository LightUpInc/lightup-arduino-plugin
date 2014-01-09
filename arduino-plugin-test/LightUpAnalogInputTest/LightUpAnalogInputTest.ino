#include <LightUp.h>

void on(int pin) {
  digitalWrite(pin, 1);
}

void off(int pin) {
  digitalWrite(pin, 0);
}

void onOff(int pin) {
  on(pin);
  delay(500);
  off(pin); 
}

void allOn() {
  on(OUTPUT_1);
  on(OUTPUT_2);
  on(OUTPUT_3);
  on(OUTPUT_4);
  on(OUTPUT_5);
  on(OUTPUT_6);
  on(_LU_INPUT_SIGNAL_1);
  on(_LU_INPUT_SIGNAL_2);
  on(_LU_INPUT_SIGNAL_3);
  on(_LU_INPUT_SIGNAL_4);
  on(_LU_INPUT_SIGNAL_5);
  on(_LU_INPUT_SIGNAL_6);
}

void allOff() {
  off(OUTPUT_1);
  off(OUTPUT_2);
  off(OUTPUT_3);
  off(OUTPUT_4);
  off(OUTPUT_5);
  off(OUTPUT_6);
  off(_LU_INPUT_SIGNAL_1);
  off(_LU_INPUT_SIGNAL_2);
  off(_LU_INPUT_SIGNAL_3);
  off(_LU_INPUT_SIGNAL_4);
  off(_LU_INPUT_SIGNAL_5);
  off(_LU_INPUT_SIGNAL_6);
}

void setup() {
  allOff();
}

boolean inRange(int pin) {
  int value = analogRead(pin);
  if (value > 502 && value < 522) {
    return true;
  } else {
    return false;
  }
}

void loop() {
  if (inRange(INPUT_1) &&
      inRange(INPUT_2) &&
      inRange(INPUT_3) &&
      inRange(INPUT_4) &&
      inRange(INPUT_5) &&
      inRange(INPUT_6)) {

    onOff(OUTPUT_1);
    onOff(OUTPUT_2);
    onOff(OUTPUT_3);
    onOff(OUTPUT_6);
    onOff(OUTPUT_5);
    onOff(OUTPUT_4);
  } 
}
