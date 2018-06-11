#pragma once

#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"

#include "Camera.h"
#include "Frame.h"

class Window : public sf::RenderWindow
{
private:
	unsigned short m_fps;
	Camera m_camera;
	Frame m_frame;
	std::vector<sf::Drawable*> m_toDraws;
public:
	Window(Frame frame, sf::String name, unsigned short fps = 60);
	const Frame& getFrame() const;
	void addToDraw(sf::Drawable* drawable, unsigned int order = UINT_MAX); //Only specify order if you want to have it run nth
	void start();
};