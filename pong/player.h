#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "pong.h"


class Player
{
private:
	int x;
	int y;
	int pts;
	sf::Keyboard::Key downKey;
	sf::Keyboard::Key upKey;
	sf::RectangleShape paddle;
	
public:
	Player(int xPos,
				 sf::Keyboard::Key up,
				 sf::Keyboard::Key down,
				 sf::Vector2f rectSize);
	
	void update();
	void render();

};

