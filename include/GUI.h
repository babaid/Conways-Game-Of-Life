#pragma once
#include<SFML/Graphics.hpp>
class GUI
{
	sf::RenderWindow window;
	std::vector<sf::RectangleShape> grid;
	float w, h;
	float dw, dh;
	sf::Font font;
public:
	int rows = 30, cols = 30;
	GUI();
	~GUI();

	void run();
	void change(int, int);
};

