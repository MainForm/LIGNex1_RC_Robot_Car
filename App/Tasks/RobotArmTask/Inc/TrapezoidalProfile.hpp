#ifndef TRAPEZOIDAL_PROFILE_HPP
#define TRAPEZOIDAL_PROFILE_HPP

#include "ITrajectory.hpp"
#include <stdint.h>

class TrapezoidalProfile : public ITrajectory
{
private:
	float current_angle_;
	float current_velocity_;
	float max_velocity_;
	float accel_;
	float decel_;
	uint32_t last_tick_;

public:
	TrapezoidalProfile(float current_angle_, float max_velocity, float accel, float decel, uint32_t current_tick);

	void Update(float target_angle, uint32_t current_tick) override;
	float GetCurrentAngle() override;
};

#endif
