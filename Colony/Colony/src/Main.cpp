#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "Camera.h"

sf::RenderWindow window;
Camera camera;

int main()
{
	unsigned short fps = 60;
	
	window.create(sf::VideoMode(640, 400), "Colony");
	//window.setFramerateLimit(fps);

	camera = Camera(&window);

	std::string file = "res/maps/pangea.png";
	sf::Texture mapTex;
	if (!mapTex.loadFromFile(file))
	{
		std::cout << "Map not loaded!\n";
	}

	sf::Sprite map(mapTex);

	auto time = clock();

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
		if (clock() - time >= CLOCKS_PER_SEC / (float)fps)
		{
			camera.update();
		}

		//Render ticks
		window.clear();
		
		window.draw(map);

		window.display();
	}

	return 0;
}

