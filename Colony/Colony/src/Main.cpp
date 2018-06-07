#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>

float zoom;
sf::View camera;
sf::RenderWindow window;

void handleKeys()
{
	//Handle zooming
	float zoomSpeed = 0.0005f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		if (zoom > 0.25f)
		{
			zoom -= zoomSpeed;
			camera.zoom(zoom / (zoom + zoomSpeed));
			window.setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		if (zoom < 1.0f)
		{
			zoom += zoomSpeed;
			camera.zoom(zoom / (zoom - zoomSpeed));
			//Check for camera being out of bounds
			//X-axis
			if (camera.getCenter().x - camera.getSize().x / 2 < 0) camera.move(camera.getSize().x / 2 - camera.getCenter().x, 0);
			else if (camera.getCenter().x + camera.getSize().x / 2 > window.getSize().x) camera.move(window.getSize().x - camera.getSize().x / 2 - camera.getCenter().x, 0);
			//Y-axis
			if (camera.getCenter().y - camera.getSize().y / 2 < 0) camera.move(0, camera.getSize().y / 2 - camera.getCenter().y);
			else if (camera.getCenter().y + camera.getSize().y / 2 > window.getSize().y) camera.move(0, window.getSize().y - camera.getCenter().y - camera.getSize().y / 2);

			window.setView(camera);
		}
	}

	//Handle moving camera
	float moveSpeed = 0.1f;
	//x-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (camera.getCenter().x - camera.getSize().x / 2 > 0)
		{
			camera.move(-moveSpeed, 0);
			window.setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (camera.getCenter().x + camera.getSize().x / 2 < window.getSize().x)
		{
			camera.move(moveSpeed, 0);
			window.setView(camera);
		}
	}
	//y-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (camera.getCenter().y - camera.getSize().y/2 > 0)
		{
			camera.move(0, -moveSpeed);
			window.setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (camera.getCenter().y + camera.getSize().y / 2 < window.getSize().y)
		{
			camera.move(0, moveSpeed);
			window.setView(camera);
		}
	}
	
}

int main()
{
	unsigned short fps = 60;
	
	window.create(sf::VideoMode(640, 400), "Colony");
	//window.setFramerateLimit(fps);

	camera = window.getDefaultView();

	zoom = 1.0f;

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

		if (clock() - time >= CLOCKS_PER_SEC / (float)fps)
		{
			std::cout << "Hi!\n";
			handleKeys();
		}

		window.clear();
		
		window.draw(map);

		window.display();
	}

	return 0;
}

