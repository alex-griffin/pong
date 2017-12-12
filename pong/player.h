#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/window/Keyboard.hpp>
#include "pong.h"

#define PADDLE_HEIGHT 80
#define PADDLE_WIDTH  10


class Player
{
friend class Game;

protected:
	int x;
	int y;
	sf::Vector2f textPos;
	int pts;
	sf::Keyboard::Key downKey;
	sf::Keyboard::Key upKey;
	sf::RectangleShape paddle;
	
public:
	Player(int xPos,
				 sf::Keyboard::Key up,
				 sf::Keyboard::Key down,
				 sf::Vector2f rectSize,
				 sf::Vector2f tPos);
	
	void update();
	void render();

};

