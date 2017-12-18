#include "stdafx.h"
#include "Game.h"
#include <iostream>

Game::Game() : 
player1(10,                sf::Keyboard::W,  sf::Keyboard::S,    sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT), sf::Vector2f(200, 10)),
player2(WINDOW_WIDTH - 20, sf::Keyboard::Up, sf::Keyboard::Down, sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT), sf::Vector2f(600, 10)),
ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10),
state(GAME_STATE_START)
{
	if (!font.loadFromFile("RobotoMono.ttf")) 
	{
		// TODO: make an error thingy
	}
	ball.vel = sf::Vector2f(1, 1);
	srand(time(NULL));

}

void Game::drawMidLine() {
	for (double i = 0.135; i < WINDOW_HEIGHT / 50; i++) {
		sf::RectangleShape line(sf::Vector2f(4, 50));
		line.setPosition(WINDOW_WIDTH / 2 + 2, i * 100);
		line.setFillColor(sf::Color::White);
		window.draw(line);
	}
}

void Game::render() 
{
	player1.render();
	player2.render();
	ball.render();
	drawMidLine();
}

void Game::revertBall(sf::Vector2f initVel) 
{
	ball.pos.x = WINDOW_WIDTH / 2;
	ball.pos.y = WINDOW_HEIGHT / 2;

	ball.vel = initVel;
}

void Game::endGame()
{
	sf::RectangleShape win(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	
	win.setPosition(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4);
	win.setOutlineThickness(5);
	win.setFillColor(sf::Color::Black);
	
	sf::Text txt;
	txt.setFont(font);
	txt.setString(winner + " Wins!");
	sf::FloatRect boundstxt = txt.getLocalBounds();
	txt.setPosition(WINDOW_WIDTH / 2 - boundstxt.width / 2, WINDOW_HEIGHT / 2 - boundstxt.height / 2);
	
	sf::Text spa;
	spa.setFont(font);
	spa.setString("[space] to restart");
	sf::FloatRect boundsspa = spa.getLocalBounds();
	spa.setPosition(WINDOW_WIDTH / 2 - boundsspa.width / 2, WINDOW_HEIGHT / 2 + boundsspa.height / 2 + boundstxt.height);

	render();
	window.draw(win);	
	window.draw(txt);
	window.draw(spa);

}

void Game::preGame() 
{
	sf::RectangleShape win(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

	win.setPosition(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4);
	win.setOutlineThickness(5);
	win.setFillColor(sf::Color::Black);

	sf::Text txt;
	txt.setFont(font);
	txt.setString("Press [space] to start");
	sf::FloatRect bounds = txt.getLocalBounds();
	txt.setPosition(WINDOW_WIDTH / 2 - bounds.width / 2, WINDOW_HEIGHT / 2 - bounds.height / 2);

	render();
	window.draw(win);
	window.draw(txt);
}

void Game::startGame() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		state = GAME_STATE_PLAYING;
		revertBall(sf::Vector2f(1, util::random(-1, 1)));
		player1.pts = 0;
		player2.pts = 0;
		player1.pos = player1.defaultPos;
		player2.pos = player2.defaultPos;

	}
}

int Game::getState() {
	return state;
}
	
void Game::update() {

	if (ball.pos.x > WINDOW_WIDTH) 
	{
		player1.pts++;
		if (player1.pts >= WIN_PTS) 
		{
			winner = "Player 1";
			state = GAME_STATE_ENDED;
		}
		else 
		{
			revertBall(sf::Vector2f(-1, util::random(-1, 1)));
		}
	} 
	else if (ball.pos.x < 0) 
	{
		player2.pts++;
		if (player2.pts >= WIN_PTS)
		{
			winner = "Player 2";
			state = GAME_STATE_ENDED;
		}
		else
		{
			revertBall(sf::Vector2f(1, util::random(-1, 1)));
		}
	}

	if (util::intersects(ball.shape, player1.paddle)) {
		ball.vel = sf::Vector2f( abs(ball.vel.x), util::random(ball.vel.y - 0.2, ball.vel.y + 0.2));
	}
	if (util::intersects(ball.shape, player2.paddle)) {
		ball.vel = sf::Vector2f(-abs(ball.vel.x), util::random(ball.vel.y - 0.2, ball.vel.y + 0.2));
	}

	render();

	player1.update();
	player2.update();
	ball.update();

}