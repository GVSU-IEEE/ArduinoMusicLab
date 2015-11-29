/**
 * @file HailToTheeGrandValley.ino
 * 
 * @author Ethan Ruffing <ruffinge@mail.gvsu.edu>
 * @since 2015-11-29
 * 
 * @brief Plays the Alma Mater on a piezo buzzer
 * 
 * This is based on an example program by Tom Igoe, which can be found
 * at https://www.arduino.cc/en/Tutorial/toneMelody.
 * 
 * To alter the melod that is played, place the notes for the melody in
 * the `melody` array, and the durations in the `noteDurations` array.
 * 
 * This is designed for use with a piezo buzzer connected to the
 * Arduino's digital pin 8.
 */

#include "pitches.h"

/** The tempo, in beats per minutes */
#define TEMPO 88

/** Number of notes */
#define LENGTH 62

/** The pin to which the piezo buzzer is connected. */
#define PIEZO_PIN 9

/** Notes in the melody */
int melody[] = {
  NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_DS4, REST,
  NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_AS4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_AS4, NOTE_G4,
  NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_AS4, NOTE_C5, NOTE_F4, NOTE_AS4,
  NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_DS5,
  NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_DS4
};

/** Note durations (4 = quarter note, 8 = eighth note, etc.) */
float noteDurations[] = {
  3, 8, 4, 4, 8, 2, 4, 3, 8, 4, 4, 1.5, 8,
  3, 8, 4, 4, 8, 2, 4, 3, 8, 4, 4, 1,
  3, 8, 4, 4, 8, 2, 4, 3, 8, 4, 4, 1,
  3, 8, 4, 4, 8, 8, 1.5, 3, 8, 4, 4, 1.5, 4,
  3, 8, 4, 4, 8, 2, 4, 3, 8, 4, 4, .5
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < LENGTH; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = ((float)(60.0/(TEMPO/2))) * (1000 / noteDurations[thisNote]);
    tone(PIEZO_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
