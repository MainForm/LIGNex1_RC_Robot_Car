#include "MovingAverageFilter.hpp"

MovingAverageFilter::MovingAverageFilter(int window_size) 
	: window_size_(window_size), index_(0), sum_(0.0f)
{
	buffer_ = new float[window_size_];
	for (int i = 0; i < window_size_; ++i) buffer_[i] = 0.0f;
}

MovingAverageFilter::~MovingAverageFilter()
{
	delete[] buffer_;
}

float MovingAverageFilter::Process(float raw_value)
{
	sum_ -= buffer_[index_];
	buffer_[index_] = raw_value;
	sum_ += buffer_[index_];

	index_ = (index_ + 1) % window_size_;

	return sum_ / window_size_;
}
