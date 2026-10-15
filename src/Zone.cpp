#include "Zone.h"
#include <string>
#include <Arduino.h>

using namespace std;

Zone::Zone(IOutputPin& valvePin, const string& name, MoistureSensor& moistureSensor, int dryThreshold, int wetThreshold) :
	name_(name),
	valve_(valvePin, name + " valve"),
	moistureSensor_(moistureSensor),
	dryThreshold_(dryThreshold),
	wetThreshold_(wetThreshold)
{

	Serial.print(name_.c_str());
	Serial.println(" created");
}

void Zone::update() {
	Serial.print("update on ");
	Serial.print(name_.c_str());
	Serial.println(" Zone:");

	int moisture = moistureSensor_.read();
	
	if (moisture > wetThreshold_) {
		valve_.close();
	}
	else if (moisture < dryThreshold_) {
		valve_.open();
	}
}

Zone::~Zone() {

	Serial.print(name_.c_str());
	Serial.println(" destroyed");
}

const string& Zone::getName() const {
	return name_;
}

bool Zone::isValveOpen() const {
	return valve_.isOpen();
}

