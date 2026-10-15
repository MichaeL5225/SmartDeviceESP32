#pragma once

#include <string>
#include "Component.h"
#include "IAnalogInput.h"

using namespace std;

class MoistureSensor : public Component
{
	private: 
		IAnalogInput& input_;
		int lastReading_ = 0;

	public:
		MoistureSensor(IAnalogInput& input_);
		MoistureSensor(IAnalogInput& input_, const string& name);
		int getLastReading() const;
		int read();
		void printStatus() const override;
};

