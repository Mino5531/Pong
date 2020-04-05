#pragma once
class Racket
{
public:
	int score;
	const int width = 10, height = 50;

	Racket(int x);
	void Draw();
	void MoveUp();
	void MoveDown();
	void Reset();
	int GetX();
	int GetY();
private:
	int x;
	int y;
	int speed;
};

