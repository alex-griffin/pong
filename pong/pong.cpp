// pong.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "pong.h"
#include "player.h"
#include "util.h"



sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong");

Player player1(10, sf::Keyboard::W, sf::Keyboard::S, sf::Vector2f(10, 80));
Player player2(WINDOW_WIDTH - 20, sf::Keyboard::Up, sf::Keyboard::Down, sf::Vector2f(10, 80));



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

		
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();

			player1.update();
			player2.update();

			util::drawMidLine();


			window.display();
		}

   
}

