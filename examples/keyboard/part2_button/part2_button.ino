#include <LightUp.h>

void setup() {

}

void loop() {
    // Read whether the button is pressed.
    if (digitalRead(INPUT_3) == PRESSED) {
        // It is pressed, play the tone.
        tone(OUTPUT_F, NOTE_C4);
    } else {
        // It is not pressed, stop playing the tone.
        noTone(OUTPUT_F);
    }
}
