#include "Menu3.h"


Menu3::Menu3(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		// handle error
	}

	//create play again button
	menu3[0].setFont(font);
	menu3[0].setFillColor(sf::Color::Red);
	menu3[0].setString("Play again");
	menu3[0].setPosition(sf::Vector2f(width /2.6, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	//create exit button
	menu3[1].setFont(font);
	menu3[1].setFillColor(sf::Color::White);
	menu3[1].setString("Exit");
	menu3[1].setPosition(sf::Vector2f(width / 2.28, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	// select index use for button choose
	selectedItemIndex = 0;
}


Menu3::~Menu3()
{
}
// draw on display
void Menu3::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu3[i]);
	}
}
// move up when press up key
void Menu3::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu3[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu3[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
// move down when press down key
void Menu3::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu3[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu3[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}