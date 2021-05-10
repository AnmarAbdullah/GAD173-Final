#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

	virtual void Update();
	virtual void Render(sf::RenderWindow& window) ;
	void Init();
	void Load();
};

