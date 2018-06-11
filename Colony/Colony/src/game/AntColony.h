#pragma once

#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/VertexArray.hpp"

#include "Ant.h"
#include "CellMap.h"

class AntColony : public sf::Drawable
{
private:
	const CellMap* m_map;
	const sf::Color m_colonyColour;
	const Ant m_queen;
	std::vector<Ant> m_workers;
	sf::VertexArray m_points;
public:
	static unsigned int STARTNUM;

	AntColony(const CellMap* map, const sf::Color& colonyColour, sf::Vector2u startPoint);
	const sf::Color& getTeamColour() const;
	const Ant& getQueen() const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};