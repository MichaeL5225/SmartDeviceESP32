#include "Valve.h"
#include <string>

using namespace std;


Valve::Valve(IOutputPin& pin) :Component("Valve") ,pin_(pin){}

Valve::Valve(IOutputPin& pin, const string& name) : Component("Valve", name), pin_(pin) {}

void Valve::open() {

	if (isOpen_) {
		log("is already open !");
	}
	else {
		isOpen_ = true;
		pin_.write(true);
		log("opened");
	}
}

void Valve::close() {
	if (!isOpen_) {
		log("is already closed !");
	}
	else {
		isOpen_ = false;
		pin_.write(false);
		log("closed");
	}
}

bool Valve::isOpen() const {
	return isOpen_;
}

void Valve::printStatus() const{
	log(isOpen_ ? "is open" : "is closed");
}



