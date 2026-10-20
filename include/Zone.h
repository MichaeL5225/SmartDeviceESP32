#pragma once

#include <string>
#include "Valve.h"
#include "MoistureSensor.h"
#include "Button.h"
#include "IClock.h"
#include "ZoneState.h"

using namespace std;


class Zone
{
	private:
		const string name_;
		Valve valve_;
		MoistureSensor& moistureSensor_;
		Button& button_;
		IClock& clock_;
		int dryThreshold_;
		int wetThreshold_;
		ZoneState state_ = ZoneState::Auto;
		uint32_t manualStartMs_ = 0;
		uint32_t manualDurationMs_ = 10000;
		bool wasPressed_ = false;
		uint32_t lastSensorReadMs_ = 0;


	public:
		Zone(IOutputPin& valvePin, const string& name, MoistureSensor& moistureSensor,Button& button, IClock& clock, int dryThreshold, int wetThreshold);
		void update();
		~Zone();
		const string& getName() const;
		bool isValveOpen() const;

};

