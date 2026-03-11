#include "Stm32PwmDriver.hpp"

Stm32PwmDriver::Stm32PwmDriver(TIM_HandleTypeDef* htim, uint32_t channel)
	: htim_(htim), channel_(channel)
{
	HAL_TIM_PWM_Start(htim_, channel_);
}

Stm32PwmDriver::~Stm32PwmDriver()
{
	HAL_TIM_PWM_Stop(htim_, channel_);
}

void Stm32PwmDriver::SetAngle(float angle)
{
	if (angle < 0.0f) angle = 0.0f;
	if (angle > 180.0f) angle = 180.0f;

	uint32_t pulse = static_cast<uint32_t>(500.0f + (angle * (2000.0f / 180.0f))) + 0.5f;
	__HAL_TIM_SET_COMPARE(htim_, channel_, pulse);
}
