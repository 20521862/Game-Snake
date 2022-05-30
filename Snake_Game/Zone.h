#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Zone
{
public:
	int w, h, position;
	//w: chiều rộng, h: chiều cao, position: vị trí bắt đầu draw
	Zone();
	void Draw(sf::RenderWindow& window); //draw zone
	void DrawModeEasy(sf::RenderWindow& window); //draw zone mode easy
};