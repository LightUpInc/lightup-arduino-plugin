#include <LightUp.h>

void setup() {
    // The pitch defines which note to play.
    // Change the value (try 500 and 1500) and listen to the pitch change.
    // Change the value to NOTE_C4 and listen to a predefined note.
    int pitch = 1000;
    
    // The length defines how long to play the tone.
    // Change the value (try 2000) and listen to the tone play longer.
    int length = 1000;

    // Start playing the tone.
    tone(OUTPUT_F, pitch);
    
    // Play it for some time.
    delay(length);
    
    Stop playing the tone.
    noTone(OUTPUT_F);
}
