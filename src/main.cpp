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
Zone garden(valvePin, "Garden",sensor, 30,60);
Esp32DigitalInput btnInput(4);
Button btn(btnInput,systemClock, "Manual button");

unsigned long lastUpdate = 0;
bool wasPressed = false;

void setup() {
  Serial.begin(115200);
}

void loop() {

  if (millis() - lastUpdate >= 1000){
    lastUpdate = millis();
    garden.update();
  }
  btn.update();
  bool isPressedNow = btn.isPressed();
  if(isPressedNow != wasPressed){
    btn.printStatus();
    wasPressed = isPressedNow;
  }
  
}
