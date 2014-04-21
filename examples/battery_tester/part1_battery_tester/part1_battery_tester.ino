#include <LightUp.h>

#define MAX_VOLTAGE 2.8

#define LOW_VOLTAGE = 1.2
#define OKAY_VOLTAGE = 1.4
#define GOOD_VOLTAGE = 1.5

void setup() {

}

void loop() {
  // Read the battery voltage (0 = 0 volts, 1024 = MAX_VOLTAGE volts).
  int value = analogRead(INPUT_2);
  
  // Convert the value to the equivalent voltage.
  float voltage = MAX_VOLTAGE * ((float)value / 1024);
  
  // Display more lights for higher voltage, and less lights for
  // lower voltage.
  if (voltage >  GOOD_VOLTAGE) {
    
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, LOW);
    digitalWrite(OUTPUT_c, LOW);
    
  } else if (voltage > OKAY_VOLTAGE) {
  
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, HIGH);
    digitalWrite(OUTPUT_C, LOW);
  
  } else {
  
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, HIGH);
    digitalWrite(OUTPUT_C, HIGH);

  }
  
}
