#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Thank
{
public:
	Thank(float width, float height);
	~Thank();

	void draw(sf::RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text Thank1[MAX_NUMBER_OF_ITEMS];

};

