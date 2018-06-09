#pragma once

#include <array>

#include "SFML/Graphics/Color.hpp"

class Cell
{
private:
	const sf::Color m_colour;
public:
	Cell();
	Cell(sf::Color colour);
	sf::Color getColour() const;
	
	bool operator== (const Cell& rhs) const;

	static const Cell& getCell(const sf::Color& colour);
	static const Cell GRASSLAND, DESERT, FOREST, OCEAN, LAKE, MUD, EMPTY;
	static const std::array<const Cell, 7> cells;
};