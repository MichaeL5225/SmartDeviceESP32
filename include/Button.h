#pragma once

#include "Component.h"
#include "IDigitalInput.h"
#include "IClock.h"
#include "debounce.h"

class Button : public Component{
    public:
        Button(IDigitalInput& input, IClock& clockInput);
        Button(IDigitalInput& input,IClock& clockInput, const string& name);
        bool isPressed() const ;
        void printStatus() const override;
        void update();


    private:
        IDigitalInput& input_;
        IClock& clockInput_;
        Debouncer debouncer_;
};