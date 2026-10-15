#pragma once
#include "IOutputPin.h"

class Esp32Pin : public IOutputPin{
    public:
        Esp32Pin(int pinNum);
        void write(bool on) override;
    private:
        const int pinNum_;
};