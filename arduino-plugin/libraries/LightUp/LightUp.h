#ifndef __LIGHTUP_H__
#define __LIGHTUP_H__

#include "Arduino.h"

// We're using the Arduino Leonardo's bootloader and configuration so the pin numbers
// are defined based on the Leonardo, not the underlying Atmel 32u4.

// These pins connect to block terminals designed for digital and analog input.
#define INPUT_1 A0
#define INPUT_2 A1
#define INPUT_3 A2
#define INPUT_4 A3
#define INPUT_5 A4
#define INPUT_6 A5

// These pins connect to block terminals designed for digital and analog (PWM) output.
// The block's output terminals are connected to LEDs to display the digital signal value.
#define OUTPUT_1 5
#define OUTPUT_2 10
#define OUTPUT_3 9
#define OUTPUT_4 11
#define OUTPUT_5 3
#define OUTPUT_6 6

// These pins connect to signal LEDs next to the corresponding input pins. Reading the
// signal on the input pin and then writing it to the signal LED guarantees that the
// value on the signal LED accurately reflects what the software sees. This is important
// in the case of internal pull up resistors being enabled and floating connections.
// This technique also requires no circuitry on the input pins themselves preserving the 
// integrity of analog signal values.
#define _LU_INPUT_SIGNAL_1 7
#define _LU_INPUT_SIGNAL_2 2
#define _LU_INPUT_SIGNAL_3 1
#define _LU_INPUT_SIGNAL_4 13
#define _LU_INPUT_SIGNAL_5 12
#define _LU_INPUT_SIGNAL_6 4

// These functions are called during initialization to setup the I/O ports and debugging
// lights on the block.
void lightup_setup_io();
void lightup_setup_timer();

// This function contains the user's program setup code. This is normally in a function
// called "setup" for Arduino, but we overwrite that function with the LightUp's setup routine.
// To prevent users from getting confused, a macro renames their setup to user_setup automatically.
void user_setup();

// Configure the input and output pins on the block.
void lightup_setup_io() {
  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
  pinMode(INPUT_3, INPUT);
  pinMode(INPUT_4, INPUT);
  pinMode(INPUT_5, INPUT);
  pinMode(INPUT_6, INPUT);

  pinMode(_LU_INPUT_SIGNAL_1, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_2, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_3, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_4, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_5, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_6, OUTPUT);

  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);
  pinMode(OUTPUT_5, OUTPUT);
  pinMode(OUTPUT_6, OUTPUT);
}

void lightup_setup_timer() {
  cli(); // Disable interrupts while we configure interrupts.

  // Set Timer1 to interrupt at 1kHz (every millisecond).
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  // Set compare match register for 1kHz increments
  // OCR1A = CLOCK_FREQUENCY / PRESCALER / INTERRUPT_FREQUENCY - 1
  OCR1A = 7999; // = (8*10^6) / 1 / (1*10e3) - 1
  // Turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Enable timer compare interrupt so that ISR runs every millisecond.
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Enable interrupts.
}

// This code runs every millisecond. 
ISR(TIMER1_COMPA_vect) {
  digitalWrite(_LU_INPUT_SIGNAL_1, digitalRead(INPUT_1));
  digitalWrite(_LU_INPUT_SIGNAL_2, digitalRead(INPUT_2));
  digitalWrite(_LU_INPUT_SIGNAL_3, digitalRead(INPUT_3));
  digitalWrite(_LU_INPUT_SIGNAL_4, digitalRead(INPUT_4));
  digitalWrite(_LU_INPUT_SIGNAL_5, digitalRead(INPUT_5));
  digitalWrite(_LU_INPUT_SIGNAL_6, digitalRead(INPUT_6));
}

// Arduino setup actually invokes the lightup setup routine. The end of this
// routine calls user_setup which invokes the program's setup routine.
void setup() {
  lightup_setup_io();

#ifndef DISABLE_INPUT_SIGNAL_PROPAGATION_TIMER
  lightup_setup_timer();
#endif

  // Run the user's setup code. This is normally in the function called "setup"
  // in Arduino code.
  user_setup();
}

// Rename the user program's setup function to user_setup.
#define setup() user_setup()

#endif //__LIGHTUP_H__

