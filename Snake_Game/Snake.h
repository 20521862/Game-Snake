#pragma once
#include <SFML/Graphics.hpp>
struct NODE
{
	int x, y;
};
class Snake
{
public:
	NODE A[1000];
	int Length;
	sf::Sprite spriteSnake;
	sf::Sprite spriteHeadSnake;
	Snake(sf::Sprite sprite, sf::Sprite spriteHead);
	void Draw(sf::RenderWindow& window);
	void Move(int dir);
};



