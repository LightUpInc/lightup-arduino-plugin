#include <LightUp.h>

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
  on(INPUT_1);
  on(INPUT_2);
  on(INPUT_3);
  on(INPUT_4);
  on(INPUT_5);
  on(INPUT_6);
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
  off(INPUT_1);
  off(INPUT_2);
  off(INPUT_3);
  off(INPUT_4);
  off(INPUT_5);
  off(INPUT_6);
}


void setup() {
  disableInputLights();
  
  pinMode(INPUT_1, OUTPUT);
  pinMode(INPUT_2, OUTPUT);
  pinMode(INPUT_3, OUTPUT);
  pinMode(INPUT_4, OUTPUT);
  pinMode(INPUT_5, OUTPUT);
  pinMode(INPUT_6, OUTPUT);

  
  allOn();
}

void loop() {
  allOn();
}
