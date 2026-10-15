
#include "Esp32AnalogInput.h"
#include <Arduino.h>

Esp32AnalogInput::Esp32AnalogInput(int pinNum) : pinNum_(pinNum){}

int Esp32AnalogInput::read(){
    return analogRead(pinNum_);
}