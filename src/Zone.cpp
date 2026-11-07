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
	bool justPressed = nowPressed && !wasPressed_;
	wasPressed_ = nowPressed;

	bool secondPassed = (now - lastSensorReadMs_ >= 1000);

	int moisture = 0;

	if (secondPassed) { // runs every one second
		lastSensorReadMs_ = now;

		Serial.print("update on ");
		Serial.print(name_.c_str());
		Serial.println(" Zone:");

		moisture = moistureSensor_.read();
		
		if (moistureSensor_.isAtEdge(moisture)){
			if (!sensorAtEdge_){
				sensorAtEdge_ = true;
				edgeStartMs_ = now;
			}
			else {
				if (state_ != ZoneState::Fault && now - edgeStartMs_ >= edgeFaultMs_) { // has the sensor been at the edge for 10 seconds?
					state_ = ZoneState::Fault;
					valve_.close();
					Serial.print(name_.c_str());                    // which zone has the fault
					Serial.println(" sensor fault, valve closed");  // what happened
				}
			}
		}
		else{
				sensorAtEdge_ = false;
				edgeStartMs_ = 0;
		}
	}

	switch (state_) {
		case ZoneState::Auto:

			if (secondPassed) {
				if (moisture > wetThreshold_) {
				valve_.close();
				}
				else if (moisture < dryThreshold_) {
					valve_.open();
				}
			}	
				
			if (justPressed) {
				state_ = ZoneState::Manual;
				manualStartMs_ = now;
				valve_.open();
				Serial.print(name_.c_str());
				Serial.println(" manual watering started");
			}

			break;
		case ZoneState::Manual:
			
			if (justPressed) {
				valve_.close();
				state_ = ZoneState::Auto;
				Serial.print(name_.c_str());
				Serial.println(" manual watering cancelled");
			}

			if (now - manualStartMs_ >= manualDurationMs_) {
				valve_.close();
				state_ = ZoneState::Auto;
				Serial.print(name_.c_str());
				Serial.println(" manual watering finished");
			}


			break;
		case ZoneState::Fault:
			
			break;
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

