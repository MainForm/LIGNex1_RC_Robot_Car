#include "LinearMapper.hpp"

LinearMapper::LinearMapper(float in_min, float in_max, float out_min, float out_max) 
	: in_min_(in_min), in_max_(in_max), out_min_(out_min), out_max_(out_max) {}

float LinearMapper::Map(float value)
{
	if (in_max_ == in_min_) return in_max;
	return (value - in_min_) * (out_max_ - out_min_) / (in_max_ - in_min_) + out_min_;
}

