#ifndef I_FILTER_HPP
#define I_FILTER_HPP

class IFilter
{
public:
	virtual ~IFilter() = default;
	virtual float Process(float raw_value) = 0;
};

#endif
