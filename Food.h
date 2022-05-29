#pragma once
#include "Zone.h"
#include <SFML/Graphics.hpp>
class Food
{
public:
	int x, y;
	sf::Sprite spriteFood;
	Food(sf::Sprite sprite);
	void Random(Zone zone);
	void Draw(sf::RenderWindow& window);
};


