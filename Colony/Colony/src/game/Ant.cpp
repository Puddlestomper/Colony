#include "Ant.h"

#include <stdlib.h>
#include <optional>
//#include <iostream>

#include "AntColony.h"
#include "CellMap.h"

Ant::Ant(AntColony* const colony, unsigned int index)
	: m_colony(colony), m_position(colony->getQueen().getPosition()), m_index(index) 
{
	m_colony->getMap()->antIsAt(m_position);
}

Ant::Ant(AntColony* const colony, const sf::Vector2u position, unsigned int index)
	: m_colony(colony), m_position(position), m_index(index)
{
	m_colony->getMap()->antIsAt(m_position);
}

/*
Ant::Ant(const Ant& ant)
	: m_colony(ant.m_colony), m_position(ant.m_position), m_index(ant.m_index)
{
	
}*/

const sf::Vector2u& Ant::getPosition() const { return m_position; }

int Ant::getDistanceFromQueen() const
{
	sf::Vector2u queenPos = sf::Vector2u(m_colony->getQueen().getPosition().x, m_colony->getQueen().getPosition().y);
	return abs((int)(m_position.x - queenPos.x)) + abs((int)(m_position.y - queenPos.y));
}

//Have move check if new cell is occupied

void Ant::move(AntMove m)
{
	std::optional<sf::Vector2u> newPos;
	switch (m)
	{
	case AntMove::Up:
		newPos = m_colony->getMap()->upOf(m_position);
		break;
	case AntMove::Right:
		newPos = m_colony->getMap()->rightOf(m_position);
		break;
	case AntMove::Down:
		newPos = m_colony->getMap()->downOf(m_position);
		break;
	case AntMove::Left:
		newPos = m_colony->getMap()->leftOf(m_position);
		break;
	}

	if (newPos)
	{
		if (m_colony->getMap()->antAt(newPos.value())) return;

		m_colony->getMap()->antNotAt(m_position);
		m_position = newPos.value();
		m_colony->updateAntPosition(m_index);
	}

}

void Ant::update(unsigned long ticks)
{
	if (ticks % 30 == 0)
	{
		srand(ticks * (m_index + 1));
		move((AntMove)(rand() % 4));
	}
}

void Ant::updateColony(AntColony* colony) { m_colony = colony; }