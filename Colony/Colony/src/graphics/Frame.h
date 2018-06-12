#pragma once

#include "SFML/Graphics/Drawable.hpp"

class Frame : public sf::Drawable
{
protected:
	const unsigned int m_width, m_height;
public:
	Frame(unsigned int width, unsigned int height);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};