#pragma once
#include "IAnalogInput.h"

class Esp32AnalogInput : public IAnalogInput{
    public:
        Esp32AnalogInput(int pinNum);
        int read() override;
    private:
        const int pinNum_;
};