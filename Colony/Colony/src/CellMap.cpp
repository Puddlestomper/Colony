#include "CellMap.h"

#include <iostream>

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

CellMap::CellMap(const sf::Image& map)
	: Frame(map.getSize().x, map.getSize().y), m_cells(1), m_mapData(m_width * m_height), m_mapTex()
{	
	if(!m_mapTex.loadFromImage(map)) std::cout << "CellMap Texture Load Failed!\n";
	
	const sf::Uint8* pixels = map.getPixelsPtr();
	
	for (unsigned int i = 0; i < 4 * m_width * m_height; i += 4)
	{
		Cell cell = Cell::getCell(sf::Color(pixels[i], pixels[i + 1], pixels[i + 2], pixels[i + 3])); //Get cell from colour
		
		unsigned char j;
		for (j = 0; j < m_cells.size(); j++) if (cell == m_cells[j]) break; //If cell already found break
		if (j == m_cells.size()) m_cells.push_back(cell); //If loop didn't break add the cell
		m_mapData.push_back(j); //Add the cell to the mapData
	}
}

void CellMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(m_mapTex);
	target.draw(sprite, states);
}