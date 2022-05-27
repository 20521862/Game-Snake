#pragma once

struct NODE
{
	int x, y;
};
class Snake
{
public:
	NODE A[100];
	int Length, dir, olddir;
	Snake();
	void Draw();
	void Move();
	void RemoveTail();
};



