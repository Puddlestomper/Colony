#pragma once

#include <vector>
#include <set>

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
	const unsigned int m_index;
	const sf::Color m_colonyColour;
	std::vector<Ant> m_ants;
	std::set<unsigned int> m_antSlots;
	sf::VertexArray m_points;
public:
	static unsigned int STARTNUM;

	AntColony(CellMap* const map, const unsigned int index, const sf::Color& colonyColour, sf::Vector2u startPoint);
	AntColony(const AntColony& colony);
	//~AntColony();

	inline CellMap* const getMap() const { return m_map; };
	inline const unsigned int& getIndex() const { return m_index; }
	inline const sf::Color& getTeamColour() const { return m_colonyColour; }
	inline const Ant& getQueen() const { return m_ants[0]; }
	
	void update(const unsigned long& ticks);
	void updateAntPosition(const unsigned int& index);
	void killAnt(const unsigned int& index);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};