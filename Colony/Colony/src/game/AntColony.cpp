#include "AntColony.h"

#include <stdlib.h>

#include "SFML/Graphics/RenderTarget.hpp"

unsigned int AntColony::STARTNUM = 25;

AntColony::AntColony(const sf::Color& colonyColour, sf::Vector2f startPoint)
	: m_colonyColour(colonyColour), m_queen(this, startPoint), m_points(sf::Points, STARTNUM + 1)
{
	m_workers.reserve(STARTNUM);
	
	m_points[0].position = m_queen.getPosition();
	m_points[0].color = colonyColour;
	
	srand(startPoint.x * startPoint.y);

	for (unsigned int i = 0; i < STARTNUM; i++)
	{
		sf::Vector2f workerStart(startPoint.x + rand() % (2 * STARTNUM + 1) - STARTNUM, startPoint.y + rand() % (2 * STARTNUM + 1) - STARTNUM);
		m_workers.emplace_back(this, workerStart);
		m_points[i + 1].position = m_workers[i].getPosition();
		m_points[i + 1].color = colonyColour;
	}
}

const sf::Color& AntColony::getTeamColour() const { return m_colonyColour; }

const Ant& AntColony::getQueen() const { return m_queen; }

void AntColony::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_points, states);
}