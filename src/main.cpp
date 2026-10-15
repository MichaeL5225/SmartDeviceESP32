#include <Arduino.h>
#include "Esp32Pin.h"
#include "Esp32AnalogInput.h"
#include "MoistureSensor.h"
#include "Zone.h"

Esp32AnalogInput moistureInput(34);
Esp32Pin valvePin(5);
MoistureSensor sensor(moistureInput, "Garden Sensor");
Zone garden(valvePin, "Garden",sensor, 30,60);

void setup() {
  Serial.begin(115200);
}

void loop() {
  garden.update();
  delay(1000);
}
