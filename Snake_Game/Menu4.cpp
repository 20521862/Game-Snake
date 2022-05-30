#include "Menu4.h"


Menu4::Menu4(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		// handle error
	}

	//create easy buttom
	menu4[0].setFont(font);
	menu4[0].setFillColor(sf::Color::Red);
	menu4[0].setString("Slow");
	menu4[0].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	//create normal button
	menu4[1].setFont(font);
	menu4[1].setFillColor(sf::Color::White);
	menu4[1].setString("Normal");
	menu4[1].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	//vreate hard butoon
	menu4[2].setFont(font);
	menu4[2].setFillColor(sf::Color::White);
	menu4[2].setString("Fast");
	menu4[2].setPosition(sf::Vector2f(width / 2.26, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	// select index use for button choose
	selectedItemIndex = 0;
	selectedItemIndex = 0;
}


Menu4::~Menu4()
{
}
// draw on display
void Menu4::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu4[i]);
	}
}
// move up when press up key
void Menu4::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu4[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu4[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//move down when press down key
void Menu4::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu4[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu4[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}