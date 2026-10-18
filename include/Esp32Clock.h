#pragma once

#include "IClock.h"

class Esp32Clock : public IClock{
    public:
        uint32_t nowMs() const override;

};