#include <LightUp.h>

void setup() {

}

void loop() {
  // Read the light level.
  int light = analogRead(INPUT_2);
  
  // Map the light level to a frequency.
  int frequency = light * 4;
  
  // Play the proper frequency.
  tone(OUTPUT_F, frequency);
}
