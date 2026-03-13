#include "LowPassFilter.hpp"

LowPassFilter::LowPassFilter(float alpha, float initial_value) : alpha_(alpha), prev_value_(initial_value) {}

float LowPassFilter::Process(float raw_value)
{
	prev_value_ = (raw_value * alpha_) + ((1.0f - alpha_) * prev_value_);
	return prev_value_;
}
