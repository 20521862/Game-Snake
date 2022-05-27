#include "Zone.h"
#include <iostream>
#include "Func.h"
Zone::Zone()
{
	top = 5;
	left = 5;
	right = 35;
	bottom = 25;
}

void Zone::Draw()
{
	Func::gotoxy(left, top);
	for (int i = left; i < right; i++)
	{
		cout << "#";
	}

	for (int i = top; i < bottom; i++)
	{
		Func::gotoxy(left, i);
		cout << "#";
	}

	Func::gotoxy(left, bottom);
	for (int i = left; i < right; i++)
	{
		cout << "#";
	}

	for (int i = top; i < bottom + 1; i++)
	{
		Func::gotoxy(right, i);
		cout << "#";
	}
}

void Zone::Erase()
{
	Func::gotoxy(left, top);
	for (int i = left; i < right; i++)
	{
		cout << " ";
	}

	for (int i = top; i < bottom; i++)
	{
		Func::gotoxy(left, i);
		cout << " ";
	}

	Func::gotoxy(left, bottom);
	for (int i = left; i < right; i++)
	{
		cout << " ";
	}

	for (int i = top; i < bottom + 1; i++)
	{
		Func::gotoxy(right, i);
		cout << " ";
	}
}
