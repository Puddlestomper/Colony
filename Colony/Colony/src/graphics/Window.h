#pragma once

#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"

#include "Camera.h"
#include "Frame.h"

class Updatable;

class Window : public sf::RenderWindow
{
private:
	unsigned short m_fps, m_ups;
	Camera m_camera;
	const Frame& m_frame;
	std::vector<sf::Drawable*> m_toDraw;
	std::vector<Updatable*> m_toUpdate;
public:
	Window(Frame& frame, sf::String name, unsigned short fps = 60, unsigned short ups = 60);
	const Frame& getFrame() const;
	
	void addToDraw(sf::Drawable* drawable, unsigned int order = UINT_MAX); //Only specify order if you want to have it run nth
	void addToUpdate(Updatable* updatable, unsigned int order = UINT_MAX); //Here too
	void start();
};