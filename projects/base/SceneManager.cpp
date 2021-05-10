#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Loadscene(int sceneIndex)
{
	currentSceneIndex = sceneIndex;
	Scene* scene = scenes[currentSceneIndex];
	scene->Load();
}

void SceneManager::Addscene(Scene* scene)
{
	scenes.push_back(scene);
}

void SceneManager::RemoveScene(int sceneIndex)
{
}

void SceneManager::update()
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Update();
	}
}

void SceneManager::Render(sf::RenderWindow& window)
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Render(window);
	}
}
