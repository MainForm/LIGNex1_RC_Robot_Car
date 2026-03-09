#ifndef I_PWM_DRIVER_HPP
#define I_PWM_DRIVER_HPP

class IPwmDriver 
{
public:
	virtual ~IPwmDriver() = default;
	virtual void SetAngle(float angle) = 0;
};

#endif
