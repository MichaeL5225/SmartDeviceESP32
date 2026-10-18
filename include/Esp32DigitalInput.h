#pragma once
#include "IDigitalInput.h"

class Esp32DigitalInput : public IDigitalInput{
    public:
        Esp32DigitalInput(int pinNum);
        bool read() override;
    private:
        const int pinNum_;

};