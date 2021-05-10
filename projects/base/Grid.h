#pragma once
#include <SFML/Graphics.hpp>
#include "Animator.h"

#define HORI_LINES_Y 17
#define VERT_LINES_X 12

#define Cell_Count_X 11 + 1
#define Cell_Count_Y 16 + 1

#define Y_Cell_Height 30.06
#define X_Cell_Width 81.8181

#define GRID_SIZE_X 900
#define GRID_SIZE_Y 481

#define Vert_Lines Cell_Count_Y * Y_Cell_Height
#define Hori_Lines Cell_Count_X * X_Cell_Width

#define TILE_X 81.70
#define TILE_Y 30

#define OFFSET_X 0
#define OFFSET_Y 0

class Grid
{
public:
	
	// Here we created a constructor and a deconstructor for the grid.
	Grid();
	~Grid();


	
	// Over here, we are creating a line, the will represent and draw the grid, we are using an array to be able to draw multiple lines to draw the whole grid.
	sf::RectangleShape line[HORI_LINES_Y]; // These are the Horizontal line
	sf::RectangleShape lone[VERT_LINES_X]; // These are the Vertical lines, I called it lone.
	
	
	void Render(sf::RenderWindow& window);
	void LoadMapFromSave(std::string filename);
	void Update();
	
	Animator animatorTiles[176];
	
	int map[176] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

};





