#include "stdafx.h"
#include "util.h"
#include <cmath>


float util::random(float min, float max) {
	return ((float)rand()) / (float)RAND_MAX * (max - min) + min;
}

bool util::intersects(sf::CircleShape circle, sf::RectangleShape rect)
{
	/*sf::Vector2f circleDistance(abs(circle.getPosition().x - rect.getPosition().x),
															abs(circle.getPosition().y - rect.getPosition().y));

	if (circleDistance.x > (rect.getSize().x / 2 + circle.getRadius())) { return false; }
	if (circleDistance.y > (rect.getSize().y / 2 + circle.getRadius())) { return false; }

	if (circleDistance.x <= (rect.getSize().x / 2)) { return true; }
	if (circleDistance.y <= (rect.getSize().y / 2)) { return true; }

	float cornerDistance_sq = ((circleDistance.x - rect.getSize().x / 2) * (circleDistance.x - rect.getSize().x / 2)) +
		(circleDistance.y - rect.getSize().y / 2) * (circleDistance.y - rect.getSize().y / 2);

	return (cornerDistance_sq <= (circle.getRadius() * circle.getRadius()));*/


	if (rect.getPoint()) {

	}
}