#include "ServoAxis.hpp"

ServoAxis::ServoAxis(IPwmDriver* pwmDriver, ITrajectory* trajectory)
	: pwmDriver_(pwmDriver), trajectory_(trajectory), target_angle_(0.0f)
{}

void ServoAxis::SetTargetAngle(float angle)
{
	target_angle_ = angle;
}

void ServoAxis::Update(uint32_t current_tick)
{
	if (pwmDriver_ != nullptr && trajectory_ != nullptr)
	{
		trajectory_->Update(target_angle_, current_tick);
		pwmDriver_->SetAngle(trajectory_->GetCurrentAngle());
	}
}

float ServoAxis::GetCurrentAngle() const
{
	if (trajectory_ != nullptr)
	{
		return trajectory_->GetCurrentAngle();
	}
	return 0.0f;
}
