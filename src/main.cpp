#include <Arduino.h>
#include "Esp32Pin.h"
#include "Esp32AnalogInput.h"
#include "MoistureSensor.h"
#include "Zone.h"
#include "Esp32DigitalInput.h"
#include "Button.h"
#include "Esp32Clock.h"

Esp32Clock systemClock;
Esp32AnalogInput moistureInput(34);
Esp32Pin valvePin(5);
MoistureSensor sensor(moistureInput, "Garden Sensor");
Esp32DigitalInput btnInput(4);
Button btn(btnInput,systemClock, "Manual button");
Zone garden(valvePin, "Garden",sensor,btn,systemClock, 30,60);

bool wasPressed = false;

void setup() {
  Serial.begin(115200);
}

void loop() {

  garden.update(); // the zone runs every iteration but the sensor inside runs every second
  btn.update(); // runs every loop iteration
  bool isPressedNow = btn.isPressed();
  if(isPressedNow != wasPressed){
    btn.printStatus();
    wasPressed = isPressedNow;
  }
  
}
