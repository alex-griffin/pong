#include "stdafx.h"
#include "Ball.h"
#include "util.h"

#define MIN_DIFFICULTY 1.001
#define MAX_DIFFICULTY 1.01


Ball::Ball(int x, int y, int r) :
	pos(x, y),
	vel(0, 0),
	shape(r)
{
}

void Ball::render() {
	window.draw(shape);
}


void Ball::update() {
	if (pos.y > WINDOW_HEIGHT) {
		vel.y = util::random(MIN_DIFFICULTY, MAX_DIFFICULTY) * -abs(vel.y);
	}
	else if (pos.y < 0) {
		vel.y = util::random(MIN_DIFFICULTY, MAX_DIFFICULTY) * abs(vel.y);
	}
	shape.setPosition(pos);

	pos += vel;
}