#pragma once
#include "Racket.h"
class Ball
{
public:
	enum class CollisionSide {
		None,
		Right,
		Left
	};

	Ball(Racket *rightRacket,Racket *leftRacket);
	void Draw();
	CollisionSide Move();
	void Reset(float xVel);
private:
	Racket* rightRacket;
	Racket* leftRacket;
	const int width = 10, height = 10;
	float x;
	float y;
	float xVel;
	float yVel;
	double speed;
};

