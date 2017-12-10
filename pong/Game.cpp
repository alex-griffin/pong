#include "stdafx.h"
#include "Game.h"


Game::Game() : 
	player1(10,                sf::Keyboard::W,  sf::Keyboard::S,    sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT), sf::Vector2f(200, 10)),
  player2(WINDOW_WIDTH - 20, sf::Keyboard::Up, sf::Keyboard::Down, sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT), sf::Vector2f(600, 10)),
	ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10)

{
	if (!font.loadFromFile("RobotoMono.ttf")) {
		// TODO: make an error thingy
	}
	ball.setVel(sf::Vector2f(1, 1));
	srand(time(NULL));

}


void Game::render() {
	window.clear();
	util::drawMidLine();
	player1.update();
	player2.update();
	ball.update();
}

void Game::update() {
	if (ball.pos.x) {

	}
}