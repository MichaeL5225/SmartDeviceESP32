#include "Component.h"
#include <Arduino.h>
#include <string>

using namespace std;

int Component::nextId_ = 0;

Component::Component(const string& kind, const string& name) : 
	id_(nextId_++),
	name_(name.empty() ? kind + " - " + to_string(id_) : name)
{
	log("created");
}

int Component::getId() const {
	return id_;
}

const string& Component::getName() const {
	return name_;
}

void Component::log(const string& message) const{
	Serial.print(name_.c_str());
	Serial.print(" ");
	Serial.println(message.c_str());
}

Component::~Component() {
	log("destroyed");
}

