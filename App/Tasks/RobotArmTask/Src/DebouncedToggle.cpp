#include "DebouncedToggle.hpp"

DebouncedToggle::DebouncedToggle(IButton* btn, uint32_t delay)
	: hwButton_(btn), toggle_state_(false), prev_state_(false), last_time_(0), debounce_delay_(delay) {}

bool DebouncedToggle::Process(uint32_t current_time)
{
	bool current_raw = hwButton_->ReadState();

	if (current_raw != prev_state_)
	{
		last_time_ = current_time;
	}

	if ((current_time - last_time_) > debounce_delay_)
	{
		if (current_raw == true && prev_state_ == false)
		{
			toggle_state_ =! toggle_state_;
		}
	}

	prev_state_ = current_raw;
	return toggle_state_;
}

bool DebouncedToggle::GetState() const 
{
	return toggle_state_;
}
