#include "stdafx.h"
#include "util.h"
#include <cmath>


float util::random(float min, float max) {
	return ((float)rand()) / (float)RAND_MAX * (max - min) + min;
}

bool util::intersects(sf::CircleShape circle, sf::RectangleShape rect)
{

	if ((circle.getPosition().y > rect.getPosition().y && 
			 circle.getPosition().y < rect.getPosition().y + rect.getSize().y) && 
		 ((circle.getPosition().x + circle.getRadius() < rect.getPosition().x &&
			 circle.getPosition().x - circle.getRadius() > rect.getPosition().x + rect.getSize().x) ||
			(circle.getPosition().x + circle.getRadius() > rect.getPosition().x &&
			 circle.getPosition().x - circle.getRadius() < rect.getPosition().x + rect.getSize().x)))
	{
		return true;
	}

	return false;

}