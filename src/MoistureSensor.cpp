#include "MoistureSensor.h"
#include <string>

using namespace std;


MoistureSensor::MoistureSensor(IAnalogInput& input) : Component("MoistureSensor"), input_(input) {}

MoistureSensor::MoistureSensor(IAnalogInput& input, const string& name) : Component("MoistureSensor", name), input_(input) {}

int MoistureSensor::getLastReading() const {
	return lastReading_;
}

int MoistureSensor::read() {
	int raw = input_.read();
	lastReading_ = raw * 100 / 4095;
	log("read: " + to_string(lastReading_));
	return lastReading_;
}

bool MoistureSensor::isAtEdge(int reading) const {
	return reading == MIN_READING || reading == MAX_READING;
}

void MoistureSensor::printStatus() const {
	log("last reading is: " + to_string(lastReading_));
}
