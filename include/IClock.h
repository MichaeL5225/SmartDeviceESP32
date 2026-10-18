#pragma once

#include <stdint.h>

class IClock {
    public:
        virtual uint32_t nowMs() const = 0;
        virtual ~IClock() = default;
};