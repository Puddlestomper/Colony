#pragma once

#include <vector>
#include <optional>

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "graphics/Frame.h"
#include "Updatable.h"
#include "Cell.h"
#include "AntColony.h"

class CellMap : public Frame, public Updatable
{
private:
	std::vector<Cell> m_cells;
	std::vector<char> m_mapData;
	bool m_warp;
	sf::Texture m_mapTex;
	std::vector<AntColony> m_colonies;
	std::vector<bool> m_antData; //Stores if a cell is occupied
	//Implement this^
public:
	CellMap(const sf::Image& map, bool warp = false);

	const Cell& cellAt(const sf::Vector2u& point) const;
	const bool& antAt(const const sf::Vector2u& point) const;

	const std::optional<sf::Vector2u> upOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> downOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> leftOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> rightOf(const sf::Vector2u& point) const;

	void addColony(const sf::Color& colonyColour, sf::Vector2u startPoint);
	void update(unsigned long ticks);
	void antIsAt(const sf::Vector2u& point);
	void antNotAt(const sf::Vector2u& point);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};