#include "Window.h"

#include "SFML/Window/Event.hpp"

Window::Window(Frame& frame, sf::String name, unsigned short fps)
	: sf::RenderWindow(sf::VideoMode(frame.getWidth(), frame.getHeight()), name), m_fps(fps), m_camera(this), m_frame(frame)
{
	setFramerateLimit(fps);
	setActive(false);
}

const Frame& Window::getFrame() const { return m_frame; }

void Window::addToDraw(sf::Drawable* drawable, unsigned int order)
{
	if (order >= m_toDraws.size()) m_toDraws.push_back(drawable);	
	else m_toDraws.insert(m_toDraws.begin() + order, drawable);
}

void Window::start()
{
	setActive(true);

	sf::Clock clock;

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
		if (clock.getElapsedTime().asSeconds() >= 1.0f / m_fps)
		{
			m_camera.update();
			clock.restart();
		}

		//Render ticks
		clear();

		draw(m_frame);
		for (sf::Drawable* d : m_toDraws) draw(*d);

		display();
	}
}