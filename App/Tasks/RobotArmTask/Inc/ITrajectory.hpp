#ifndef I_TRAJECTORY_HPP
#define I_TRAJECTORY_HPP

#include <cstdint>

class ITrajectory
{
public:
	virtual ~ITrajectory() = default;
	virtual void Update(float target_angle, uint32_t current_tick) = 0;
	virtual float GetCurrentAngle() = 0;
};

#endif
