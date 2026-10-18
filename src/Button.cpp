#include "Button.h"


Button::Button(IDigitalInput& input): Component("Button"),input_(input){}

Button::Button(IDigitalInput& input, const string& name): Component("Button", name),input_(input){}

bool Button::isPressed()const {
    return !input_.read();
}

void Button::printStatus() const{
    log(isPressed() ? "is pressed" : "is released");
}