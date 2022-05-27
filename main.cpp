#include <iostream>
#include <thread>
#include <windows.h>
#include "Snake.h"
#include "Zone.h"
#include "Func.h"
#include "Food.h"

using namespace std;

int Score = 0;
int Speed = 180;
int Time = 0;
int Time2 = 20;
int MODE = 1;

void SetMode()
{
	cout << "\tSelect game mode:\n";
	cout << "\t1. Easy\n";
	cout << "\t2. Medium\n";
	cout << "\t3. Hard\n";
	int n;
	do
	{
		cout << "Please choice 1, 2 or 3: ";
		cin >> n;
	} while (n < 1 || n > 3);
	MODE = n;
	system("cls");
}

void SetSpeed()
{
	cout << "\tSelect game speed:\n";
	cout << "\t1. Slow\n";
	cout << "\t2. Normal\n";
	cout << "\t3. Fast\n";
	int n;
	do
	{
		cout << "Please choice 1, 2 or 3: ";
		cin >> n;
	} while (n < 1 || n > 3);
	if (n == 1)
	{
		Speed = 230;
	}
	else if (n == 3)
	{
		Speed = 130;
	}
	system("cls");
}

void ThreadTime()
{
	while (true)
	{
		Sleep(1000);
		Time++;
	}
}

void DrawScore()
{
	Func::gotoxy(40, 5);
	cout << "SCORE: " << Score;
}

void DrawTime()
{
	Func::gotoxy(40, 10);
	cout << "TIME: " << Time;
}

bool CheckLose(Snake &snake, Zone zone)
{
	for (int i = 1; i < snake.Length; i++)
	{
		if (snake.A[0].x == snake.A[i].x && snake.A[0].y == snake.A[i].y) // Nếu đầu rắn ăn thân
		{
			return false;
		}
	}
	if (MODE == 2 || MODE == 3)
	{
		if (snake.A[0].x <= zone.left || snake.A[0].y <= zone.top || snake.A[0].x >= zone.right || snake.A[0].y >= zone.bottom) // Nếu chạm vào tường
		{
			return false;
		}
	}
	else
	{
		if (snake.A[0].x <= zone.left)
		{
			snake.A[0].x += 29;
			zone.Draw();
		}
		else if (snake.A[0].y <= zone.top)
		{
			snake.A[0].y += 19;
			zone.Draw();
		}
		else if (snake.A[0].x >= zone.right)
		{
			snake.A[0].x -= 29;
			zone.Draw();
		}
		else if (snake.A[0].y >= zone.bottom)
		{
			snake.A[0].y -= 19;
			zone.Draw();
		}
	}
	return true;
}

void GameOver()
{
	system("cls");
	cout << "\n\n\n\t\tGAME OVER!\n\n";
	cout << "\n\n\n\t\tSCORE: " << Score << "\n\n";
	cout << "\n\n\n\t\tGoodbye! See you again!\n\n";
}

int main()
{
	SetMode();
	SetSpeed();
	Zone zone;
	zone.Draw();
	thread time(ThreadTime);
	time.detach();
	Snake snake;
	snake.Draw();

	Func::gotoxy(40, 15);
	std::cout << "Press SPACE to pause . . . . .";

	Food food;
	food = food.Random(zone);
	food.Draw();

	while (1)
	{
		if (MODE == 3) //MODE Hard
		{
			if (Time == Time2)
			{
				Time2 += 20;
				zone.Erase();
				zone.bottom -= 1;
				zone.left += 1;
				zone.right -= 1;
				zone.top += 1;
				food.Erase();
				zone.Draw();
				food = food.Random(zone);
				food.Draw();
			}
		}

		for (int i = 0; i < snake.Length; i++)
		{
			if (snake.A[i].x == food.x && snake.A[i].y == food.y) // Nếu thân rắn chạm thức ăn
			{
				if (i == 0) // Chỉ đầu rắn chạm thức ăn mới được điểm
				{
					snake.Length++;
					Score += 10;
				}
				else // Nếu lỡ food có random trong phần thân rắn
				{
					Func::gotoxy(food.x, food.y);
					cout << " ";
				}
				food = food.Random(zone);
				food.Draw();
			}
		}

		snake.RemoveTail();
		snake.Move();
		snake.Draw();
		DrawScore();
		DrawTime();
		if (!CheckLose(snake, zone)) // Kiểm tra thắng thua
			break;

		Func::gotoxy(0, 0); // Đưa con trỏ lên góc trên bên trái
		Sleep(Speed);
	}
	GameOver();
	system("pause");
	return 0;
}