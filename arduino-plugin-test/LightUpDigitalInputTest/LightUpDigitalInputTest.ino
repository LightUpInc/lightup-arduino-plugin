#include <LightUp.h>

void loop() {
  digitalWrite(OUTPUT_A, digitalRead(INPUT_1));
  digitalWrite(OUTPUT_B, digitalRead(INPUT_2));
  digitalWrite(OUTPUT_C, digitalRead(INPUT_3));
  digitalWrite(OUTPUT_D, digitalRead(INPUT_4));
  digitalWrite(OUTPUT_E, digitalRead(INPUT_5));
  digitalWrite(OUTPUT_F, digitalRead(INPUT_6));
}
