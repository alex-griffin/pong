#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.h"
#include "Ball.h"
#include "util.h"
#include "pong.h"

#define GAME_STATE_PLAYING 0
#define GAME_STATE_START   1
#define GAME_STATE_ENDED   2

#define WIN_PTS 10



class Game
{
private:
	Player player1; 
	Player player2; 
	Ball ball;
	int state;
	std::string winner;		


public:

	Game();
	void render();
	void update();
	void revertBall(sf::Vector2f initVel);
	void endGame();
	void preGame(); 
	void startGame();
	void drawMidLine();
	int getState();
};

