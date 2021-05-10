#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"


class Scene
{
private:
	bool isRunning;

public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
};

