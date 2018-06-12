#include "CellMap.h"

#include <iostream>

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

CellMap::CellMap(const sf::Image& map, bool warp)
	: Frame(map.getSize().x, map.getSize().y), m_mapData(m_width * m_height), m_warp(warp), m_mapTex()
{	
	if(!m_mapTex.loadFromImage(map)) std::cout << "CellMap Texture Load Failed!\n";
	
	const sf::Uint8* pixels = map.getPixelsPtr();
	
	for (unsigned int i = 0; i < 4 * m_width * m_height; i += 4)
	{
		Cell cell = Cell::getCell(sf::Color(pixels[i], pixels[i + 1], pixels[i + 2], pixels[i + 3])); //Get cell from colour
		if (cell == Cell::EMPTY)
		{
			std::cout << "Empty Cell Found At " << i << "!\n";
			std::cout << "RGBA: " << (int)pixels[i] << ", " << (int)pixels[i + 1] << ", " << (int)pixels[i + 2] << ", " << (int)pixels[i + 3] << "\n";
		}
		unsigned char j;
		for (j = 0; j < m_cells.size(); j++) if (cell == m_cells[j]) break; //If cell already found break
		if (j == m_cells.size()) m_cells.push_back(cell); //If loop didn't break add the cell
		m_mapData[i/4] = j; //Add the cell to the mapData
	}
}

const Cell& CellMap::cellAt(const sf::Vector2u& point) const
{
	return m_cells[m_mapData[point.x + point.y * m_width]];
}

const std::optional<sf::Vector2u> CellMap::upOf(const sf::Vector2u& point) const
{
	if (m_warp) return sf::Vector2u(point.x, point.y <= 0 ? m_height - 1 : point.y - 1);
	else if (point.y <= 0) return std::nullopt;
	return sf::Vector2u(point.x, point.y - 1);
}

const std::optional<sf::Vector2u> CellMap::downOf(const sf::Vector2u& point) const
{
	if (m_warp) return sf::Vector2u(point.x, (point.y + 1) % m_height);
	else if (point.y >= m_height - 1) return std::nullopt;
	return sf::Vector2u(point.x, point.y + 1);
}

const std::optional<sf::Vector2u> CellMap::leftOf(const sf::Vector2u& point) const
{
	if (m_warp) return sf::Vector2u(point.x <= 0 ? m_width - 1 : point.x - 1, point.y);
	else if (point.x <= 0) return std::nullopt;
	return sf::Vector2u(point.x - 1, point.y);
}

const std::optional<sf::Vector2u> CellMap::rightOf(const sf::Vector2u& point) const
{
	if (m_warp) return sf::Vector2u((point.x + 1) % m_width, point.y);
	else if (point.x >= m_width - 1) return std::nullopt;
	return sf::Vector2u(point.x + 1, point.y);
}

void CellMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Implement making a vertex array and drawing from that instead of from the texture
	//(so that empty cells are drawn white)
	sf::Sprite sprite(m_mapTex);
	target.draw(sprite, states);
}