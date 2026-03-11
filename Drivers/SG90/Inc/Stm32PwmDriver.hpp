#ifndef STM32_PWM_DRIVER_HPP
#define STM32_PWM_DRIVER_HPP

#include "IPwmDriver.hpp"
#include "stm32f1xx_hal.h"

class Stm32PwmDriver : public IPwmDriver
{
private:
	TIM_HandleTypeDef* htim_;
	uint32_t channel_;

public:
	Stm32PwmDriver(TIM_HandleTypeDef* htim, uint32_t channel);
	~Stm32PwmDriver() override;
	void SetAngle(float angle) override;
};

#endif
