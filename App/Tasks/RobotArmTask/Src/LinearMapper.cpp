#include "LinearMapper.hpp"

LinearMapper::LinearMapper(float in_min, float in_max, float out_min, float out_max) 
	: in_min(in_min), in_max(in_max), out_min(out_min), out_max(out_max) {}

float LinearMapper::Map(float value)
{
	if (in_max == in_min) return in_max;
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

