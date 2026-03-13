#ifndef STM32_BUTTON_HPP
#define STM32_BUTTON_HPP

#include "IButton.hpp"
#include "stm32f1xx_hal.h"
#include <cstdint>

class Stm32Button : public IButton
{
private:
	GPIO_TypeDef* port_;
	uint16_t pin_;

public:
	Stm32Button(GPIO_TypeDef* port, uint16_t pin);
	bool ReadState() override;
};

#endif
