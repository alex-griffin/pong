#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.h"
#include "Ball.h"
#include "util.h"
#include "pong.h"

class Game
{
private:
	Player player1; 
	Player player2; 
	Ball ball;


public:

	Game();
	void render();
	void update();

};

