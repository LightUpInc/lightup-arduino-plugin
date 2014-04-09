#include <LightUp.h>

void setup() {
    // The length defines how long to play the tone.
    int length = 1000;

    // Start playing the tone.
    tone(OUTPUT_F, NOTE_C4);
    
    // Play it for some time.
    delay(length);
    
    Stop playing the tone.
    noTone(OUTPUT_F);
}
