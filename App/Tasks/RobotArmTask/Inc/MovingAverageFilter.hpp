#ifndef MOVING_AVERAGE_FILTER_HPP
#define MOVING_AVERAGE_FILTER_HPP

#include "IFilter.hpp"

class MovingAverageFilter : IFilter
{
private:
	int window_size;
	float* buffer;
	int index;
	float sum;

public:
	MovingAverageFilter(int size);
	~MovingAverageFilter();
	float Process(float raw_value) override;
};

#endif
