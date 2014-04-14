#include <LightUp.h>

int DARKNESS_THRESHOLD = 50;

void setup() {
  disableInputLights();
}

void loop() {
  // Read the value of the sensor.
  int darkness = analogRead(INPUT_2);

  // If it is dark, turn on all the lights.
  if (darkness > DARKNESS_THRESHOLD) {
    digitalWrite(OUTPUT_1, HIGH);
    digitalWrite(OUTPUT_2, HIGH);
    digitalWrite(OUTPUT_3, HIGH);
    digitalWrite(OUTPUT_4, HIGH);
    digitalWrite(OUTPUT_5, HIGH);
    digitalWrite(OUTPUT_6, HIGH);
  } else {
    digitalWrite(OUTPUT_1, LOW);
    digitalWrite(OUTPUT_2, LOW);
    digitalWrite(OUTPUT_3, LOW);
    digitalWrite(OUTPUT_4, LOW);
    digitalWrite(OUTPUT_5, LOW);
    digitalWrite(OUTPUT_6, LOW);
  }
}
