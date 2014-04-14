#include <LightUp.h>

int DARKNESS_THRESHOLD = 150;

void setup() {

}

void loop() {
  // Read the value of the sensor.
  int darkness = analogRead(INPUT_2);

  if (darkness > DARKNESS_THRESHOLD) {
    // If it is dark, turn on all the lights.
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, HIGH);
    digitalWrite(OUTPUT_C, HIGH);
    digitalWrite(OUTPUT_D, HIGH);
    digitalWrite(OUTPUT_E, HIGH);
    digitalWrite(OUTPUT_F, HIGH);
  } else {
    // Otherwise, turn off all the lights.
    digitalWrite(OUTPUT_A, LOW);
    digitalWrite(OUTPUT_B, LOW);
    digitalWrite(OUTPUT_C, LOW);
    digitalWrite(OUTPUT_D, LOW);
    digitalWrite(OUTPUT_E, LOW);
    digitalWrite(OUTPUT_F, LOW);
  }
}
