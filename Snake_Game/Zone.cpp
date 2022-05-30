#include "Zone.h"
#include "ConstNumber.h"
#include <SFML/Graphics.hpp>
Zone::Zone()
{
	w = 30;
	h = 20;
	position = 5;
}

void Zone::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(w * ConstNumber::size, h * ConstNumber::size)); //tạo chữ nhật có kích thước w * h
	rectangle.setFillColor(sf::Color::Color(141, 160, 0, 255)); //set color cho hình (color background zone)
	rectangle.setOutlineThickness(20);	//set kích thước đường viền ngoài hình (bức tường)
	rectangle.setOutlineColor(sf::Color::Cyan); //set color đường viền ngoài hình (color bức tường)
	rectangle.setPosition(position * ConstNumber::size, position * ConstNumber::size); //Set vị trí bắt đầu vẽ zone
	window.draw(rectangle);
}

void Zone::DrawModeEasy(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(w * ConstNumber::size, h * ConstNumber::size)); //tạo chữ nhật có kích thước w * h
	rectangle.setFillColor(sf::Color::Color(141, 160, 0, 255)); //set color cho hình (color background zone)
	rectangle.setPosition(position * ConstNumber::size, position * ConstNumber::size); //Set vị trí bắt đầu vẽ zone
	window.draw(rectangle);
}
