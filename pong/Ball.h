#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/system/Vector2.hpp>
#include "pong.h"

#define MIN_DIFFICULTY 1.01
#define MAX_DIFFICULTY 1.1

class Ball
{
	friend class Game;
	protected:
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::CircleShape shape;
	
	public:
		Ball(int, int, int);

		bool update();
		void render();
};

