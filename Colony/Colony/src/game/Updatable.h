#pragma once

class Updatable
{
public:
	//virtual ~Updatable() = 0;
	virtual void update(unsigned long ticks) = 0;
};