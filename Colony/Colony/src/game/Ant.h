#pragma once

#include "SFML/System/Vector2.hpp"

class AntColony;

class Ant
{
private:
	AntColony* const m_colony;
	sf::Vector2u m_position;
	const unsigned int m_index;
public:
	enum class AntMove
	{
		Up, Right, Down, Left
	};

	Ant(AntColony* const colony, unsigned int index);
	Ant(AntColony* const colony, const sf::Vector2u position, unsigned int index);

	const sf::Vector2u& getPosition() const;
	int getDistanceFromQueen() const;

	void move(AntMove m);
	//void update();
};

//Ants should always have vision of home base

/*Ants will have different actions available to them:
	Move up, down, left or right - Attack by moving into an enemy ant
	moveToQueen: move following the shortest path to get to the queen
	Fortify: Stay and gain defensive bonus
	Build: build stuff
*/