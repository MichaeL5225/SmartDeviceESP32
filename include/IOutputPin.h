#pragma once

class IOutputPin {
	public:
		virtual void write(bool on) = 0;
		virtual ~IOutputPin() = default;
};
