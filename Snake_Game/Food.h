#pragma once
#include "Zone.h"
#include <SFML/Graphics.hpp>
class Food
{
public:
	int x, y; //tọa độ food
	sf::Sprite spriteFood;
	Food(sf::Sprite sprite);
	void Random(Zone zone); //random food
	void Draw(sf::RenderWindow& window); //draw food
};


