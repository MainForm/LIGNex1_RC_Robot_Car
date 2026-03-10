#ifndef LINEAR_MAPPER_HPP
#define LINEAR_MAPPER_HPP

class LinearMapper
{
private:
	float in_min;
	float in_max;
	float out_min;
	float out_max;

public:
	LinearMapper(float in_min, float in_max, float out_min, float out_max);
	float Map(float value);
};

#endif
