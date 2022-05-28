#include "Snake.h"
#include <iostream>
#include "Func.h"
#include <conio.h>

Snake::Snake()
{
	dir = 0;
	olddir = 0;
	Length = 4;
	A[0].x = 11;
	A[0].y = 10;
	A[1].x = 10;
	A[1].y = 10;
	A[2].x = 9;
	A[2].y = 10;
	A[3].x = 8;
	A[3].y = 10;
}

void Snake::Draw()
{
	
	for (int i = 0; i < Length; i++)
	{
		Func::gotoxy(A[i].x, A[i].y);
		if (i == 0)
		{
			std::cout << "O"; // hinh dang dau con ran
		}
		else
		{
			std::cout << "o"; // hinh dang than con ran
		}
	}
}

void DrawPause()
{
	Func::gotoxy(40, 15);
	std::cout << "Press SPACE to pause . . . . .";
}

void Snake::Move()
{
	RemoveTail();
	if (_kbhit())
	{
		olddir = dir;
		char c = _getch();
		if (c == 'd') // sang phai
			dir = 0;
		else if (c == 's') // di xuong
			dir = 1;
		else if (c == 'a') // sang trai
			dir = 2;
		else if (c == 'w') // di len
			dir = 3;
		else if (c == ' ')
		{
			Func::gotoxy(40, 15);
			system("pause");
			DrawPause();
		}
	}
	for (int i = Length; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	switch (dir)
	{
	case 0:
		if (olddir == 2) // Trước đó đang sang trái mà nhấn sang phải
		{
			A[0].x = A[0].x - 1;
			dir = olddir;
			break;
		}
		A[0].x = A[0].x + 1;
		break;
	case 1:
		if (olddir == 3) // Trước đó đang đi xuống mà nhấn đi lên
		{
			A[0].y = A[0].y - 1;
			dir = olddir;
			break;
		}
		A[0].y = A[0].y + 1;
		break;
	case 2:
		if (olddir == 0) // Trước đó đang sang phải mà nhấn sang trái
		{
			A[0].x = A[0].x + 1;
			dir = olddir;
			break;
		}
		A[0].x = A[0].x - 1;
		break;
	case 3:
		if (olddir == 1) // Trước đó đang đi lên mà nhấn đi xuống
		{
			A[0].y = A[0].y + 1;
			dir = olddir;
			break;
		}
		A[0].y = A[0].y - 1;
		break;
	}
}

void Snake::RemoveTail()
{
	Func::gotoxy(A[Length - 1].x, A[Length - 1].y); // xóa đuôi
	std::cout << " ";
}
