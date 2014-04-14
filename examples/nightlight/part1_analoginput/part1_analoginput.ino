#include <LightUp.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int darkness = analogRead(INPUT_2);

  Serial.println();
}
