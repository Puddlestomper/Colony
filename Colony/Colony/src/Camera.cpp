#include "Camera.h"

#include "SFML/Window/Keyboard.hpp"

Camera::Camera(sf::RenderWindow* window)
	: m_Zoom(1.0f), m_MoveSpeed(0.1f), m_ZoomSpeed(0.0005f), camera(window->getDefaultView()), window(window)
{

}

void Camera::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		if (m_Zoom > 0.25f)
		{
			m_Zoom -= m_ZoomSpeed;
			camera.zoom(m_Zoom / (m_Zoom + m_ZoomSpeed));
			window->setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		if (m_Zoom < 1.0f)
		{
			m_Zoom += m_ZoomSpeed;
			camera.zoom(m_Zoom / (m_Zoom - m_ZoomSpeed));
			//Check for camera being out of bounds
			//X-axis
			if (camera.getCenter().x - camera.getSize().x / 2 < 0) camera.move(camera.getSize().x / 2 - camera.getCenter().x, 0);
			else if (camera.getCenter().x + camera.getSize().x / 2 > window->getSize().x) camera.move(window->getSize().x - camera.getSize().x / 2 - camera.getCenter().x, 0);
			//Y-axis
			if (camera.getCenter().y - camera.getSize().y / 2 < 0) camera.move(0, camera.getSize().y / 2 - camera.getCenter().y);
			else if (camera.getCenter().y + camera.getSize().y / 2 > window->getSize().y) camera.move(0, window->getSize().y - camera.getCenter().y - camera.getSize().y / 2);

			window->setView(camera);
		}
	}

	//Handle moving camera
	//x-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (camera.getCenter().x - camera.getSize().x / 2 > 0)
		{
			camera.move(-m_MoveSpeed, 0);
			window->setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (camera.getCenter().x + camera.getSize().x / 2 < window->getSize().x)
		{
			camera.move(m_MoveSpeed, 0);
			window->setView(camera);
		}
	}
	//y-axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (camera.getCenter().y - camera.getSize().y / 2 > 0)
		{
			camera.move(0, -m_MoveSpeed);
			window->setView(camera);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (camera.getCenter().y + camera.getSize().y / 2 < window->getSize().y)
		{
			camera.move(0, m_MoveSpeed);
			window->setView(camera);
		}
	}
}

void Camera::setWindow(sf::RenderWindow* window)
{
	this->window = window;
	camera = window->getDefaultView();
	m_Zoom = 1.0f;
}