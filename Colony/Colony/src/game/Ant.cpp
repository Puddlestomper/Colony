#include "Ant.h"

#include <stdlib.h>

#include "AntColony.h"

Ant::Ant(const AntColony* colony)
	: m_colony(colony), m_position(colony->getQueen().getPosition()) {}

Ant::Ant(const AntColony* colony, const sf::Vector2u position)
	: m_colony(colony), m_position(position) {}

const sf::Vector2u Ant::getPosition() const { return m_position; }

int Ant::getDistanceFromQueen() const
{
	sf::Vector2u queenPos = sf::Vector2u(m_colony->getQueen().getPosition().x, m_colony->getQueen().getPosition().y);
	return abs((int)(m_position.x - queenPos.x)) + abs((int)(m_position.y - queenPos.y));
}