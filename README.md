lightup-arduino-plugin
======================

Requirements
-----------

The plugin is designed for Arduino 1.5.x and has been tested on Arduino 1.5.5.

Installation
------------

1. Locate your Arduino Sketchbook folder by opening Arduino IDE and clicking ```File > Preferences```.
2. Copy ```arduino-plugin/hardware/lightup``` into ```${ARDUINO_SKETCHBOOK}/hardware/```. If no folder named ```hardware``` exists, create it.
3. Copy ```arduino-plugin/libraries/LightUp``` into ```${ARDUINO_SKETCHBOOK}/libraries/```. If no folder named ```libraries``` exists, create it.
4. Open Arduino IDE. You should see LightUp listed under ```Tools > Board``` and ```Sketch > Import Library```

Usage
-----

Plug in the LightUp microcontroller block, select ```Tools > Board > LightUp``` and ```Sketch > Import Library > LightUp```. You should be good to go.
