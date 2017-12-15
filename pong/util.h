#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/system/vector2.hpp>
#include "pong.h"

namespace util 
{
	float random(float, float);
	bool  intersects(sf::CircleShape, sf::RectangleShape);
}
