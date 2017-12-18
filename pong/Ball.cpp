#include "stdafx.h"
#include "Ball.h"
#include "util.h"




Ball::Ball(int x, int y, int r) :
	pos(x, y),
	vel(0, 0),
	shape(r)
{
	shape.setOrigin(r, r);

}

void Ball::render() {
	window.draw(shape);
}


void Ball::update() {
	if (pos.y + shape.getRadius() > WINDOW_HEIGHT) {
		vel.y = util::random(MIN_DIFFICULTY, MAX_DIFFICULTY) * -abs(vel.y);
	}
	else if (pos.y - shape.getRadius() < 0) {
		vel.y = util::random(MIN_DIFFICULTY, MAX_DIFFICULTY) * abs(vel.y);
	}
	shape.setPosition(pos);

	pos += vel;
}