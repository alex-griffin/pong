#include "stdafx.h"
#include "util.h"


void util::drawMidLine() {
	for (double i = 0.135; i < WINDOW_HEIGHT / 50; i++) {
		sf::RectangleShape line(sf::Vector2f(4, 50));
		line.setPosition(WINDOW_WIDTH / 2 + 2, i * 100);
		window.draw(line);
	}
}