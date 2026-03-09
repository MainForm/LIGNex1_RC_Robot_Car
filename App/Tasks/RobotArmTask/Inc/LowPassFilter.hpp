#ifndef LOW_PASS_FILTER_HPP
#define LOW_PASS_FILTER_HPP

#include "IFilter.hpp"

class LowPassFilter : IFilter
{
private:
	float alpha;
	float prev_value;

public:
	LowPassFilter(float alpha, float initial_value);
	float Process(float raw_value) override;
};

#endif
