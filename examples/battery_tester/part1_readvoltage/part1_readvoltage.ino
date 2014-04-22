#include <LightUp.h>

#define MAX_VOLTAGE 3.0

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
}
