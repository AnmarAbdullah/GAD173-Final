#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Animator
{
private:

	sf::Texture* CharacterPic;

	sf::Clock clock;

	sf::Vector2i Startframe;
	sf::Vector2i currentFrame;
	sf::Vector2i Endframe;
	int Speed;

	bool animate = false;

	int indexX = 0;
	int indexY = 0;

public:
	Animator();
	~Animator();
	sf::Sprite SpritePic;
	void load(std::string filename);
	void Init();
	void Render(sf::RenderWindow& window);
	void Update();

	void Animate(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
};

