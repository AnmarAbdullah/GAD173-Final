#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Grid.h"
#include "Animator.h"


class Level1 : public Scene
{

	public:
		Level1();
		~Level1();

		virtual void Update();
		virtual void Render(sf::RenderWindow & window);
		void Init();
		void Load();
		
		Grid grid;

};

