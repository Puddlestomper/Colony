#pragma once

#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Camera
{
private:
	float m_Zoom = 1.0f, m_MoveSpeed = 3.0f, m_ZoomSpeed = 0.01f;
	sf::View m_camera;
	sf::RenderWindow* m_window;
public:
	Camera();
	Camera(sf::RenderWindow* window);
	void update();
	void setWindow(sf::RenderWindow* window);
};
