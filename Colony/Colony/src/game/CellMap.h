#pragma once

#include <vector>
#include <optional>

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "graphics/Frame.h"
#include "game/Cell.h"

class CellMap : public Frame
{
private:
	std::vector<Cell> m_cells;
	std::vector<char> m_mapData;
	bool m_warp;
	sf::Texture m_mapTex;
public:
	CellMap(const sf::Image& map, bool warp = false);
	const Cell& cellAt(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> upOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> downOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> leftOf(const sf::Vector2u& point) const;
	const std::optional<sf::Vector2u> rightOf(const sf::Vector2u& point) const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};