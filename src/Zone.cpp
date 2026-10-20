#include "Zone.h"
#include <string>
#include <Arduino.h>

using namespace std;

Zone::Zone(IOutputPin& valvePin, const string& name, MoistureSensor& moistureSensor,Button& button, IClock& clock, int dryThreshold, int wetThreshold) :
	name_(name),
	valve_(valvePin, name + " valve"),
	moistureSensor_(moistureSensor),
	button_(button),
	clock_(clock),
	dryThreshold_(dryThreshold),
	wetThreshold_(wetThreshold)
	
{

	Serial.print(name_.c_str());
	Serial.println(" created");
}

void Zone::update() {
	

	uint32_t now = clock_.nowMs();

	bool nowPressed = button_.isPressed();

	if (nowPressed && !wasPressed_){
		manualActive_ = true;
		manualStartMs_ = now;
		valve_.open();
	}

	wasPressed_ = nowPressed;

	if (manualActive_ && now - manualStartMs_ >= manualDurationMs_) {
		valve_.close();
		manualActive_ = false;
	}

	if (now - lastSensorReadMs_ >= 1000){
		lastSensorReadMs_ = now;

		Serial.print("update on ");
		Serial.print(name_.c_str());
		Serial.println(" Zone:");

		int moisture = moistureSensor_.read();


		if (!manualActive_){
			if (moisture > wetThreshold_) {
				valve_.close();
			}
			else if (moisture < dryThreshold_) {
				valve_.open();
			}
		}
		
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

