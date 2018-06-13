#include "Camera.h"

#include "SFML/Window/Keyboard.hpp"

#include "Window.h"

Camera::Camera(Window* const window)
	: m_camera(window->getDefaultView()), m_window(window) {}

void Camera::update()
{	
	//Handle Zooming
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		if (m_zoom >= 0.10f + m_zoomSpeed)
		{
			m_zoom -= m_zoomSpeed;
			m_camera.setSize((int)(m_window->getFrame().getWidth() * m_zoom), (int)(m_window->getFrame().getHeight() * m_zoom));
			m_window->setView(m_camera);
		}
		else if (m_zoom > 0.10f)
		{
			m_zoom = 0.10f;
			m_camera.setSize((int)(m_window->getFrame().getWidth() * m_zoom), (int)(m_window->getFrame().getHeight() * m_zoom));
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		if (m_zoom <= 1.0f - m_zoomSpeed)
		{
			m_zoom += m_zoomSpeed;
			m_camera.setSize((int)(m_window->getFrame().getWidth() * m_zoom), (int)(m_window->getFrame().getHeight() * m_zoom));
			m_window->setView(m_camera);
		}
		else if (m_zoom < 1.0f)
		{
			m_zoom = 1.0f;
			m_camera.setSize((int)(m_window->getFrame().getWidth() * m_zoom), (int)(m_window->getFrame().getHeight() * m_zoom));
			m_window->setView(m_camera);
		}
	}

	//Handle moving camera
	//x-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		float left = m_camera.getCenter().x - m_camera.getSize().x / 2.0f;
		if (left > m_moveSpeed)
		{
			m_camera.setCenter(m_camera.getCenter().x - m_moveSpeed, m_camera.getCenter().y);
			m_window->setView(m_camera);
		}
		else if (left > 0)
		{
			m_camera.setCenter(m_camera.getCenter().x - (int)left, m_camera.getCenter().y);
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		float right = m_camera.getCenter().x + m_camera.getSize().x / 2.0f;
		if (right < m_window->getFrame().getWidth() - m_moveSpeed)
		{
			m_camera.setCenter(m_camera.getCenter().x + m_moveSpeed, m_camera.getCenter().y);
			m_window->setView(m_camera);
		}
		else if (right < m_window->getFrame().getWidth())
		{
			m_camera.setCenter(m_camera.getCenter().x + m_window->getFrame().getWidth() - (int)right, m_camera.getCenter().y);
			m_window->setView(m_camera);
		}
	}
	//y-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float up = m_camera.getCenter().y - m_camera.getSize().y / 2.0f;
		if (up > m_moveSpeed)
		{
			m_camera.setCenter(m_camera.getCenter().x, m_camera.getCenter().y - m_moveSpeed);
			m_window->setView(m_camera);
		}
		else if (up > 0)
		{
			m_camera.setCenter(m_camera.getCenter().x, m_camera.getCenter().y - (int)up);
			m_window->setView(m_camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		float down = m_camera.getCenter().y + m_camera.getSize().y / 2.0f;
		if (down < m_window->getFrame().getHeight() - m_moveSpeed)
		{
			m_camera.setCenter(m_camera.getCenter().x, m_camera.getCenter().y + m_moveSpeed);
			m_window->setView(m_camera);
		}
		else if (down < m_window->getFrame().getHeight())
		{
			m_camera.setCenter(m_camera.getCenter().x, m_camera.getCenter().y + m_window->getFrame().getHeight() - (int)down);
			m_window->setView(m_camera);
		}
	}

	//Check for camera being out of bounds
	//X-axis
	if (m_camera.getCenter().x - m_camera.getSize().x / 2.0f < 0)
	{
		m_camera.move(m_camera.getSize().x / 2.0f - m_camera.getCenter().x, 0);
		m_window->setView(m_camera);
	}	
	else if (m_camera.getCenter().x + m_camera.getSize().x / 2.0f > m_window->getFrame().getWidth())
	{
		m_camera.move(m_window->getFrame().getWidth() - m_camera.getSize().x / 2.0f - m_camera.getCenter().x, 0);
		m_window->setView(m_camera);
	}
	//Y-axis
	if (m_camera.getCenter().y - m_camera.getSize().y / 2.0f < 0)
	{
		m_camera.move(0, m_camera.getSize().y / 2.0f - m_camera.getCenter().y);
		m_window->setView(m_camera);
	}	
	else if (m_camera.getCenter().y + m_camera.getSize().y / 2.0f > m_window->getFrame().getHeight())
	{
		m_camera.move(0, m_window->getFrame().getHeight() - m_camera.getCenter().y - m_camera.getSize().y / 2.0f);
		m_window->setView(m_camera);
	}
}