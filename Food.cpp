#include "Food.h"
#include <chrono>
#include <iostream>
#include "Zone.h"
#include "Func.h"
int RandomInt(int min, int max)
{
	srand(time(NULL));
	int n = rand() % (max - min + 1) + min;
	return n;
}

Food Food::Random(Zone zone)
{
	srand(time(NULL));
	Food food;
	food.x = RandomInt(zone.left + 1, zone.right - 1);
	food.y = RandomInt(zone.top + 1, zone.bottom - 1);
	return food;
}

void Food::Draw()
{
	Func::gotoxy(x, y);
	std::cout << "X"; // hinh dang thuc an
}

void Food::Erase()
{
	Func::gotoxy(this->x, this->y);
	std::cout << " ";
}
