# Conways-Game-Of-Life
An implementation of Conway's Game of Life in C++ using the graphics library SFML.

> The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine. 
> 

# Rules
The Rules which one has to implement are simple:
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

[Source: Wikipedia]

# Implementation
The implementation is fairly simple. One has to create a grid of cells, and at each time step update them. Instead of creating some thing like a 
~~~~
std::vector<std::vector<std::pair<bool, sf::RectangleShape>>> grid;
~~~~
in which one could easily acces each vertice in an easy manner (e.g. grid[i][j].first) we use a computationally faster alternative, which is just a vector of pairs.
~~~~
std::vector<<std::pair<bool, sf::RectangleShape>> grid(rows*columns);
~~~~

in which it holds that:
~~~~
grid[i][j] = grid[i * rows + j]
~~~~
This is the only thing that could be not straight forward at first glance.

# Build the project

You can build the executable of the project and play around with it with cmake;

First clone the project:
~~~~
git clone https://github.com/babaid/Conways-Game-Of-Life
~~~~
Then navigate in your command line to the project folder and type
~~~~
cmake --configurate
cmake --build ./build --config Release --target cgol
~~~~
Now there should be an executable called cgol.exe in the build folder. You can play now! :) \ 
Check out the screenshots and GIFs:

The Manual of the game: \
![Alt Text](https://github.com/babaid/Conways-Game-Of-Life/blob/master/screenshots/manual.png)\
Some life-action: \
![Alt Text](https://github.com/babaid/Conways-Game-Of-Life/blob/master/screenshots/moving.gif)\
