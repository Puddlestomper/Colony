#include "Camera.h"

#include "SFML/Window/Keyboard.hpp"

Camera::Camera() {}

Camera::Camera(sf::RenderWindow* window)
	: m_camera(window->getDefaultView()), m_window(window) {}

void Camera::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		if (m_Zoom > 0.25f)
		{
			m_Zoom -= m_ZoomSpeed;
			m_camera.zoom(m_Zoom / (m_Zoom + m_ZoomSpeed));
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		if (m_Zoom < 1.0f)
		{
			m_Zoom += m_ZoomSpeed;
			m_camera.zoom(m_Zoom / (m_Zoom - m_ZoomSpeed));
			m_window->setView(m_camera);
		}
	}

	//Handle moving camera
	//x-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_camera.getCenter().x - m_camera.getSize().x / 2 > 0)
		{
			m_camera.move(-m_MoveSpeed, 0);
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_camera.getCenter().x + m_camera.getSize().x / 2 < m_window->getSize().x)
		{
			m_camera.move(m_MoveSpeed, 0);
			m_window->setView(m_camera);
		}
	}
	//y-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_camera.getCenter().y - m_camera.getSize().y / 2 > 0)
		{
			m_camera.move(0, -m_MoveSpeed);
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_camera.getCenter().y + m_camera.getSize().y / 2 < m_window->getSize().y)
		{
			m_camera.move(0, m_MoveSpeed);
			m_window->setView(m_camera);
		}
	}

	//Check for camera being out of bounds
	//X-axis
	if (m_camera.getCenter().x - m_camera.getSize().x / 2 < 0) m_camera.move(m_camera.getSize().x / 2 - m_camera.getCenter().x, 0);
	else if (m_camera.getCenter().x + m_camera.getSize().x / 2 > m_window->getSize().x) 
		m_camera.move(m_window->getSize().x - m_camera.getSize().x / 2 - m_camera.getCenter().x, 0);
	//Y-axis
	if (m_camera.getCenter().y - m_camera.getSize().y / 2 < 0) m_camera.move(0, m_camera.getSize().y / 2 - m_camera.getCenter().y);
	else if (m_camera.getCenter().y + m_camera.getSize().y / 2 > m_window->getSize().y)
		m_camera.move(0, m_window->getSize().y - m_camera.getCenter().y - m_camera.getSize().y / 2);
}

void Camera::setWindow(sf::RenderWindow* window)
{
	this->m_window = window;
	m_camera = window->getDefaultView();
	m_Zoom = 1.0f;
}