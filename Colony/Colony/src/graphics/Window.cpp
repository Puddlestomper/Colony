#include "Window.h"

#include <time.h>

#include "SFML/Window/Event.hpp"

#include "game/Updatable.h"

Window::Window(Frame& frame, sf::String name, unsigned short fps, unsigned short ups)
	: sf::RenderWindow(sf::VideoMode(frame.getWidth(), frame.getHeight()), name), m_fps(fps), m_ups(ups), m_camera(this), m_frame(frame)
{
	setFramerateLimit(fps);
	setActive(false);
}

void Window::addToDraw(sf::Drawable* drawable, unsigned int order)
{
	if (order >= m_toDraw.size()) m_toDraw.push_back(drawable);	
	else m_toDraw.insert(m_toDraw.begin() + order, drawable);
}

void Window::addToUpdate(Updatable* updatable, unsigned int order)
{
	if (order >= m_toUpdate.size()) m_toUpdate.push_back(updatable);
	else m_toUpdate.insert(m_toUpdate.begin() + order, updatable);
}

void Window::start()
{
	setActive(true);

	clock_t time = std::clock();
	unsigned long ticks = 0;

	while (isOpen())
	{
		sf::Event event;
		while (pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				close();
				break;

			}
		}

		//Update ticks
		if (std::clock() - time >= CLOCKS_PER_SEC / m_ups)
		{
			time = std::clock();

			m_camera.update();
			for (Updatable* u : m_toUpdate) u->update(ticks);

			ticks++;
		}

		//Render ticks
		clear();

		draw(m_frame);
		for (sf::Drawable* d : m_toDraw) draw(*d);

		display();
	}
}