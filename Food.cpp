#include "Food.h"
#include <chrono>
#include <iostream>
#include "Zone.h"
#include "ConstNumber.h"
#include <SFML/Graphics.hpp>

Food::Food(sf::Sprite sprite)
{
	spriteFood = sprite;
}
//set random for food
void Food::Random(Zone zone)
{
	x = rand() % zone.w + zone.position;
	y = rand() % zone.h + zone.position;
}
//draw food
void Food::Draw(sf::RenderWindow& window)
{
	spriteFood.setPosition(x * ConstNumber::size, y * ConstNumber::size);
	window.draw(spriteFood);
}
