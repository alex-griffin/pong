#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/system/Vector2.hpp>
#include "pong.h"

class Ball
{
	friend class Game;
	protected:
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::CircleShape shape;
	
	public:
		Ball(int, int, int);

		void update();
		void render();
};

