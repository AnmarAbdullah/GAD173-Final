#include "Level1.h"

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Update()
{
	//std::cout << "level 1 update" << std::endl;
	grid.Update();
}

void Level1::Render(sf::RenderWindow& window)
{
	//std::cout << "level 1 render" << std::endl;
	grid.Render(window);
}

void Level1::Init()
{
}

void Level1::Load()
{
	grid.LoadMapFromSave("map.txt");
	std::cout << "hiii" << std::endl;
}
