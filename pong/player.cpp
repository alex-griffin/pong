#include "stdafx.h"
#include "player.h"


Player::Player(int xPos,
			 				 sf::Keyboard::Key up,
				 			 sf::Keyboard::Key down,
			 				 sf::Vector2f rectSize)
{
	x = xPos;
	y = WINDOW_HEIGHT / 2;
	
	upKey = up;
	downKey = down;
	
	paddle.setSize(rectSize);
	paddle.setFillColor(sf::Color(255, 255, 255));
	paddle.setPosition(x, y);

}

void Player::update() 
{
	y += sf::Keyboard::isKeyPressed(upKey)   ? -1 :
		   sf::Keyboard::isKeyPressed(downKey) ?  1 : 0;
	render();
	paddle.setPosition(x, y);

}

void Player::render() 
{
	window.draw(paddle);
}

