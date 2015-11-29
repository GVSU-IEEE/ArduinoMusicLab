/**
 * @file SharpSensor.c
 * 
 * @author Ethan Ruffing
 * @since 2015-11-29
 * 
 * @brief Implementation of SharpSensor.h
 * 
 * This file contains implementations of the functions declared in SharpSensor.h.
 */

#include "SharpSensor.h"

/**
 * Converts a binary reading of an analog sensor value to a voltage. Assumes that
 * the voltage returned will be between 0V and 5V.
 *
 * @param[in] bin
 *     The binary (byte value) reading of the analog sensor
 * @returns
 *     The converted voltage reading of the analog sensor
 */
double binToVolt(int bin) {
  return ((double)bin / 255) * 5.0;
}

/**
 * Converts a voltage reading to a distance, in centimeters, for the Sharp
 * GP2Y0A21YK0F distance sensor. Formula found using a power model regression 
 * on data from the Sharp sensor datasheet.
 * 
 * @param[in] v
 *     The voltage reading from the sensor
 * @returns
 *     The distance, in cm, that the sensor is reading
 */
double voltToDist(double v) {
  return 26.5574 * pow(v, -1.19027);
}

/**
 * Reads an analog sensor value.
 * @param[in] sens
 *     The sensor to read from (0-5)
 * @returns
 *     The voltage of the sensor, on a scale of 0 to 255
 */
uint8_t read_sensor(int sens) {
  uint8_t sensorVoltage;

  ADMUX = _BV(REFS0) | _BV(ADLAR) | sens;

  ADCSRA = _BV(ADEN) | _BV(ADIF) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);

  ADCSRB = 0;

  ADCSRA |= _BV(ADSC);

  while((ADCSRA & _BV(ADIF)) == 0);

  sensorVoltage = (uint8_t)ADCH;

  return sensorVoltage;
}

float readDistance(int pin) {
  return voltToDist(binToVolt(read_sensor(pin)));
}

