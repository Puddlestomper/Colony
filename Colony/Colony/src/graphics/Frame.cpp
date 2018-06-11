#include "Frame.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

Frame::Frame(unsigned int width, unsigned int height)
	: m_width(width), m_height(height) {}

unsigned int Frame::getWidth() const { return m_width; }

unsigned int Frame::getHeight() const { return m_height; }

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rect(sf::Vector2f(m_width, m_height));
	target.draw(rect, states);
}