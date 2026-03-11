#ifndef SERVO_AXIS_HPP
#define SERVO_AXIS_HPP

#include "IPwmDriver.hpp"
#include "ITrajectory.hpp"
#include <cstdint>

class ServoAxis 
{
private:
	IPwmDriver* pwmDriver_;
	ITrajectory* trajectory_;
	float target_angle_;

public:
	ServoAxis(IPwmDriver* pwmDriver, ITrajectory* trajectory);

	void SetTargetAngle(float angle);
	void Update(uint32_t current_tick);
	float GetCurrentAngle() const;
};

#endif
