#ifndef LOW_PASS_FILTER_HPP
#define LOW_PASS_FILTER_HPP

#include "IFilter.hpp"

class LowPassFilter : public IFilter
{
private:
	float alpha_;
	float prev_value_;

public:
	LowPassFilter(float alpha, float initial_value);
	float Process(float raw_value) override;
};

#endif
