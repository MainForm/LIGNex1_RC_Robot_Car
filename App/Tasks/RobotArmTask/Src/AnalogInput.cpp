#include "AnalogInput.hpp"

AnalogInput::AnalogInput(IFilter* filter, LinearMapper mapper)
	: filter_(filter), mapper_(mapper), current_raw_value_(0.0f) {}

void AnalogInput::SetRawValue(float raw_value)
{
	current_raw_value_ = raw_value;
}

float AnalogInput::GetProcessedValue()
{
	float val = current_raw_value_;

	if (filter_ != nullptr)
	{
		val = filter_->Process(val);
	}

	return mapper_.Map(val);
}
