#pragma once


class IAnalogInput {
	public:
		virtual int read() = 0;
		virtual ~IAnalogInput() = default;
};