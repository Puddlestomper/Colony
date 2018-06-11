#pragma once

#include "SFML/Graphics/View.hpp"

class Window;

class Camera
{
private:
	float m_zoom = 1.0f, m_moveSpeed = 3.0f, m_zoomSpeed = 0.01f;
	sf::View m_camera;
	Window* m_window;
public:
	Camera(Window* window);
	void update();
};
