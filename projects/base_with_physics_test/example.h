#pragma once
#include "app.h"
#include "Grid.h"
#include "Animator.h"

#define TILE_X 81.81
#define TILE_Y 30.60

#define OFFSET_X 0
#define OFFSET_Y 0


class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();
	
	// I was only able to do 1 sprite for every texture due to some errors I couldnt fix.
	// And I was not able to change the colors of every button in the Kage2d window, and it kept looping around the buttons on its own.
	// The only way I was able to fix all these issues was to make a new pointer for every tile.

	//Under here, I created the pointers for every tile alone with sprites, which is the tile itself.

	// Normal tiles..1 hit to break.
	sf::Texture *CtileTexture; // Cyan normal tile
	sf::Sprite Ctile;
	sf::Texture* RtileTexture; // Red normal tile
	sf::Sprite Rtile;
	sf::Texture* GtileTexture; // Green normal tile
	sf::Sprite Gtile;
	sf::Texture* YtileTexture; // Yellow normal tile
	sf::Sprite Ytile;

	Animator animatorTiles[176];

	// In here we created an array with the count of how many cells I have in my grid so we can be able to do the mapping. Each number will represent a tile.
	sf::Sprite tiles[176];

	// The chosenTile will be the Id of each tile. each tile will have an ID and once the ID is 1 for example. then the first tile is being chosen to be placed into the grid
	int chosenTile = 0;

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

	Grid grid;

	void LoadMapFromSave();

	std::string filename;

	sf::Sprite *m_backgroundSprite;
};
