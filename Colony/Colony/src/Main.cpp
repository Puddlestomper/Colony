#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"

#include "graphics/Window.h"
#include "game/AntColony.h"
#include "CellMap.h"

int main()
{
	std::cout << "Colony Started!\n";
	
	std::string file = "res/maps/pangea.png";
	sf::Image mapImage;
	if (!mapImage.loadFromFile(file)) std::cout << "Map not loaded!\n";
	else "Map Loaded!\n";

	CellMap map(mapImage);

	Window window(map, "Colony");
	
	AntColony colony(sf::Color::Red, sf::Vector2f(380, 170));

	window.addToDraw(&map);
	window.addToDraw(&colony);

	window.start();

	return 0;
}

