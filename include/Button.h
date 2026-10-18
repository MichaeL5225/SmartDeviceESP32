#pragma once

#include "Component.h"
#include "IDigitalInput.h"

class Button : public Component{
    public:
        Button(IDigitalInput& input);
        Button(IDigitalInput& input, const string& name);
        bool isPressed() const ;
        void printStatus() const override;


    private:
        IDigitalInput& input_;
};