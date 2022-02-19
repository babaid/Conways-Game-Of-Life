#pragma once



#include<SFML/Graphics.hpp>
#include<vector>



class Game
{
	
	std::vector<std::pair<bool, sf::RectangleShape>> next_cells;
	int rows, cols;
	
public:
	float cell_width, cell_height;
	bool paused = true;
	std::vector<std::pair<bool, sf::RectangleShape>> cells;
	Game(int, int, float, float);
	~Game();
	int neighbors(int, int);

	void kill(int, int);
	void kill(std::vector<std::pair<bool, sf::RectangleShape>>::iterator);
	void revive(int, int);
	void changeState(int, int);
	void generate();
	void reset();
	void reset(float, float);
	bool state(int, int);
};

