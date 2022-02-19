#include "../include/Game.h"
#include<iostream>


Game::Game(int r, int c, float w, float h): rows(r), cols(c)
{
	cell_width = 1.0 * w / c;
	cell_height = 1.0 * h / r;
	float x{ 0 }, y{ 0 };

	for (int row = 0; row < rows; row++) {
		for (int columns = 0; columns < cols; columns++) {
			
			sf::RectangleShape cell;
			cell.setPosition(x, y);
			cell.setSize(sf::Vector2f(cell_width, cell_height));
			cell.setFillColor(sf::Color::Black);
			cell.setOutlineColor(sf::Color(255,255,255, 30));
			cell.setOutlineThickness(1);
			cells.push_back(std::make_pair(0, cell));
			x += cell_width;			
		}
		x = 0;
		y += cell_height;
	}
	next_cells = cells;
}


Game::~Game()
{
}

int Game::neighbors(int x, int y)
{
	int cnt = 0;

	//bal felette
	if (x != 0 && y != 0) {
		if (cells[(y - 1) * cols + x - 1].first) cnt++;
	}

	//felette
	if (y != 0) {
		if (cells[(y - 1) * cols + x].first) cnt++;
	}
	//jobb felette
	if (x != cols - 1 && y != 0) {
		if (cells[(y - 1) * cols + x + 1].first) cnt++;
	}
	//bal
	if (x != 0) {
		if (cells[y * cols + x - 1].first) cnt++;
	}

	//jobb
	if (x != cols - 1) {
		if (cells[y * cols + x + 1].first) cnt++;
	}
	// bal alatta
	if (x != 0 && y != rows - 1) {
		if (cells[(y + 1) * cols + x - 1].first) cnt++;
	}
	//alatta
	if (y != rows - 1) {
		if (cells[(y + 1) * cols + x].first) cnt++;
	}
	//jobb alatta

	if (x != cols - 1 && y != cols - 1) {
		if (cells[(y + 1) * cols + x + 1].first) cnt++;
	}
	return cnt;
}

void Game::kill(int x, int y)
{
	next_cells[y * cols + x].first = false;
	next_cells[y * cols + x].second.setFillColor(sf::Color::Black);
}

void Game::kill(std::vector<std::pair<bool, sf::RectangleShape>>::iterator it)
{
	(*it).first = false;
	(*it).second.setFillColor(sf::Color::Black);
}

void Game::revive(int x, int y)
{
	next_cells[y * cols + x].first = true;
	next_cells[y * cols + x].second.setFillColor(sf::Color(170,210,255));
}

void Game::changeState(int x, int y)
{
	
	if (cells[y * cols + x].first == 0) {
		cells[y * cols + x].first = true;
		cells[y * cols + x].second.setFillColor(sf::Color(170, 210, 255));
	}
	else {
		cells[y * cols + x].first = false;
		cells[y * cols + x].second.setFillColor(sf::Color::Black);
	}
}

void Game::generate()
{
	next_cells = cells;

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{

			int n = neighbors(x, y);
			if (n == 3 && !cells[y * cols + x].first)  revive(x, y);
			else if (n < 2 && cells[y * cols + x].first)  kill(x, y);
			else if (cells[y * cols + x].first && (n == 2 || n == 3)) continue;
			else if (cells[y * cols + x].first && n > 3)  kill(x, y);

		}
	}
	cells = next_cells;
}

void Game::reset()
{
	//std::cout << "reset" << std::endl;

	for (auto it = cells.begin(); it != cells.end(); it++)
	{
		kill(it);
		paused = true;
	}
}

void Game::reset(float w, float h)
{
	cells.clear();

	int r = h * 1.0 / cell_height;
	int c = w * 1.0 / cell_width;
	rows = r;
	cols = c;
	float x{ 0 }, y{ 0 };

	for (int row = 0; row < rows; row++) {
		for (int columns = 0; columns < cols; columns++) {

			sf::RectangleShape cell;
			cell.setPosition(x, y);
			cell.setSize(sf::Vector2f(cell_width, cell_height));
			cell.setFillColor(sf::Color::Black);
			//cell.setOutlineColor(sf::Color::White);
			//cell.setOutlineThickness(1);
			cells.push_back(std::make_pair(0, cell));
			x += cell_width;
		}
		x = 0;
		y += cell_height;
	}
	next_cells = cells;
}

bool Game::state(int x, int y)
{
	return cells[y*cols + x].first;
}
