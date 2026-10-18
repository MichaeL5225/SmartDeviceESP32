#include "Esp32DigitalInput.h"
#include <Arduino.h>

Esp32DigitalInput::Esp32DigitalInput(int pinNum):pinNum_(pinNum){
    pinMode(pinNum_, INPUT_PULLUP);
}

bool Esp32DigitalInput::read(){
    return digitalRead(pinNum_) == HIGH;
}