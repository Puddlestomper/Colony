#include "Ant.h"

#include <stdlib.h>

#include "AntColony.h"

Ant::Ant(const AntColony* colony)
	: m_colony(colony), m_position(colony->getQueen().getPosition()) {}

Ant::Ant(const AntColony* colony, const sf::Vector2f position)
	: m_colony(colony), m_position(position) {}

const sf::Vector2f Ant::getPosition() const { return m_position; }

int Ant::getDistanceFromQueen() const
{
	sf::Vector2f queenPos = m_colony->getQueen().getPosition();
	return abs((int)(m_position.x - queenPos.x)) + abs((int)(m_position.y - queenPos.y));
}