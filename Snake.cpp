#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct NODE {
    int x, y;
};

struct SNAKE {
    NODE A[100];
    int Length;
};

void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    _COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hConsole, pos);
}

void Init(SNAKE& snake)
{
    snake.Length = 7;
    snake.A[0].x = 9; snake.A[0].y = 5;
    snake.A[1].x = 8; snake.A[1].y = 5;
    snake.A[2].x = 7; snake.A[2].y = 5;
    snake.A[3].x = 7; snake.A[3].y = 4;
    snake.A[4].x = 7; snake.A[4].y = 3;
    snake.A[5].x = 6; snake.A[5].y = 3;
    snake.A[6].x = 5; snake.A[6].y = 3;
    //snake.A[0] = { (9,5), (8,5), (7,5), (7,4), (7,3), (6,3), (5,3) };
}

void Draw(SNAKE snake) {
    int i;
    for (i = 0; i < snake.Length; i++) {
        gotoxy(2*snake.A[i].x, snake.A[i].y);
        printf("%c%c", 219, 219);
        
    }
    gotoxy(snake.A[i].x * 2, snake.A[i].y);
    printf("  ");
    gotoxy(40, 25);
}

void Run(SNAKE& snake, int dir) {
    int i;
    for (i = snake.Length; i > 0; i--) {
        snake.A[i] = snake.A[i - 1];        
    }
    switch (dir)
    {
    case 0: snake.A[0].x = snake.A[0].x + 1; break;
    case 1: snake.A[0].y = snake.A[0].y + 1; break;
    case 2: snake.A[0].x = snake.A[0].x - 1; break;
    case 3: snake.A[0].y = snake.A[0].y - 1; break;
    default:
        break;
    }
}

int main()
{
    SNAKE snake;
    int dir = 0;
    Init(snake);
    Draw(snake);
    while (1) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'd') dir = 0;
            if (c == 's') dir = 1;
            if (c == 'a') dir = 2;
            if (c == 'w') dir = 3;
        }
        Draw(snake);
        Run(snake, dir);
        Sleep(300);
        system("CLS");
    }
    return 0;
}
