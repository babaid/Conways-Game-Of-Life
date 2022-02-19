#include "../include/GUI.h"
#include "../include/Game.h"
#include<iostream>
#include<vector>
#include<chrono>
#include<thread>

using namespace std;

GUI::GUI()
{
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(700,700), "Cellular Automaton");
	window.setPosition(sf::Vector2i(0,0));
	dw = 700.0;
	dh = 700.0;
	
	

	
}


GUI::~GUI()
{
}

void GUI::run()
{
	Game* game = new Game(rows , cols, dw, dh);
	bool stateOf;
	bool mb_pressed = false;
	sf::Vector2i pos;
	unsigned int playing_delay=500;
	

	while(window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Space) game->paused = !(game->paused);
				else if (event.key.code == sf::Keyboard::R) game->reset();
				else if (event.key.code == sf::Keyboard::Escape) window.close();
				else if (event.key.code == sf::Keyboard::Up) { if (playing_delay != 0) playing_delay -= 50; 
				
				}
				else if (event.key.code == sf::Keyboard::Down) { if (playing_delay < 2000) playing_delay += 50; }
				
				break;

			case sf::Event::MouseButtonPressed:

				if (game->paused) {
					mb_pressed = true;
					pos = sf::Mouse::getPosition(window);
					pos.x /= game->cell_width;
					pos.y /= game->cell_height;					game->changeState(pos.x, pos.y);
					stateOf = game->state(pos.x, pos.y);
				}
				break;
			
			case sf::Event::MouseButtonReleased:
				mb_pressed = false;

			case sf::Event::MouseMoved:
				if (mb_pressed && game->paused) {
					
					int x = event.mouseMove.x/game->cell_width;
					int y = event.mouseMove.y/game->cell_height;

					if (x != pos.x || y != pos.y) {						
						if(game->state(x, y) != stateOf)
							game->changeState(x, y);

						pos.x = x;
						pos.y = y;
					}

					
				}
				break;
			case sf::Event::Resized:

				break;
			}
		}
		window.clear(sf::Color::Black);
		

		


		if (!game->paused) {
			game->generate();
			this_thread::sleep_for(chrono::milliseconds(playing_delay));
		}

		
		for (auto it = game->cells.begin(); it != game->cells.end(); it++) window.draw((*it).second);
		
		window.display();
		
	}

}

void GUI::change(int x, int y)
{
	if (grid.at(y * 6 + x).getFillColor() == sf::Color(153, 153, 200)) grid.at(y * 6 + x).setFillColor(sf::Color::White);
	else grid.at(y * 6 + x).setFillColor(sf::Color(153, 153, 200));
}
