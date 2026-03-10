#ifndef I_TRAJECTORY_HPP
#define I_TRAJECTORY_HPP

class ITrajectory
{
public:
	virtual ~ITrajectory() = default;
	virtual float GetCurrentAngle() = 0;
};

#endif
