#include <SFML/Graphics.hpp>
#include <time.h>
#include "Snake.h"
#include "Food.h"
#include "ConstNumber.h"
#include <thread>
#include "Menu.h"
#include "Menu2.h"
#include "Menu3.h"
#include "Thank.h"
using namespace sf;
// set const number

int dir = 0;
int Score = 0;
int MODE = 1;
float TimePlaying = 0;
float timemax = 15;
float delay = 0.1;
bool pause = false;
// function
bool Update(Snake& snake, Food& food, Zone& zone, sf::RenderWindow& window);
void Start();
void playgame();
void gameover();
void selectmode();
void drawScore(Font font, RenderWindow& window);
void drawTime(Font font, RenderWindow& window);

bool Update(Snake& snake, Food& food, Zone& zone, sf::RenderWindow& window)
{
	snake.Move(dir);

	for (int i = 0; i < snake.Length; i++)
	{
		if (snake.A[i].x == food.x && snake.A[i].y == food.y) // Nếu thân rắn chạm thức ăn
		{
			if (i == 0) // Chỉ đầu rắn chạm thức ăn mới được điểm
			{
				snake.Length++;
				Score += 10;
			}
			food.Random(zone);
		}
	}

	if (MODE == 3) //MODE Hard
	{
		if (TimePlaying >= timemax)
		{
			timemax += 15;
			zone.w -= 2;
			zone.h -= 2;
			if (food.x >= zone.w + zone.position || food.x < zone.position || food.y >= zone.h + zone.position || food.y < zone.position)
			{
				//food đang ở ngoài phạm vi zone thì mới random lại
				food.Random(zone);
			}
		}
	}
	for (int i = 1; i < snake.Length; i++)
	{
		if (snake.A[0].x == snake.A[i].x && snake.A[0].y == snake.A[i].y) // Nếu đầu rắn ăn thân
		{
			return false;
		}
	}
	if (MODE == 2 || MODE == 3)
	{
		// Nếu chạm vào tường
		if (snake.A[0].x >= zone.w + zone.position || snake.A[0].x < zone.position || snake.A[0].y >= zone.h + zone.position || snake.A[0].y < zone.position)
		{
			return false;
		}
	}
	else
	{
		if (snake.A[0].x >= zone.w + zone.position) snake.A[0].x = zone.position;
		if (snake.A[0].x < zone.position) snake.A[0].x = zone.w + (zone.position - 1);
		if (snake.A[0].y >= zone.h + zone.position) snake.A[0].y = zone.position;
		if (snake.A[0].y < zone.position) snake.A[0].y = zone.h + (zone.position - 1);
	}
	return true;
}
//draw score

void drawScore(Font font, RenderWindow& window)
{
	// set score on dispaly
	sf::Text text;
	text.setFont(font);
	String str = "Score: " + to_string(Score);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(ConstNumber::size, ConstNumber::size);
	window.draw(text);
}
//draw time 
void drawTime(Font font, RenderWindow& window)
{
	//set text
	sf::Text text;
	text.setFont(font);
	String str = "Time: " + to_string((int)TimePlaying);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(10 * ConstNumber::size, ConstNumber::size);
	window.draw(text);
}
void thank()
{
	//set display for thank
	RenderWindow window(VideoMode(VideoMode(600, 500)), "Thank!!!!!!!");
	//load background
	sf::Texture background;
	background.loadFromFile("images/love.png");
	sf::Sprite spriteBG;
	Vector2u size = background.getSize();
	spriteBG.setTexture(background);
	spriteBG.setOrigin(size.x / 10, size.y / 10);
	//set menu thank
	Thank  thank1(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{	//set background
		sf::Event event1;
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		window.draw(spriteBG);
		//set text
		sf::Text text, text2;
		sf::Font font;
		if (!font.loadFromFile("font/arial.ttf"))
		{

		}
		text.setFont(font);
		text.setFillColor(sf::Color::Magenta);
		text.setString("             Group ALT thanks everyone");
		text2.setFont(font);
		text2.setFillColor(sf::Color::Cyan);
		text2.setString("\t\t \nMember: ");
		text2.setPosition(0, 40);
		window.draw(text);
		window.draw(text2);;
		thank1.draw(window);
		window.display();
		sf::Event event;
		// exit when press enter key
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
					window.close();
					break;
				}
			}
		}

	}
}

