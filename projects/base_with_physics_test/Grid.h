#pragma once
#include <SFML/Graphics.hpp>


#define Cell_Count_X 11 //12
#define Cell_Count_Y 16 // 17

#define Y_Cell_Height 30.60 //30
#define X_Cell_Width 81.81 //81

#define Start_x 492
#define Start_y 181

#define GRID_SIZE_X 900
#define GRID_SIZE_Y 491

#define Vert_Lines Cell_Count_Y * Y_Cell_Height
#define Hori_Lines Cell_Count_X * X_Cell_Width

class Grid
{
public:
	
	// Here we created a constructor and a deconstructor for the grid.
	Grid();
	~Grid();


	
	// Over here, we are creating a line, the will represent and draw the grid, we are using an array to be able to draw multiple lines to draw the whole grid.
	sf::RectangleShape Hori_line[Cell_Count_Y + 1]; // These are the Horizontal line
	sf::RectangleShape Vert_line[Cell_Count_X + 1]; // These are the Vertical lines
	
	
	void Render(sf::RenderWindow& window);

};





