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

void Food::Random(Zone zone)
{
	srand(time(NULL));
	x = RandomInt(zone.left + 1, zone.right - 1);
	y = RandomInt(zone.top + 1, zone.bottom - 1);
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
