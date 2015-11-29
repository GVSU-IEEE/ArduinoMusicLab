/**
 * @file Instrument.ino
 * 
 * @author Ethan Ruffing <ruffinge@mail.gvsu.edu>
 * @since 2015-11-29
 * 
 * @brief Acts as a musical instrument.
 * 
 * This program creates a basic musical instrument from the Arduino
 * through the use of a distance sensor and a piezo buzzer. The distance
 * is mapped to musical notes, and these are played whenever a button is
 * pressed.
 * 
 * The pin configuration is set using the appropriate macros below.
 */

#include "pitches.h"
#include "SharpSensor.h"

/** The pin to which the piezo buzzer is connected. */
#define PIEZO_PIN 9

/** The analog pin to which the distance sensor is connected. */
#define DIST_PIN 0

/** The digital pin to which the control button is connected. */
#define BTN_PIN 0

/**
 * Converts a distance to a frequency.
 * 
 * @param[in] dist
 *     The distance to map to a frequency
 * 
 * @returns
 *     The mapped frequency for the given distance
 */
int distToFreq(float dist);

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(BTN_PIN)) {
    tone(PIEZO_PIN, distToFreq(readDistance(DIST_PIN)));
  } else {
    noTone(PIEZO_PIN);
  }
}

int distToFreq(float dist) {
  return ((dist - 10) / 70.0) * 4947 + 31;
}

