#include <LightUp.h>

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

    allOff();

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
    
  } else {
    allOff();
    
  }
}
