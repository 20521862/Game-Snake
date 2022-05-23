#include <windows.h>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

int Score = 0;
int Speed = 180;
int Time = 0;
int Time2 = 10;

struct NODE
{
    int x, y;
};

struct SNAKE
{
    NODE A[1000];
    int Length;
};

struct ZONE
{
    int top;
    int bottom;
    int left;
    int right;
};

void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    _COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hConsole, pos);
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
        Time++;
        Sleep(1000);
    }
}

void InitZone(ZONE &zone)
{
    zone.top = 5;
    zone.left = 5;
    zone.right = 35;
    zone.bottom = 25;
}

void DrawZone(ZONE zone)
{
    gotoxy(zone.left, zone.top);
    for (int i = zone.left; i < zone.right; i++)
    {
        cout << "#";
    }

    for (int i = zone.top; i < zone.bottom; i++)
    {
        gotoxy(zone.left, i);
        cout << "#";
    }

    gotoxy(zone.left, zone.bottom);
    for (int i = zone.left; i < zone.right; i++)
    {
        cout << "#";
    }

    for (int i = zone.top; i < zone.bottom; i++)
    {
        gotoxy(zone.right, i);
        cout << "#";
    }
}

void EraseZone(ZONE zone)
{
    gotoxy(zone.left, zone.top);
    for (int i = zone.left; i < zone.right; i++)
    {
        cout << " ";
    }

    for (int i = zone.top; i < zone.bottom; i++)
    {
        gotoxy(zone.left, i);
        cout << " ";
    }

    gotoxy(zone.left, zone.bottom);
    for (int i = zone.left; i < zone.right; i++)
    {
        cout << " ";
    }

    for (int i = zone.top; i < zone.bottom; i++)
    {
        gotoxy(zone.right, i);
        cout << " ";
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
    for (int i = 0; i < snake.Length; i++)
    {
        gotoxy(snake.A[i].x, snake.A[i].y);
        if (i == 0)
        {
            cout << "O"; // hinh dang dau con ran
        }
        else
        {
            cout << "o"; // hinh dang than con ran
        }
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

int RandomInt(int min, int max)
{
    srand(time(NULL));
    int n = rand() % (max - min + 1) + min;
    return n;
}

NODE DrawFood(ZONE zone)
{
    NODE food;
    food.x = RandomInt(zone.left + 1, zone.right - 1);
    food.y = RandomInt(zone.top + 1, zone.bottom - 1);
    gotoxy(food.x, food.y);
    cout << "X"; // hinh dang thuc an
    return food;
}

void EraseFood(NODE food)
{
    gotoxy(food.x, food.y);
    cout << " ";
}

void DrawScore()
{
    gotoxy(40, 5);
    cout << "SCORE: " << Score;
}

void DrawTime()
{
    gotoxy(40, 10);
    cout << "TIME: " << Time;
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
    SetSpeed();

    SNAKE snake;
    NODE food;
    ZONE zone;
    InitZone(zone);
    DrawZone(zone);

    thread time(ThreadTime);
    time.detach();

    int dir = 0;
    int olddir = 0;
    InitSnake(snake);
    DrawSnake(snake);

    food = DrawFood(zone);

    while (1)
    {
        if (Time == Time2)
        {
            Time2 += 10;
            EraseZone(zone);
            zone.bottom -= 2;
            zone.left += 2;
            zone.right -= 2;
            zone.top += 2;
            EraseFood(food);
            DrawZone(zone);
            food = DrawFood(zone);
        }

        gotoxy(snake.A[snake.Length - 1].x, snake.A[snake.Length - 1].y); // xóa đuôi
        cout << " ";

        for (int i = 0; i < snake.Length; i++)
        {
            if (snake.A[i].x == food.x && snake.A[i].y == food.y) // Nếu thân rắn chạm thức ăn
            {
                if (i == 0) // Chỉ đầu rắn chạm thức ăn mới được điểm
                {
                    snake.Length++;
                    Score++;
                }
                else // Nếu lỡ food có random trong phần thân rắn
                {
                    gotoxy(food.x, food.y);
                    cout << " ";
                }
                food = DrawFood(zone);
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
        DrawScore();
        DrawTime();
        gotoxy(0, 0); // Đưa con trỏ lên góc trên bên trái

        int flag = 0;
        for (int i = 1; i < snake.Length; i++)
        {
            if (snake.A[0].x == snake.A[i].x && snake.A[0].y == snake.A[i].y) // Nếu đầu rắn ăn thân
            {
                flag = 1;
                break;
            }
        }
        if (snake.A[0].x <= zone.left || snake.A[0].y <= zone.top || snake.A[0].x >= zone.right || snake.A[0].y >= zone.bottom) // Nếu chạm vào tường
        {
            flag = 1;
        }
        if (flag == 1)
        {
            break;
        }
        Sleep(Speed);
    }
    GameOver();
    system("pause");
    return 0;
}