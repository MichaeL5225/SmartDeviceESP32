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
		static const int MIN_READING = 0;
		static const int MAX_READING = 4095;
		

	public:
		MoistureSensor(IAnalogInput& input_);
		MoistureSensor(IAnalogInput& input_, const string& name);
		int getLastReading() const;
		int read();
		bool isAtEdge(int reading) const;  // true if the reading equals MIN_READING or MAX_READING
		void printStatus() const override;
};