void gameover()
{
	//set display for gameover
	RenderWindow window(VideoMode(VideoMode(500, 400)), "Game over!!!!!!!");
	//load background
	sf::Texture background;
	background.loadFromFile("images/hi.bmp");
	sf::Sprite spriteBG;
	Vector2u size = background.getSize();
	spriteBG.setTexture(background);
	spriteBG.setOrigin(size.x / 10, size.y / 10);
	//set menu gameover
	Menu3  menu3(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
		//choose
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu3.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu3.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu3.GetPressedItem())
					{
					case 0:
						//play again
						window.close();
						selectmode();
						break;
					case 1:
						//exit
						window.close();
						thank();
						break;
					}

				}
			}
		}
		window.clear();
		//set background
		sf::Event event1;
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		window.draw(spriteBG);
		//set text
		sf::Text text, text2;
		sf::Font font;
		if (!font.loadFromFile("font/arial.ttf"))
		{
			// error...
		}
		text.setFont(font);
		text.setFillColor(sf::Color::Black);
		text.setString("      -----------GAME OVER-----------");
		text2.setFont(font);
		text2.setFillColor(sf::Color::Black);
		text2.setString("Score: " + to_string(Score));
		text2.setPosition(0, 40);
		window.draw(text);
		window.draw(text2);
		menu3.draw(window);

		window.display();
	}
}
// draw text "Press space to pause game
void drawPause(Font font, RenderWindow& window)
{	
	//set text
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(20 * ConstNumber::size, ConstNumber::size);
	if (!pause)
	{
		text.setString("Press space to pause game...");
	}
	else
	{
		text.setString("Press space to continue...");
	}
	window.draw(text);
}
// play
void playgame()
{
	dir = 0;
	Score = 0;
	TimePlaying = 0;

	srand(time(0));
	//set display for game
	RenderWindow window(VideoMode(ConstNumber::wWindow, ConstNumber::hWindow), "Snake Game!");

	Texture t1, t2, t3;
	// load images
	t1.loadFromFile("images/red.png");//snake body
	Sprite spriteSnake(t1);
	t3.loadFromFile("images/green.png");//head
	Sprite spriteHead(t3);
	Snake snake(spriteSnake, spriteHead);

	t2.loadFromFile("images/white.png");//food
	Sprite spriteFood(t2);
	Food food(spriteFood);

	Zone zone;
	// food in play zone
	food.Random(zone);
	//time
	Clock clock;
	float timer = 0;
	//font
	Font arial;
	arial.loadFromFile("font/arial.ttf");

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		if (!pause)
		{
			TimePlaying += time;
		}
		//pause when press space key
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyReleased)
			{
				if (e.key.code == Keyboard::Space)
				{
					pause = !pause;
				}
			}
		}

		if (timer > delay)
		{
			timer = 0;
			if (Keyboard::isKeyPressed(Keyboard::A) && dir != 0)
			{
				dir = 2;
			}
			else if (Keyboard::isKeyPressed(Keyboard::D) && dir != 2)
			{
				dir = 0;
			}
			else if (Keyboard::isKeyPressed(Keyboard::W) && dir != 1)
			{
				dir = 3;
			}
			else if (Keyboard::isKeyPressed(Keyboard::S) && dir != 3)
			{
				dir = 1;
			}
			if (!pause)
			{
				if (!Update(snake, food, zone, window))
				{
					window.close();
					gameover();
				}
			}
		}

		window.clear();
		//setting for game graphic
		if (MODE == 1)
		{
			zone.DrawModeEasy(window);
		}
		else
		{
			zone.Draw(window);
		}
		
		snake.Draw(window);
		food.Draw(window);
		drawScore(arial, window);
		drawTime(arial, window);
		drawPause(arial, window);
		window.display();

		sleep(milliseconds(15));
	}
}

void selectmode()
{ 
	// set display for select game mode
	sf::RenderWindow window1(sf::VideoMode(500, 400), "Mode");
	sf::Texture background;
	//load backgorund
	background.loadFromFile("images/hi.bmp");
	sf::Sprite spriteBG;
	Vector2u size = background.getSize();
	spriteBG.setTexture(background);
	spriteBG.setOrigin(size.x / 10, size.y / 10);
	//set menu select game mode
	Menu2 menu2(window1.getSize().x, window1.getSize().y);

	while (window1.isOpen())
	{
		sf::Event event;
		//choose
		while (window1.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu2.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu2.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu2.GetPressedItem())
					{
					case 0: //easy
						MODE = 1;
						break;
					case 1: //normal
						MODE = 2;
						break;
					case 2: //hard
						MODE = 3;
						break;
					}
					window1.close();
					playgame();
					break;
				}

				break;
			case sf::Event::Closed:
				window1.close();
				break;

			}
		}
		window1.clear();
		//set backgroubd
		sf::Event event1;
		sf::Event e;
		while (window1.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window1.close();
		}
		window1.draw(spriteBG);

		//set text
		sf::Text text;
		sf::Font font;
		if (!font.loadFromFile("font/arial.ttf"))
		{
			// error...
		}
		text.setFont(font);
		text.setFillColor(sf::Color::Black);
		text.setString("                 Select game mode");
		window1.draw(text);
		menu2.draw(window1);
		window1.display();
	}
}
//staer game whem select game mode

void Start()
{
	//set display
	sf::RenderWindow window(sf::VideoMode(500, 400), "Menu");
	//load background
	sf::Texture background;
	background.loadFromFile("images/hi.bmp");
	sf::Sprite spriteBG;
	Vector2u size = background.getSize();
	spriteBG.setTexture(background);
	spriteBG.setOrigin(size.x / 10, size.y / 10);

	//set menu start
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{	
			// choose
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{

					case 0:
						//play game
						window.close();
						selectmode();

					case 1:
						//exit;
						thank();
						window.close();


						break;
					}
					break;
				}

				break;
			case sf::Event::Closed:
				window.close();
				break;

			}
		}


		window.clear();
		//set background
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		window.draw(spriteBG);
		//set text
		sf::Text text;
		sf::Font font;
		if (!font.loadFromFile("font/arial.ttf"))
		{
			// error...
		}
		text.setFont(font);
		text.setFillColor(sf::Color::Black);
		text.setString("         Welcome to Snake Game");
		window.draw(text);

		menu.draw(window);
		window.display();
	}
}



int main()
{
	//play game
	Start();
	return 0;
}
