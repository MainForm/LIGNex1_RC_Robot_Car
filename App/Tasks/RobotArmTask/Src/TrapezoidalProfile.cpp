#include "TrapezoidalProfile.hpp"
#include "stm32f1xx_hal.h"
#include <cmath>

TrapezoidalProfile::TrapezoidalProfile(float cur_angle, float max_vel, float acc, float dec) : current_angle(cur_angle), current_velocity(0.0f), max_velocity(max_vel), accel(acc), decel(dec)
{
	last_tick = HAL_GetTick();
}

void TrapezoidalProfile::Update(float target_angle)
{
	uint32_t now = HAL_GetTick();
	float dt = (now - last_tick) / 1000.0f;

	if (dt < 0.001f || dt > 0.1f) return;

	last_tick = now;

	float distance = target_angle - current_angle;
	int direction = distance > 0 ? 1 : -1;
	distance = fabsf(distance);

	if (distance < 1.0f && fabsf(current_velocity) < 2.0f)
	{
		current_angle = target_angle;
		current_velocity = 0.0f;
		return;
	}

	float stopping_distance = (current_velocity * current_velocity) / (2.0f * decel);

	if (distance <= stopping_distance)
	{
		current_velocity -= decel * dt * direction;

		if (direction == 1 && current_velocity < 0) current_velocity = 0.0f;
		if (direction == -1 && current_velocity > 0) current_velocity = 0.0f;

	}
	else
	{
		float target_velocity = max_velocity * direction;

		if (direction == 1 && current_velocity < target_velocity)
			current_velocity += accel * dt * direction;
		if (direction == -1 && current_velocity > target_velocity)
			current_velocity += accel * dt * direction;

		if (current_velocity > max_velocity) current_velocity = max_velocity;
		if (current_velocity < -max_velocity) current_velocity = -max_velocity;
	}

	current_angle += current_velocity * dt;
}

float TrapezoidalProfile::GetCurrentAngle()
{
	return current_angle;
}
