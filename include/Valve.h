#pragma once

#include <string>
#include "Component.h"
#include "IOutputPin.h"
using namespace std;

class Valve : public Component
{
private:
	bool isOpen_ = false;
	IOutputPin& pin_;

public:
	Valve(IOutputPin& pin);
	Valve (IOutputPin& pin, const string& name);
	void open();
	void close();
	bool isOpen() const;
	void printStatus() const override;
};

