#include "Racket.h"
#include "GraphicsHelper.h"

const int screenWidth = 600, screenHeight = 400;

Racket::Racket(int x)
{
	score = 0;
	y = 0;
	this->x = x;
	speed = 5;

}

void Racket::Draw()
{
	GraphicsHelper::DrawRect(x, y, width, height);
}

void Racket::MoveUp() {
	if (y - speed < 0) {
		y = 0;
		return;
	}
	y -= speed;
}

void Racket::MoveDown() {
	if (y + speed > screenHeight - this->height) {//300 is screenHeight - racketHeight
		y = screenHeight - this->height;
		return;
	}
	y += speed;
}

void Racket::Reset()
{
	y = 0;
	score = 0;
}

int Racket::GetX()
{
	return x;
}

int Racket::GetY()
{
	return y;
}
