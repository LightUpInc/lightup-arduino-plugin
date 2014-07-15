#include <LightUp.h>

void on(int pin) {
  digitalWrite(pin, HIGH);
}

void off(int pin) {
  digitalWrite(pin, LOW);
}

void onOff(int pin) {
  on(pin);
  delay(500);
  off(pin); 
}

void allOn() {
  on(OUTPUT_A);
  on(OUTPUT_B);
  on(OUTPUT_C);
  on(OUTPUT_D);
  on(OUTPUT_E);
  on(OUTPUT_F);
  on(_LU_INPUT_SIGNAL_1);
  on(_LU_INPUT_SIGNAL_2);
  on(_LU_INPUT_SIGNAL_3);
  on(_LU_INPUT_SIGNAL_4);
  on(_LU_INPUT_SIGNAL_5);
  on(_LU_INPUT_SIGNAL_6);
}

void allOff() {
  off(OUTPUT_A);
  off(OUTPUT_B);
  off(OUTPUT_C);
  off(OUTPUT_D);
  off(OUTPUT_E);
  off(OUTPUT_F);
  off(_LU_INPUT_SIGNAL_1);
  off(_LU_INPUT_SIGNAL_2);
  off(_LU_INPUT_SIGNAL_3);
  off(_LU_INPUT_SIGNAL_4);
  off(_LU_INPUT_SIGNAL_5);
  off(_LU_INPUT_SIGNAL_6);
}


void setup() {
  disableInputLights();
  allOff();
}

void loop() {
  allOn();

  delay(2000);

  allOff();

  delay(2000);

  onOff(OUTPUT_A);
  onOff(OUTPUT_B);
  onOff(OUTPUT_C);
  onOff(_LU_INPUT_SIGNAL_4);
  onOff(_LU_INPUT_SIGNAL_5);
  onOff(_LU_INPUT_SIGNAL_6);
  onOff(OUTPUT_F);
  onOff(OUTPUT_E);
  onOff(OUTPUT_D);
  onOff(_LU_INPUT_SIGNAL_3);
  onOff(_LU_INPUT_SIGNAL_2);
  onOff(_LU_INPUT_SIGNAL_1);
}
