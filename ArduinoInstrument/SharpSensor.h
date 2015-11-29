/**
 * @file SharpSensor.h
 * 
 * @author Ethan Ruffing
 * @since 2015-11-29
 * 
 * @brief Driver for the Sharp GP2Y0A21YK0F Analog Distance Sensor
 * 
 * This is a driver for using the Sharp GP2Y0A21YK0F Analog Distance Sensor with
 * an Arduino. To use, simply call `readDistance` for the appropriate pin.
 */

#include <avr/io.h>

#ifndef SHARPSENSOR_H_
#define SHARPSENSOR_H_
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Reads the distance from the distance sensor.
 * 
 * @param[in] pin
 *     The analog pin to which the sensor is connected.
 * 
 * @returns
 *     The distance, in centimeters, read from the sensor.
 */
float readDistance(int pin);

#ifdef __cplusplus
}
#endif
#endif

