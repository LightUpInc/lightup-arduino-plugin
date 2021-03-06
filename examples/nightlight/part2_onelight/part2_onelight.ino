#include <LightUp.h>

int DARKNESS_THRESHOLD = 150;

void setup() {

}

void loop() {
  // Read the value of the sensor.
  int darkness = analogRead(INPUT_2);

  if (darkness > DARKNESS_THRESHOLD) {
    // If it is dark, turn on a light.
    digitalWrite(OUTPUT_A, HIGH);
  } else {
    // Otherwise, turn off the light.
    digitalWrite(OUTPUT_A, LOW);
  }
}
