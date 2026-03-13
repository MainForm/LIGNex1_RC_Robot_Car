#ifndef ANALOG_INPUT_HPP
#define ANALOG_INPUT_HPP

#include "IFilter.hpp"
#include "LinearMapper.hpp"

class AnalogInput 
{
private:
	IFilter* filter_;
	LinearMapper mapper_;
	float current_raw_value_;

public:
	AnalogInput(IFilter* filter, LinearMapper mapper);

	void SetRawValue(float raw_value);
	float GetProcessedValue();

};

#endif
