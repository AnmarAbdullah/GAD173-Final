#pragma once
#include "Grid.h"
#include "Animator.h"
#include "Scene.h"


class Level2 : public Scene
{

public:
	Level2();
	~Level2();

	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	void Init();
	void Load();

	Grid grid;

};

