#pragma once
#include "Zone.h"
class Food
{
public:
	int x, y;
	Food Random(Zone zone);
	void Draw();
	void Erase();
};


