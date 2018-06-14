#pragma once

class Updatable
{
public:
	virtual void update(const unsigned long& ticks) = 0;
};