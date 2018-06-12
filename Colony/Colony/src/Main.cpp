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
	
	AntColony redColony(&map, sf::Color::Red, sf::Vector2u(380, 170));
	AntColony magColony(&map, sf::Color::Magenta, sf::Vector2u(394, 264));
	AntColony cyaColony(&map, sf::Color::Cyan, sf::Vector2u(135, 145));
	
	window.addToDraw(&redColony);
	window.addToDraw(&magColony);
	window.addToDraw(&cyaColony);

	window.start();

	return 0;
}

