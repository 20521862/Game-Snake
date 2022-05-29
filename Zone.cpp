#include "Zone.h"
#include "ConstNumber.h"
#include <SFML/Graphics.hpp>
Zone::Zone()
{
	w = 30;
	h = 20;
	position = 5;
}
//draw zone on display

void Zone::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(w * ConstNumber::size, h * ConstNumber::size));
	rectangle.setFillColor(sf::Color::Color(141, 160, 0, 255));
	rectangle.setOutlineThickness(20);
	rectangle.setOutlineColor(sf::Color::Cyan);
	rectangle.setPosition(position * ConstNumber::size, position * ConstNumber::size);
	window.draw(rectangle);
}
