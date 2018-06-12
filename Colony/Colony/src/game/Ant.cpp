#include "Ant.h"

#include <stdlib.h>

#include "AntColony.h"

Ant::Ant(AntColony* const colony, unsigned int index)
	: m_colony(colony), m_position(colony->getQueen().getPosition()), m_index(index) {}

Ant::Ant(AntColony* const colony, const sf::Vector2u position, unsigned int index)
	: m_colony(colony), m_position(position), m_index(index) {}

const sf::Vector2u& Ant::getPosition() const { return m_position; }

int Ant::getDistanceFromQueen() const
{
	sf::Vector2u queenPos = sf::Vector2u(m_colony->getQueen().getPosition().x, m_colony->getQueen().getPosition().y);
	return abs((int)(m_position.x - queenPos.x)) + abs((int)(m_position.y - queenPos.y));
}

void Ant::move(AntMove m)
{
	std::optional<sf::Vector2u> newPos;
	switch (m)
	{
	case AntMove::Up:
		newPos = m_colony->getMap().upOf(m_position);
		if (newPos)
		{
			m_position = newPos.value();
			m_colony->updateAnt(m_index);
		}
		break;
	case AntMove::Right:
		newPos = m_colony->getMap().rightOf(m_position);
		if (newPos)
		{
			m_position = newPos.value();
			m_colony->updateAnt(m_index);
		}
		break;
	case AntMove::Down:
		newPos = m_colony->getMap().downOf(m_position);
		if (newPos)
		{
			m_position = newPos.value();
			m_colony->updateAnt(m_index);
		}
		break;
	case AntMove::Left:
		newPos = m_colony->getMap().leftOf(m_position);
		if (newPos)
		{
			m_position = newPos.value();
			m_colony->updateAnt(m_index);
		}
		break;
	}
}