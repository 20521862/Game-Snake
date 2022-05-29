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

void Food::Random(Zone zone) //Random food, chỉ ramdom trong zone
{
	x = rand() % zone.w + zone.position;
	y = rand() % zone.h + zone.position;
}

void Food::Draw(sf::RenderWindow& window)
{
	spriteFood.setPosition(x * ConstNumber::size, y * ConstNumber::size); //Set vị trí khi draw food
	window.draw(spriteFood);
}
