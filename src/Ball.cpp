#include "Ball.h"
#include "GraphicsHelper.h"
#include <cstdlib>

const int screenWidth = 600, screenHeight = 400;

Ball::Ball(Racket* rightRacket, Racket* leftRacket)
{
	x = screenWidth/2 - 5;
	y = screenHeight/2 - 5;
	xVel = 2;
	yVel = 0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.7 - 0.7)));
	speed = 0.6;
	this->rightRacket = rightRacket;
	this->leftRacket = leftRacket;
}

void Ball::Draw() {
	GraphicsHelper::DrawRect(x, y, width, height);
}

Ball::CollisionSide Ball::Move() {
	x += xVel * speed;
	y += yVel *speed;
	if (x+10 + xVel * speed > 600) {
		speed = 0;
		return CollisionSide::Right;
	}
	if (x + xVel * speed < 0) {
		speed = 0;
		return CollisionSide::Left;
	}
	if (y >= rightRacket->GetY() && y <= rightRacket->GetY() + rightRacket->height &&
		x + 10 + xVel * speed > rightRacket->GetX()) {
		xVel *= -1;
		speed += 0.1;
		float chval = 0.0f+static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0f - 0.0f)));
		if (chval > 0.25 && chval < 0.5 && yVel < 3 || chval > 0.5 && yVel > 3) {
			yVel -= 0.2;
		}
		if (chval > 0.5 && yVel < 3 || chval > 0.25 && chval < 0.5 && yVel >3) {
			yVel += 0.2;
		}
	}
	if (y >= leftRacket->GetY() && y <= leftRacket->GetY() + leftRacket->height &&
		x + xVel * speed < leftRacket->GetX() +10) {
		xVel *= -1;
		speed += 0.1;
	}
	if (y+10 + yVel * speed > 400 || y + yVel * speed < 0) {
		yVel *= -1;
		speed += 0.1;
	}
	return CollisionSide::None;
}

void Ball::Reset(float xVel)
{
	x = screenWidth / 2 - 5;
	y = screenHeight / 2 - 5;
	this->xVel = xVel;
	yVel = 0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.7 - 0.7)));
	speed = 0.6;
}

