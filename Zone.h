#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Zone
{
public:
	int w, h, position;
	Zone();
	void Draw(sf::RenderWindow& window);
};


