/* Helpful constants for buttons  */
#define PRESSED 0
#define UNPRESSED 1

/* Helpful names for output pins */
void on(int pin) {
  digitalWrite(pin, HIGH);
}

void off(int pin) {
  digitalWrite(pin, LOW);
}

void onOff(int pin) {
  on(pin);
  delay(500);
  off(pin); 
}

void allOn() {
  on(OUTPUT_A);
  on(OUTPUT_B);
  on(OUTPUT_C);
  on(OUTPUT_D);
  on(OUTPUT_E);
  on(OUTPUT_F);
}

void allOff() {
  off(OUTPUT_A);
  off(OUTPUT_B);
  off(OUTPUT_C);
  off(OUTPUT_D);
  off(OUTPUT_E);
  off(OUTPUT_F);
}
