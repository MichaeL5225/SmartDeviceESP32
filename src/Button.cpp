#include "Button.h"


Button::Button(IDigitalInput& input, IClock& clockInput): Component("Button"),input_(input), clockInput_(clockInput){
    debouncer_init(&debouncer_, false, 50);
}

Button::Button(IDigitalInput& input,IClock& clockInput, const string& name): Component("Button", name),input_(input),clockInput_(clockInput){
    debouncer_init(&debouncer_, false, 50);
}

bool Button::isPressed() const{
    return debouncer_.stable_status;
}

void Button::printStatus() const{
    log(isPressed() ? "is pressed" : "is released");
}

void Button::update(){
    bool rawPressed = !input_.read();
    debouncer_update(&debouncer_, rawPressed, clockInput_.nowMs());
}