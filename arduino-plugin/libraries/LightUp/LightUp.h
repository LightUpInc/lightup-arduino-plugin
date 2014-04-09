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
#define OUTPUT_A 5
#define OUTPUT_B 10
#define OUTPUT_C 9
#define OUTPUT_D 11
#define OUTPUT_E 3
#define OUTPUT_F 6

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

// These functions intercept calls to the Arduino core libraries. These disable pullups when a pin is
// used in analog mode and also disable the signal indicator LEDs.
int lightup_analogRead(uint8_t pin);
int lightup_digitalRead(uint8_t pin);

// Helper functions.
static void setSignalLED(uint8_t signalPin, uint8_t inputPin, boolean isAnalog);

// Store which input pins have been read as analog pins.
static boolean input1IsAnalog = false;
static boolean input2IsAnalog = false;
static boolean input3IsAnalog = false;
static boolean input4IsAnalog = false;
static boolean input5IsAnalog = false;
static boolean input6IsAnalog = false;

// Configure the input and output pins on the block.
void lightup_setup_io() {
  pinMode(INPUT_1, INPUT_PULLUP);
  pinMode(INPUT_2, INPUT_PULLUP);
  pinMode(INPUT_3, INPUT_PULLUP);
  pinMode(INPUT_4, INPUT_PULLUP);
  pinMode(INPUT_5, INPUT_PULLUP);
  pinMode(INPUT_6, INPUT_PULLUP);

  pinMode(_LU_INPUT_SIGNAL_1, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_2, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_3, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_4, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_5, OUTPUT);
  pinMode(_LU_INPUT_SIGNAL_6, OUTPUT);

  pinMode(OUTPUT_A, OUTPUT);
  pinMode(OUTPUT_B, OUTPUT);
  pinMode(OUTPUT_C, OUTPUT);
  pinMode(OUTPUT_D, OUTPUT);
  pinMode(OUTPUT_E, OUTPUT);
  pinMode(OUTPUT_F, OUTPUT);
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
  // Select no prescaler and enable counter
  TCCR1B |= (1 << CS10); 
  // Turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Enable timer compare interrupt so that ISR runs every millisecond.
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Enable interrupts.
}

// This code runs every millisecond. 
ISR(TIMER1_COMPA_vect) {
  setSignalLED(_LU_INPUT_SIGNAL_1, INPUT_1, input1IsAnalog);
  setSignalLED(_LU_INPUT_SIGNAL_2, INPUT_2, input2IsAnalog);
  setSignalLED(_LU_INPUT_SIGNAL_3, INPUT_3, input3IsAnalog);
  setSignalLED(_LU_INPUT_SIGNAL_4, INPUT_4, input4IsAnalog);
  setSignalLED(_LU_INPUT_SIGNAL_5, INPUT_5, input5IsAnalog);
  setSignalLED(_LU_INPUT_SIGNAL_6, INPUT_6, input6IsAnalog);
}

// Helper function that only sets signal LEDs when pin is digital.
static void setSignalLED(uint8_t signalPin, uint8_t inputPin, boolean isAnalog) {
  if (isAnalog) {
    digitalWrite(signalPin, LOW);
  } else {
    digitalWrite(signalPin, digitalRead(inputPin));
  }
}

// This intercepts what would otherwise be a call to analogRead. In addition
// to calling analogRead, it stores the call so we know the pin is analog.
int lightup_analogRead(uint8_t pin) {

  pinMode(pin, INPUT);

  if (pin == INPUT_1) {
    input1IsAnalog = true;
  } else if (pin == INPUT_2)  {
    input2IsAnalog = true;
  } else if (pin == INPUT_3)  {
    input3IsAnalog = true;
  } else if (pin == INPUT_4)  {
    input4IsAnalog = true;
  } else if (pin == INPUT_5)  {
    input5IsAnalog = true;
  } else if (pin == INPUT_6)  {
    input6IsAnalog = true;
  }

  return analogRead(pin);
}

// This intercepts what would otherwise be a call to digitalRead. In addition
// to calling wiring_digitalRead, it stores the call so we know the pin is digital.
int lightup_digitalRead(uint8_t pin) {

  pinMode(pin, INPUT_PULLUP);

  if (pin == INPUT_1) {
    input1IsAnalog = false;
  } else if (pin == INPUT_2)  {
    input2IsAnalog = false;
  } else if (pin == INPUT_3)  {
    input3IsAnalog = false;
  } else if (pin == INPUT_4)  {
    input4IsAnalog = false;
  } else if (pin == INPUT_5)  {
    input5IsAnalog = false;
  } else if (pin == INPUT_6)  {
    input6IsAnalog = false;
  }

  return digitalRead(pin);
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

// Rename Arduino core functions that need to be intercepted.
#define analogRead(pin) lightup_analogRead(pin)
#define digitalRead(pin) lightup_digitalRead(pin)

// Definintions of commonly used things.
#include "button.h""
#include "pitches.h"

#endif //__LIGHTUP_H__

