#pragma once

#include "Cell.h"

#include <vector>

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

class CellMap
{
private:
	unsigned short m_width, m_height;
	std::vector<Cell> m_cells;
	std::vector<char> m_mapData;
	sf::Texture m_mapTex;
public:
	CellMap(const sf::Image& map);
	//member functions
};

//One cell will be a one pixel