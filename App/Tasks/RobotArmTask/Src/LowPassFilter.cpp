#include "LowPassFilter.hpp"

LowPassFilter::LowPassFilter(float alpha, float initial_value) : alpha(alpha), prev_value(initial_value) {}

float LowPassFilter::Process(float raw_value)
{
	prev_value = (raw_value * alpha) + ((1.0f - alpha) * prev_value);
	return prev_value;
}
