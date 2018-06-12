#include "Cell.h"

Cell::Cell(sf::Color colour, bool solid)
	: m_colour(colour), m_solid(solid)
{

}

const sf::Color Cell::getColour() const { return m_colour; }

const bool Cell::isSolid() const { return m_solid; }

bool Cell::operator== (const Cell& rhs) const
{
	return m_colour == rhs.getColour();
}

const Cell Cell::GRASSLAND(sf::Color(47, 193, 61));
const Cell Cell::FOREST(sf::Color(0, 127, 14));
const Cell Cell::DESERT(sf::Color(231, 142, 60));
const Cell Cell::MUD(sf::Color(86, 56, 25));
const Cell Cell::OCEAN(sf::Color(45, 94, 255), false);
const Cell Cell::LAKE(sf::Color(42, 137, 234), false);
const Cell Cell::EMPTY(sf::Color(255, 255, 255), false);

const std::array<const Cell, 7> Cell::cells = {Cell::GRASSLAND, Cell::FOREST , Cell::DESERT , Cell::MUD , Cell::OCEAN , Cell::LAKE , Cell::EMPTY };

const Cell& Cell::getCell(const sf::Color& colour)
{
	for (const Cell& c : cells) if (colour == c.getColour()) return c;
	return EMPTY;
}