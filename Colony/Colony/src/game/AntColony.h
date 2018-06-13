#pragma once

#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/VertexArray.hpp"

#include "Updatable.h"
#include "Ant.h"

class CellMap;

class AntColony : public sf::Drawable, public Updatable
{
private:
	CellMap* const m_map;
	const sf::Color m_colonyColour;
	std::vector<Ant> m_ants;
	const Ant* m_queen;
	sf::VertexArray m_points;
public:
	static unsigned int STARTNUM;

	AntColony(CellMap* const map, const sf::Color& colonyColour, sf::Vector2u startPoint);
	AntColony(const AntColony& colony);
	~AntColony();


	const sf::Color& getTeamColour() const;
	const Ant& getQueen() const;
	CellMap* const getMap() const;

	void update(unsigned long ticks);
	void updateAntPosition(unsigned int index);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};