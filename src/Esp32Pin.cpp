#include "Esp32Pin.h"
#include <Arduino.h>

Esp32Pin::Esp32Pin(int pinNum): pinNum_(pinNum){
    pinMode(pinNum_, OUTPUT);
}

void Esp32Pin::write(bool on){
    digitalWrite(pinNum_, on ? HIGH : LOW);
}
