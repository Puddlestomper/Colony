#include "AntColony.h"

#include <stdlib.h>
#include <iostream>

#include "SFML/Graphics/RenderTarget.hpp"

#include "CellMap.h"

unsigned int AntColony::STARTNUM = 15;

//Make a Copy Constructor to fix ant pointers automagically

AntColony::AntColony(CellMap* const map, const unsigned int index, const sf::Color& colonyColour, sf::Vector2u startPoint)
	: m_map(map), m_index(index), m_colonyColour(colonyColour), m_ants(1, Ant(this, startPoint, 0)), m_points(sf::Quads, 4 * (STARTNUM + 1))
{
	m_ants.reserve(STARTNUM + 1);

	m_points[0].position = sf::Vector2f(m_ants[0].getPosition().x, m_ants[0].getPosition().y);
	m_points[1].position = sf::Vector2f(m_ants[0].getPosition().x + 1, m_ants[0].getPosition().y);
	m_points[2].position = sf::Vector2f(m_ants[0].getPosition().x + 1, m_ants[0].getPosition().y + 1);
	m_points[3].position = sf::Vector2f(m_ants[0].getPosition().x, m_ants[0].getPosition().y + 1);
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

AntColony::AntColony(const AntColony& colony)
	: m_map(colony.m_map), m_index(colony.m_index), m_colonyColour(colony.m_colonyColour), m_ants(colony.m_ants), m_points(colony.m_points)
{
	for (Ant& a : m_ants) a.updateColony(this);
}

//AntColony::~AntColony() {}

void AntColony::update(const unsigned long& ticks)
{
	for (int i = 1; i < m_ants.size(); i++) m_ants[i].update(ticks);
	if (ticks % 60 == 0)
	{
		sf::Vector2u antPos = m_ants[0].getPosition();
		if (m_antSlots.size() == 0)
		{
			m_ants.emplace_back(this, antPos, m_ants.size());
			m_points.append(sf::Vertex(sf::Vector2f(antPos.x, antPos.y), m_colonyColour));
			m_points.append(sf::Vertex(sf::Vector2f(antPos.x + 1, antPos.y), m_colonyColour));
			m_points.append(sf::Vertex(sf::Vector2f(antPos.x + 1, antPos.y + 1), m_colonyColour));
			m_points.append(sf::Vertex(sf::Vector2f(antPos.x, antPos.y + 1), m_colonyColour));
		}
		else
		{
			const unsigned int& index = *m_antSlots.begin();
			m_ants[index].setPosition(antPos);
			m_points[4 * index].color = m_colonyColour;
			m_points[4 * index + 1].color = m_colonyColour;
			m_points[4 * index + 2].color = m_colonyColour;
			m_points[4 * index + 3].color = m_colonyColour;
			m_antSlots.erase(m_antSlots.begin());
		}

		//std::cout << "Ant Made!\n";
	}
}

void AntColony::updateAntPosition(const unsigned int& index)
{
	const sf::Vector2u& antPos = m_ants[index].getPosition();
	m_points[4 * index].position = sf::Vector2f(antPos.x, antPos.y);
	m_points[4 * index + 1].position = sf::Vector2f(antPos.x + 1, antPos.y);
	m_points[4 * index + 2].position = sf::Vector2f(antPos.x + 1, antPos.y + 1);
	m_points[4 * index + 3].position = sf::Vector2f(antPos.x, antPos.y + 1);
}

void AntColony::killAnt(const unsigned int& index)
{
	m_map->antNotAt(m_ants[index].getPosition());
	m_points[4 * index].color = sf::Color::Transparent;
	m_points[4 * index + 1].color = sf::Color::Transparent;
	m_points[4 * index + 2].color = sf::Color::Transparent;
	m_points[4 * index + 3].color = sf::Color::Transparent;
	
	m_antSlots.emplace(index);
}

void AntColony::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_points, states);
}