#ifndef TRAPEZOIDAL_PROFILE_HPP
#define TRAPEZOIDAL_PROFILE_HPP

#include "ITrajectory.hpp"
#include <stdint.h>

class TrapezoidalProfile : public ITrajectory
{
private:
	float current_angle;
	float current_velocity;
	float max_velocity;
	float accel;
	float decel;
	uint32_t last_tick;

public:
	TrapezoidalProfile(float cur_angle, float max_vel, float acc, float dec);

	void Update(float target_angle) override;
	float GetCurrentAngle() override;
};

#endif
