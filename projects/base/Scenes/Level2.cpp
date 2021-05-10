#include "Level2.h"

Level2::Level2()
{
}

Level2::~Level2()
{
}

void Level2::Update()
{

	grid.Update();
}

void Level2::Render(sf::RenderWindow& window)
{
	grid.Render(window);
}

void Level2::Init()
{
}

void Level2::Load()
{
	grid.LoadMapFromSave("map2.txt");
	std::cout << "hiii" << std::endl;
}
