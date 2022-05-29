#include "Snake.h"
#include "ConstNumber.h"
#include <SFML/Graphics.hpp>
using namespace sf;
// snake contruction
Snake::Snake(Sprite sprite, sf::Sprite spriteHead)
{
	spriteSnake = sprite;//body
	spriteHeadSnake = spriteHead;//head
	Length = 4;
	A[0].x = 11;
	A[0].y = 10;
}
//draw snake
void Snake::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Length; i++)
	{
		if (i == 0)
		{	
			// frist block is head
			spriteHeadSnake.setPosition(A[i].x * ConstNumber::size, A[i].y * ConstNumber::size);
			window.draw(spriteHeadSnake);
		}
		else
		{
			// remaining block is body
			spriteSnake.setPosition(A[i].x * ConstNumber::size, A[i].y * ConstNumber::size);
			window.draw(spriteSnake);
		}

	}
}
// snake move in display
void Snake::Move(int dir)
{
	// snanke len
	for (int i = Length; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	switch (dir)
	{
	case 0:// move right
		A[0].x = A[0].x + 1;
		break;
	case 1:// move up
		A[0].y = A[0].y + 1;
		break;
	case 2:// move left
		A[0].x = A[0].x - 1;
		break;
	case 3://move down
		A[0].y = A[0].y - 1;
		break;
	}
}