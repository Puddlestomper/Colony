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
	const CellMap* const m_map;
	const sf::Color m_colonyColour;
	std::vector<Ant> m_ants;
	const Ant& m_queen;
	sf::VertexArray m_points;
public:
	static unsigned int STARTNUM;

	AntColony(const CellMap* const map, const sf::Color& colonyColour, sf::Vector2u startPoint);

	const sf::Color& getTeamColour() const;
	const Ant& getQueen() const;
	const CellMap& getMap() const;

	//void update();
	void updateAnt(unsigned int index);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};