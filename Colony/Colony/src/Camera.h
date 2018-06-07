#pragma once

#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Camera
{
private:
	float m_Zoom, m_MoveSpeed, m_ZoomSpeed;
	sf::View camera;
	sf::RenderWindow* window;
public:
	Camera(sf::RenderWindow* window);
	void update();
	void setWindow(sf::RenderWindow* window);
};
