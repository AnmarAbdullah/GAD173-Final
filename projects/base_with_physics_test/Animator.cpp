#include "Animator.h"
#include "kage2dutil/texture_manager.h"
#include <iostream>

#define Sprite_Width 81
#define Sprite_Height 30

using namespace sf;
using namespace std;
Animator::Animator()
{
}

Animator::~Animator()
{
}

void Animator::load(std::string filename)
{
	
	int indexX = 0;
	int indexY = 0;

	int x = Sprite_Width * indexX;
	int y = Sprite_Height * indexY;
	
	CharacterPic = kage::TextureManager::getTexture(filename);
	SpritePic.setTexture(*CharacterPic);
	SpritePic.setTextureRect(sf::IntRect(x, y, Sprite_Width, Sprite_Height));
}

void Animator::Init()
{  
}

void Animator::Render(sf::RenderWindow& window)
{
	if(animate)
	{
		window.draw(SpritePic);
	}
}

void Animator::Update()
{
	
	if (animate == true)
	{
		Time time = clock.getElapsedTime();
		if (time.asMilliseconds() > Speed)
		{

			int x = Sprite_Width * currentFrame.x;
			int y = Sprite_Height * currentFrame.y;
			SpritePic.setTextureRect(sf::IntRect(x, y, Sprite_Width, Sprite_Height));
			currentFrame.x++;
			//std::cout << "helloo!!!" << std::endl;

			if (currentFrame.x > Endframe.x)
			{
				currentFrame.x = 0;
			}
			clock.restart();
			
		}
	}
	
}

void Animator::Animate(Vector2i startFrame, Vector2i endFrame, int speed)
{

	this->Startframe = startFrame;
	this->Endframe = endFrame;
	this->Speed = speed;
	
	animate = true;
	currentFrame = startFrame;

}


