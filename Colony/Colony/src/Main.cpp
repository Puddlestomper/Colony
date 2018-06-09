#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"

#include "graphics/Camera.h"

sf::RenderWindow window;
Camera camera;

int main()
{
	std::cout << "Colony Started!\n";
	
	unsigned short fps = 60;
	
	window.create(sf::VideoMode(640, 400), "Colony");
	//window.setFramerateLimit(fps);

	camera = Camera(&window);

	std::string file = "res/maps/pangea.png";
	sf::Texture mapTex;
	if (!mapTex.loadFromFile(file)) std::cout << "Map not loaded!\n";
	else "Map Loaded!\n";

	sf::Sprite map(mapTex);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			}
		}

		//Update ticks
		if (clock.getElapsedTime().asSeconds() >= 1.0f / fps)
		{
			camera.update();
			clock.restart();
		}

		//Render ticks
		window.clear();
		
		window.draw(map);

		window.display();
	}

	return 0;
}

