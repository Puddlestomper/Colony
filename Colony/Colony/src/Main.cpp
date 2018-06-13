#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"

#include "graphics/Window.h"
#include "game/AntColony.h"
#include "game/CellMap.h"

int main()
{
	std::cout << "Colony Started!\n";
	
	std::string file = "res/maps/pangea.png";
	sf::Image mapImage;
	if (!mapImage.loadFromFile(file)) std::cout << "Map not loaded!\n";
	else "Map Loaded!\n";

	CellMap map(mapImage, true);

	Window window(map, "Colony");
	window.addToUpdate(&map);

	map.addColony(sf::Color::Red, sf::Vector2u(380, 170));
	map.addColony(sf::Color::Magenta, sf::Vector2u(394, 264));
	map.addColony(sf::Color::Cyan, sf::Vector2u(135, 145));

	window.start();

	return 0;
}

