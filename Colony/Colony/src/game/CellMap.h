#pragma once

#include <vector>

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "graphics/Frame.h"
#include "game/Cell.h"

class CellMap : public Frame
{
private:
	std::vector<Cell> m_cells;
	std::vector<char> m_mapData;
	sf::Texture m_mapTex;
public:
	CellMap(const sf::Image& map);
	const Cell& cellAt(sf::Vector2u point) const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};