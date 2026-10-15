#pragma once

#include <string>
#include "Valve.h"
#include "MoistureSensor.h"

using namespace std;


class Zone
{
	private:
		const string name_;
		Valve valve_;
		MoistureSensor& moistureSensor_;
		int dryThreshold_;
		int wetThreshold_;

	public:
		Zone(IOutputPin& valvePin, const string& name, MoistureSensor& moistureSensor, int dryThreshold, int wetThreshold);
		void update();
		~Zone();
		const string& getName() const;
		bool isValveOpen() const;

};

