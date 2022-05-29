#include "Menu2.h"


Menu2::Menu2(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		// handle error
	}

	//create easy buttom
	menu2[0].setFont(font);
	menu2[0].setFillColor(sf::Color::Red);
	menu2[0].setString("Easy");
	menu2[0].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	//create normal button
	menu2[1].setFont(font);
	menu2[1].setFillColor(sf::Color::White);
	menu2[1].setString("Normal");
	menu2[1].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	//vreate hard butoon
	menu2[2].setFont(font);
	menu2[2].setFillColor(sf::Color::White);
	menu2[2].setString("Hard");
	menu2[2].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	// select index use for button choose
	selectedItemIndex = 0;
	selectedItemIndex = 0;
}


Menu2::~Menu2()
{
}
// draw on display
void Menu2::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu2[i]);
	}
}
// move up when press up key
void Menu2::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu2[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu2[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//move down when press down key
void Menu2::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu2[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu2[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}