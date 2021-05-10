#include "Grid.h"

// In the constructor we are drawing the Grid itself, the line size and position along with a for loop to keep drawing lines until it reaches our UI design cell count.

Grid::Grid() 
{
	for (size_t i = 0; i < Cell_Count_Y + 1; i++)
	{
		Hori_line[i].setSize(sf::Vector2f(Hori_Lines, 2));
		Hori_line[i].setPosition(sf::Vector2f(Start_x, Start_y + i * Y_Cell_Height));
	}

	for (size_t e = 0; e < Cell_Count_X + 1; e++)
	{
		Vert_line[e].setSize(sf::Vector2f(2, Vert_Lines));
		Vert_line[e].setPosition(sf::Vector2f(Start_x + e * X_Cell_Width, Start_y));
	}
}

Grid::~Grid() 
{

}

// Here is the rendering, an easy step to just render what we want to draw into the Kage2d Window. With the for loops as well to render all the lines count included in the array
void Grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < Cell_Count_Y + 1; i++)
	{
		window.draw(Hori_line[i]);
 	}
	for (size_t e = 0; e <  Cell_Count_X + 1; e++)
	{
		window.draw(Vert_line[e]);
	}
};