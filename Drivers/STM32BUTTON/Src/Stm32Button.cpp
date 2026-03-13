#include "Stm32Button.hpp"

Stm32Button::Stm32Button(GPIO_TypeDef* port, uint16_t pin)
	: port_(port), pin_(pin) {}

bool Stm32Button::ReadState()
{
	return HAL_GPIO_ReadPin(port_, pin_) == GPIO_PIN_SET;
}
