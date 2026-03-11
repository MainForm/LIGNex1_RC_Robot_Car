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
	TrapezoidalProfile(float cur_angle, float max_vel, float acc, float dec, uint32_t current_tick);

	void Update(float target_angle, uint32_t current_tick) override;
	float GetCurrentAngle() override;
};

#endif
