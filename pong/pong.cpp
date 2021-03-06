// pong.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "pong.h"
#include "Game.h"
#include "Ball.h"
#include "player.h"
#include "util.h"


sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "better than pali's pong");
sf::Font font;

Game game;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	window.setFramerateLimit(360);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();

		if (game.getState() == GAME_STATE_PLAYING) {
			game.update();
		}
		else if(game.getState() == GAME_STATE_START) {
			game.preGame();
			game.startGame();
		}
		else if (game.getState() == GAME_STATE_ENDED) {
			game.endGame();
			game.startGame();

		}


		window.display();

	}

   
}
