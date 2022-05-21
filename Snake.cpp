#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int Score = 0;

struct NODE
{
    int x, y;
};

struct SNAKE
{
    NODE A[100];
    int Length;
};

struct ZONE
{
    NODE topleft;
    NODE bottomright;
};

void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    _COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hConsole, pos);
}

void InitZone(ZONE &zone)
{
    zone.topleft.x = 5;
    zone.topleft.y = 5;
    zone.bottomright.x = 35;
    zone.bottomright.y = 25;
}

void DrawZone(ZONE zone)
{
    gotoxy(zone.topleft.x, zone.topleft.y);
    for (int i = zone.topleft.x; i < zone.bottomright.x; i++)
    {
        cout << "#";
    }

    for (int i = zone.topleft.y; i < zone.bottomright.y; i++)
    {
        gotoxy(zone.topleft.x, i);
        cout << "#";
    }
    gotoxy(zone.topleft.x, zone.bottomright.y);
    for (int i = zone.topleft.x; i < zone.bottomright.x; i++)
    {
        cout << "#";
    }
    for (int i = zone.topleft.y; i < zone.bottomright.y; i++)
    {
        gotoxy(zone.bottomright.x, i);
        cout << "#";
    }
}

void InitSnake(SNAKE &snake)
{
    snake.Length = 4;
    snake.A[0].x = 11;
    snake.A[0].y = 10;
    snake.A[1].x = 10;
    snake.A[1].y = 10;
    snake.A[2].x = 9;
    snake.A[2].y = 10;
    snake.A[3].x = 8;
    snake.A[3].y = 10;
}

void DrawSnake(SNAKE snake)
{
    int i;
    for (i = 0; i < snake.Length; i++)
    {
        gotoxy(snake.A[i].x, snake.A[i].y);
        cout << "O"; // hinh dang con ran
    }
}

void Run(SNAKE &snake, int &dir, int olddir)
{
    for (int i = snake.Length; i > 0; i--)
    {
        snake.A[i] = snake.A[i - 1];
    }
    switch (dir)
    {
    case 0:
        if (olddir == 2) // Trước đó đang sang trái mà nhấn sang phải
        {
            snake.A[0].x = snake.A[0].x - 1;
            dir = olddir;
            break;
        }
        snake.A[0].x = snake.A[0].x + 1;
        break;
    case 1:
        if (olddir == 3) // Trước đó đang đi xuống mà nhấn đi lên
        {
            snake.A[0].y = snake.A[0].y - 1;
            dir = olddir;
            break;
        }
        snake.A[0].y = snake.A[0].y + 1;
        break;
    case 2:
        if (olddir == 0) // Trước đó đang sang phải mà nhấn sang trái
        {
            snake.A[0].x = snake.A[0].x + 1;
            dir = olddir;
            break;
        }
        snake.A[0].x = snake.A[0].x - 1;
        break;
    case 3:
        if (olddir == 1) // Trước đó đang đi lên mà nhấn đi xuống
        {
            snake.A[0].y = snake.A[0].y + 1;
            dir = olddir;
            break;
        }
        snake.A[0].y = snake.A[0].y - 1;
        break;
    }
}

void DrawScore(ZONE zone)
{
    gotoxy(zone.bottomright.x + 5, zone.bottomright.y);
    cout << "SCORE: " << Score;
}

void GameOver()
{
    system("cls");
    cout << "\n\n\n\t\tGAME OVER!\n\n";
    cout << "\n\n\n\t\tSCORE: " << Score << "\n";
    cout << "\n\n\n\t\tGoodbye! See you again!";
}

int RandomInt(int min, int max)
{
    int n = rand() % (max - min + 1) + min;
    return n;
}

int main()
{
    SNAKE snake;
    NODE food;
    ZONE zone;
    InitZone(zone);
    DrawZone(zone);

    int dir = 0;
    int olddir = 0;
    InitSnake(snake);
    DrawSnake(snake);

    food.x = RandomInt(zone.topleft.x, zone.bottomright.x); // Random vi tri thuc an
    food.y = RandomInt(zone.topleft.y, zone.bottomright.y);
    gotoxy(food.x, food.y);
    cout << "X"; // hinh dang thuc an

    while (1)
    {
        gotoxy(snake.A[snake.Length - 1].x, snake.A[snake.Length - 1].y); // xoa duoi
        cout << " ";

        for (int i = 0; i < snake.Length; i++)
        {
            if (snake.A[i].x == food.x && snake.A[i].y == food.y) // neu dau ran cham thuc an
            {
                snake.Length++;
                Score++;
                food.x = RandomInt(zone.topleft.x + 1, zone.bottomright.x - 1);
                food.y = RandomInt(zone.topleft.y + 1, zone.bottomright.y - 1);
                gotoxy(food.x, food.y);
                cout << "X";
            }
        }

        if (kbhit())
        {
            olddir = dir;
            char c = getch();
            if (c == 'd') // sang phai
                dir = 0;
            else if (c == 's') // di xuong
                dir = 1;
            else if (c == 'a') // sang trai
                dir = 2;
            else if (c == 'w') // di len
                dir = 3;
        }
        Run(snake, dir, olddir);
        DrawSnake(snake);
        DrawScore(zone);
        gotoxy(0, 0);
        cout << " ";

        int flag = 0;
        for (int i = 1; i < snake.Length; i++)
        {
            if (snake.A[0].x == snake.A[i].x && snake.A[0].y == snake.A[i].y) // Nếu đầu rắn ăn thân
            {
                flag = 1;
                break;
            }
        }
        if (snake.A[0].x <= zone.topleft.x || snake.A[0].y <= zone.topleft.y || snake.A[0].x >= zone.bottomright.x || snake.A[0].y >= zone.bottomright.y)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            break;
        }
        Sleep(180);
    }
    GameOver();
    system("pause");
    return 0;
}