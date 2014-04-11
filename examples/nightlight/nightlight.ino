#include <LightUp.h>

void setup() {

}

void loop() {
  if (analogRead(INPUT_2) > 50) {
    digitalWrite(OUTPUT_1, HIGH);
    digitalWrite(OUTPUT_2, HIGH);
    digitalWrite(OUTPUT_3, HIGH);
    digitalWrite(OUTPUT_4, HIGH);
    digitalWrite(OUTPUT_5, HIGH);
    digitalWrite(OUTPUT_6, HIGH);
  }
}
