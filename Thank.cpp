#include "Thank.h"

//contruction
Thank::Thank(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		// handle error
	}

	// create member name and id whem thank display open
	Thank1[0].setFont(font);
	Thank1[0].setFillColor(sf::Color::White);
	Thank1[0].setString("Le Tuan Luong - 20521588");
	Thank1[0].setPosition(sf::Vector2f(width / 4.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


	Thank1[1].setFont(font);
	Thank1[1].setFillColor(sf::Color::White);
	Thank1[1].setString("Nguyen Thien An - 20521054");
	Thank1[1].setPosition(sf::Vector2f(width / 4.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	Thank1[2].setFont(font);
	Thank1[2].setFillColor(sf::Color::White);
	Thank1[2].setString("Tran Tan Tai - 20521862");
	Thank1[2].setPosition(sf::Vector2f(width / 4.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	selectedItemIndex = 0;
}

//detruction
Thank::~Thank()
{
}
//draw on dispaly
void Thank::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Thank1[i]);
	}
}

