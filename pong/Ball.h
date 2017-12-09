#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/system/Vector2.hpp>
#include "pong.h"

class Ball
{

private: 
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::CircleShape shape;
	
public:
	Ball(int, int, int);

	void setVel(sf::Vector2f);

	void update();
	void render();
};

