#pragma once

class IDigitalInput {
    public:
        virtual bool read () = 0;
        virtual ~IDigitalInput() = default;
};