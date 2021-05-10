#include "Grid.h"
#include "SaveLoad.h"

// In the constructor we are drawing the Grid itself, the line size and position along with a for loop to keep drawing lines until it reaches our UI design cell count.

Grid::Grid() 
{
	/*for (size_t i = 0; i < HORI_LINES_Y; i++) 
	{
		line[i].setSize(sf::Vector2f(GRID_SIZE_X, 2));
		line[i].setPosition(sf::Vector2f(491, 180 + i * Y_Cell_Height));
	}

	for (size_t e = 0; e < VERT_LINES_X; e++)
	{
		lone[e].setSize(sf::Vector2f(2, GRID_SIZE_Y));
		lone[e].setPosition(sf::Vector2f(491 + e * X_Cell_Width, 180));
	}*/
	for (size_t i = 0; i < 176; i++)
	{
		animatorTiles[i].load("data/character.png");
	}
}
void Grid::LoadMapFromSave(std::string filename)
{
	SaveLoad::Load(filename, map, 176);
	std::cout << " hiii" << std::endl;
	for (size_t y = 0; y < 16; y++)
	{
		for (size_t x = 0; x < 11; x++)
		{
			int i = x + y * 11;

			animatorTiles[i].SpritePic.setPosition(sf::Vector2f(OFFSET_X + x * TILE_X + 493, OFFSET_Y + y * TILE_Y + 181));

			if (map[i] == 0)
			{

			}
			if (map[i] == 1)
			{
				animatorTiles[i].Animate(sf::Vector2i(0, 0), sf::Vector2i(7, 0), 100);
			}
			if (map[i] == 2)
			{

				animatorTiles[i].Animate(sf::Vector2i(0, 3), sf::Vector2i(7, 3), 100);
			}
			if (map[i] == 3)
			{

				animatorTiles[i].Animate(sf::Vector2i(0, 1), sf::Vector2i(7, 1), 100);
			}
			if (map[i] == 4)
			{

				animatorTiles[i].Animate(sf::Vector2i(0, 2), sf::Vector2i(7, 2), 100);
			}
		}
	}
}

void Grid::Update()
{
	for (size_t i = 0; i < 176; i++)
	{
		animatorTiles[i].Update();
	}
}

Grid::~Grid() 
{

}

// Here is the rendering, an easy step to just render what we want to draw into the Kage2d Window. With the for loops as well to render all the lines count included in the array
void Grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < HORI_LINES_Y; i++)
	{
		window.draw(line[i]);
 	}
	for (size_t e = 0; e < VERT_LINES_X; e++)
	{
		window.draw(lone[e]);
	}
	for (size_t i = 0; i < 176; i++)
	{
		//m_window.draw(tiles[i]);
		animatorTiles[i].Render(window);
	}
};