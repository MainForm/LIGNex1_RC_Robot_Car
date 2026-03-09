#include "MovingAverageFilter.hpp"

MovingAverageFilter::MovingAverageFilter(int size) 
	: window_size(size), index(0), sum(0.0f)
{
	buffer = new float[window_size];
	for (int i = 0; i < window_size; ++i) buffer[i] = 0.0f;
}

MovingAverageFilter::~MovingAverageFilter()
{
	delete[] buffer;
}

float MovingAverageFilter::Process(float raw_value)
{
	sum -= buffer[index];
	buffer[index] = raw_value;
	sum += buffer[index];

	index = (index + 1) % window_size;

	return sum / window_size;
}
