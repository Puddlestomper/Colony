#pragma once

#include "SFML/System/Vector2.hpp"

class AntColony;

class Ant
{
private:
	const AntColony* m_colony;
	sf::Vector2f m_position;
public:
	Ant(const AntColony* colony);
	Ant(const AntColony* colony, const sf::Vector2f position);
	const sf::Vector2f getPosition() const;
	int getDistanceFromQueen() const;
};

//Ants should always have vision of home base

/*Ants will have different actions available to them:
	Move up, down, left or right - Attack by moving into an enemy ant
	moveToQueen: move following the shortest path to get to the queen
	Fortify: Stay and gain defensive bonus
	Build: build stuff
*/