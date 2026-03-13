#ifndef DEBOUNCED_TOGGLE_HPP
#define DEBOUNCED_TOGGLE_HPP

#include "IButton.hpp"
#include <cstdint>

class DebouncedToggle 
{
private:
	IButton* hwButton_;
	bool toggle_state_;
	bool prev_state_;
	uint32_t last_time_;
	uint32_t debounce_delay_;

public:
	DebouncedToggle(IButton* btn, uint32_t delay);

	bool Process(uint32_t current_time);
	bool GetState() const;
};

#endif
