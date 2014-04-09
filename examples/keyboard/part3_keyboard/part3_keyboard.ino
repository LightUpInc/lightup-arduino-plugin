#include <LightUp.h>

void setup() {

}

void loop() {
  
    // Check which button is pressed and play the note.
    if (digitalRead(INPUT_1) == PRESSED) {
        tone(OUTPUT_F, NOTE_C4);
    } else if (digitalRead(INPUT_2) == PRESSED) {
        tone(OUTPUT_F, NOTE_D4);
    } else if (digitalRead(INPUT_3) == PRESSED) {
        tone(OUTPUT_F, NOTE_E4);
    } else if (digitalRead(INPUT_4) == PRESSED) {
        tone(OUTPUT_F, NOTE_F4);
    } else if (digitalRead(INPUT_5) == PRESSED) {
        tone(OUTPUT_F, NOTE_G4);
    } else if (digitalRead(INPUT_6) == PRESSED) {
        tone(OUTPUT_F, NOTE_A5);
    } else {
        // Nothing is pressed, stop playing the tone.
        noTone(OUTPUT_F);
    }
    
}
