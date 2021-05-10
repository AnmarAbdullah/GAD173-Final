#pragma once
#include "Scene.h"
#include "SFML/Graphics.hpp"
#include <vector>

class SceneManager
{
private:

	int currentSceneIndex;
	std::vector<Scene*> scenes;

public:
	SceneManager();
	~SceneManager();

	void Loadscene(int sceneIndex);
	void Addscene(Scene* scene);
	void RemoveScene(int sceneIndex);

	void update();
	void Render(sf::RenderWindow& window);

	inline const int& GetActiveScene() { return currentSceneIndex; }
};
