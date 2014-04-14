#include <LightUp.h>

int DARKNESS_THRESHOLD = 50;

void setup() {

}

void loop() {
  // Read the value of the sensor.
  int darkness = analogRead(INPUT_2);

  if (darkness > DARKNESS_THRESHOLD) {
    // If it is dark, turn on all the lights.
    digitalWrite(OUTPUT_1, HIGH);
    digitalWrite(OUTPUT_2, HIGH);
    digitalWrite(OUTPUT_3, HIGH);
    digitalWrite(OUTPUT_4, HIGH);
    digitalWrite(OUTPUT_5, HIGH);
    digitalWrite(OUTPUT_6, HIGH);
  } else {
    // Otherwise, turn off all the lights.
    digitalWrite(OUTPUT_1, LOW);
    digitalWrite(OUTPUT_2, LOW);
    digitalWrite(OUTPUT_3, LOW);
    digitalWrite(OUTPUT_4, LOW);
    digitalWrite(OUTPUT_5, LOW);
    digitalWrite(OUTPUT_6, LOW);
  }
}
