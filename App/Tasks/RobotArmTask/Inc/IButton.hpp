#ifndef I_BUTTON_HPP
#define I_BUTTON_HPP

class IButton
{
public:
	virtual ~IButton() = default;
	virtual bool ReadState() = 0;
};

#endif
