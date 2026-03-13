#ifndef MOVING_AVERAGE_FILTER_HPP
#define MOVING_AVERAGE_FILTER_HPP

#include "IFilter.hpp"

class MovingAverageFilter : public IFilter
{
private:
	int window_size_;
	float* buffer_;
	int index_;
	float sum_;

public:
	MovingAverageFilter(int window_size);
	~MovingAverageFilter();
	float Process(float raw_value) override;
};

#endif
