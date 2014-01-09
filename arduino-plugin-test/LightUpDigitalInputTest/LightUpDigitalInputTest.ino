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

void pullUp() {
  pinMode(INPUT_1, INPUT_PULLUP);
  pinMode(INPUT_2, INPUT_PULLUP);
  pinMode(INPUT_3, INPUT_PULLUP);
  pinMode(INPUT_4, INPUT_PULLUP);
  pinMode(INPUT_5, INPUT_PULLUP);
  pinMode(INPUT_6, INPUT_PULLUP);
}

void setup() {
  pullUp();
  allOff();
}

void loop() {
  digitalWrite(OUTPUT_1, digitalRead(INPUT_1));
  digitalWrite(OUTPUT_2, digitalRead(INPUT_2));
  digitalWrite(OUTPUT_3, digitalRead(INPUT_3));
  digitalWrite(OUTPUT_4, digitalRead(INPUT_4));
  digitalWrite(OUTPUT_5, digitalRead(INPUT_5));
  digitalWrite(OUTPUT_6, digitalRead(INPUT_6));
}
