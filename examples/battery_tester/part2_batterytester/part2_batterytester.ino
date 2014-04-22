#include <LightUp.h>

#define MAX_VOLTAGE 3.0

#define LOW_VOLTAGE 1.2
#define GOOD_VOLTAGE 1.4

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the battery voltage (0 = 0 volts, 1024 = MAX_VOLTAGE volts).
  int value = analogRead(INPUT_2);
  
  // Convert the value to the equivalent voltage.
  float voltage = MAX_VOLTAGE * ((float)value / 1024);
  
  // Print the voltage to the screen.
  Serial.println(voltage);
  
  // Display more lights for higher voltage, and less lights for
  // lower voltage.
  if (voltage >  GOOD_VOLTAGE) {
    
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, LOW);
    digitalWrite(OUTPUT_C, LOW);
    
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
