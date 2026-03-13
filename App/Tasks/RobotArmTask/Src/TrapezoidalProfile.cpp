#include "TrapezoidalProfile.hpp"
#include <cmath>

TrapezoidalProfile::TrapezoidalProfile(float current_angle, float max_velocity, float accel, float decel, uint32_t current_tick) 
	: current_angle_(current_angle), current_velocity_(0.0f), max_velocity_(max_velocity), accel_(accel), decel_(decel), last_tick_(current_tick) {}

void TrapezoidalProfile::Update(float target_angle, uint32_t current_tick)
{
	float dt = (current_tick - last_tick_) / 1000.0f;

	last_tick_ = current_tick;

	if (dt < 0.001f || dt > 0.1f) return;

	float distance = target_angle - current_angle_;
	int direction = distance > 0 ? 1 : -1;
	distance = fabsf(distance);

	if (distance < 1.0f && fabsf(current_velocity_) < 2.0f)
	{
		current_angle_ = target_angle;
		current_velocity_ = 0.0f;
		return;
	}

	float stopping_distance = (current_velocity_ * current_velocity_) / (2.0f * decel_);

	if (distance <= stopping_distance)
	{
		current_velocity_ -= decel_ * dt * direction;

		if (direction == 1 && current_velocity_ < 0) current_velocity_ = 0.0f;
		if (direction == -1 && current_velocity_ > 0) current_velocity_ = 0.0f;

	}
	else
	{
		float target_velocity = max_velocity_ * direction;

		if (direction == 1 && current_velocity_ < target_velocity)
			current_velocity_ += accel_ * dt * direction;
		if (direction == -1 && current_velocity_ > target_velocity)
			current_velocity_ += accel_ * dt * direction;

		if (current_velocity_ > max_velocity_) current_velocity_ = max_velocity_;
		if (current_velocity_ < -max_velocity_) current_velocity_ = -max_velocity_;
	}

	current_angle_ += current_velocity_ * dt;
}

float TrapezoidalProfile::GetCurrentAngle()
{
	return current_angle_;
}
