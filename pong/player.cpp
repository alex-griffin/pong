#include "stdafx.h"
#include "player.h"


Player::Player(int xPos,
			 				 sf::Keyboard::Key up,
				 			 sf::Keyboard::Key down,
			 				 sf::Vector2f rectSize, 
							 sf::Vector2f tPos)
{
	x = xPos;
	y = WINDOW_HEIGHT / 2;
	
	upKey = up;
	downKey = down;
	
	paddle.setSize(rectSize);
	paddle.setFillColor(sf::Color(255, 255, 255));
	paddle.setPosition(x, y);

	textPos.x = tPos.x;
	textPos.y = tPos.y;
}

void Player::update()
{
	y += sf::Keyboard::isKeyPressed(upKey)   && y > 0                             ? -1 :
		   sf::Keyboard::isKeyPressed(downKey) && y < WINDOW_HEIGHT - PADDLE_HEIGHT ?  1 : 0;
	
	paddle.setPosition(x, y);

}

void Player::render()
{
	window.draw(paddle);

	sf::Text text;
	text.setFont(font);
	text.setString(std::to_string(pts));
	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition(textPos.x - bounds.width / 2, textPos.y);

	
	window.draw(text);


}

