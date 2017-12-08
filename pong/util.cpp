#include "util.h"


void drawMidLine() {
	for (int i = 0; i < WINDOW_HEIGHT / 100; i++) {
		sf::RectangleShape line(sf::Vector2f(100, 5));
		line.setPosition(i * 100, WINDOW_WIDTH / 2);
	}
}