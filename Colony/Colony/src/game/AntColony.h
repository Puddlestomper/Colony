#pragma once

#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/VertexArray.hpp"

#include "Ant.h"

class AntColony : public sf::Drawable
{
private:
	const sf::Color m_colonyColour;
	const Ant m_queen;
	std::vector<Ant> m_workers;
	sf::VertexArray m_points;
public:
	static unsigned int STARTNUM;

	AntColony(const sf::Color& colonyColour, sf::Vector2f startPoint);
	const sf::Color& getTeamColour() const;
	const Ant& getQueen() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};