#include "AntColony.h"

#include <stdlib.h>

#include "SFML/Graphics/RenderTarget.hpp"

unsigned int AntColony::STARTNUM = 25;

AntColony::AntColony(const CellMap* const map, const sf::Color& colonyColour, sf::Vector2u startPoint)
	: m_map(map), m_colonyColour(colonyColour), m_ants(1, Ant(this, startPoint, 0)), m_queen(m_ants[0]), m_points(sf::Quads, 4 * (STARTNUM + 1))
{
	m_ants.reserve(STARTNUM + 1);
	
	m_points[0].position = sf::Vector2f(m_queen.getPosition().x, m_queen.getPosition().y);
	m_points[1].position = sf::Vector2f(m_queen.getPosition().x + 1, m_queen.getPosition().y);
	m_points[2].position = sf::Vector2f(m_queen.getPosition().x + 1, m_queen.getPosition().y + 1);
	m_points[3].position = sf::Vector2f(m_queen.getPosition().x, m_queen.getPosition().y + 1);
	m_points[0].color = colonyColour;
	m_points[1].color = colonyColour;
	m_points[2].color = colonyColour;
	m_points[3].color = colonyColour;
	
	srand(startPoint.x * startPoint.y);

	for (unsigned int i = 1; i < STARTNUM + 1; i++)
	{
		sf::Vector2u workerStart;
		do workerStart = sf::Vector2u(startPoint.x + rand() % (2 * STARTNUM + 1) - STARTNUM, startPoint.y + rand() % (2 * STARTNUM + 1) - STARTNUM);
		while (!map->cellAt(workerStart).isSolid());

		m_ants.emplace_back(this, workerStart, i);
		m_points[4 * i].position = sf::Vector2f(m_ants[i].getPosition().x, m_ants[i].getPosition().y);
		m_points[4 * i + 1].position = sf::Vector2f(m_ants[i].getPosition().x + 1, m_ants[i].getPosition().y);
		m_points[4 * i + 2].position = sf::Vector2f(m_ants[i].getPosition().x + 1, m_ants[i].getPosition().y + 1);
		m_points[4 * i + 3].position = sf::Vector2f(m_ants[i].getPosition().x, m_ants[i].getPosition().y + 1);
		m_points[4 * i].color = colonyColour;
		m_points[4 * i + 1].color = colonyColour;
		m_points[4 * i + 2].color = colonyColour;
		m_points[4 * i + 3].color = colonyColour;
	}
}

const sf::Color& AntColony::getTeamColour() const { return m_colonyColour; }

const Ant& AntColony::getQueen() const { return m_queen; }

const CellMap& AntColony::getMap() const { return *m_map; }

void AntColony::updateAnt(unsigned int index)
{
	const sf::Vector2u& antPos = m_ants[index].getPosition();
	m_points[4 * index].position = sf::Vector2f(antPos.x, antPos.y);
	m_points[4 * index + 1].position = sf::Vector2f(antPos.x + 1, antPos.y);
	m_points[4 * index + 2].position = sf::Vector2f(antPos.x + 1, antPos.y + 1);
	m_points[4 * index + 3].position = sf::Vector2f(antPos.x, antPos.y + 1);
}

void AntColony::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_points, states);
}