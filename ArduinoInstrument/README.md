Arduino Instrument
==================
Copyright 2015 by the Grand Valley State University Branch of the IEEE.

This is a sample project for creating an instrument using an Arduino UNO.
To use the program, connect a distance sensor, a piezo buzzer, and a momentary
pushbutton switch to the Arduino. Set the pins appropriately using the macros
in the `ArduinoInstrument.ino` file and upload the program.

The instrument will play a note corresponding to the distance read on the sensor
whenever the button is pressed. While the button is not pressed, it will play
nothing.
