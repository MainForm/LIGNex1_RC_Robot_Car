#ifndef LINEAR_MAPPER_HPP
#define LINEAR_MAPPER_HPP

class LinearMapper
{
private:
	float in_min_;
	float in_max_;
	float out_min_;
	float out_max_;

public:
	LinearMapper(float in_min, float in_max, float out_min, float out_max);
	float Map(float value);
};

#endif
