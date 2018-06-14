#pragma once

#include "SFML/Graphics/View.hpp"

class Window;

class Camera
{
private:
	float m_zoom = 1.0f, m_moveSpeed = 1.0f, m_zoomSpeed = 0.01f;
	sf::View m_camera;
	Window* const m_window;
public:
	Camera(Window* const window);

	void update();
};
