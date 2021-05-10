#include "example.h"
#include "SaveLoad.h"
#include "Scenes/MainMenu.h"
#include "Scenes/Level1.h"
#include "Scenes/Level2.h"


Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/background.gif");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	// Over here it's as if we are defining the texture, or drawing, thats why, the png files are the picture that we included into the project to be the design of each tile. every texture is representing a picture/design
	CtileTexture = kage::TextureManager::getTexture("data/Ctile.png");
	RtileTexture = kage::TextureManager::getTexture("data/Rtile.png");
	GtileTexture = kage::TextureManager::getTexture("data/Gtile.png");
	YtileTexture = kage::TextureManager::getTexture("data/Ytile.png");

	LoadMapFromSave();

	// Over we are assigning each tile on its own texture, by each other their pointers.

	Ctile.setTexture(*CtileTexture);
	Rtile.setTexture(*RtileTexture);
	Gtile.setTexture(*GtileTexture);
	Ytile.setTexture(*YtileTexture);


	// Adding scenes here just like adding an index to an array...but 
	scenemanager.Addscene(new MainMenu());
	scenemanager.Addscene(new Level1());
	scenemanager.Addscene(new Level2());

	for (size_t i = 0; i < 176; i++)
	{
		animatorTiles[i].load("data/character.png");
	}
	
	return true;
}

void Example::LoadMapFromSave()
{
	for (size_t y = 0; y < 16; y++)
	{
		for (size_t x = 0; x < 11; x++)
		{
			int i = x + y * 11;

			tiles[i].setPosition(sf::Vector2f(OFFSET_X + x * TILE_X + 493, OFFSET_Y + y * TILE_Y + 181));
			animatorTiles[i].SpritePic.setPosition(sf::Vector2f(OFFSET_X + x * TILE_X + 493, OFFSET_Y + y * TILE_Y + 181));
			
			if (map[i] == 0)
			{

			}
			if (map[i] == 1)
			{
				tiles[i].setTexture(*CtileTexture);
				animatorTiles[i].Animate(sf::Vector2i(0, 0), sf::Vector2i(7, 0), 100);
			}
			if (map[i] == 2)
			{
				tiles[i].setTexture(*RtileTexture);
				animatorTiles[i].Animate(sf::Vector2i(0, 3), sf::Vector2i(7, 3), 100);
			}
			if (map[i] == 3)
			{
				tiles[i].setTexture(*GtileTexture);
				animatorTiles[i].Animate(sf::Vector2i(0, 1), sf::Vector2i(7, 1), 100);
			}
			if (map[i] == 4)
			{
				tiles[i].setTexture(*YtileTexture);
				animatorTiles[i].Animate(sf::Vector2i(0, 2), sf::Vector2i(7, 2), 100);
			}

		}

		std::cout << "\n";
	}
}



void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	// In here I was only testing to print out the mouse position in the console.	
	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
	//std::cout << mousePosition.x << " " << mousePosition.y << //" " << mouseOnTileX << " " << mouseOnTileY << " " << i << std::endl;

	
	// Over here we created a new window that will include the buttons of every tile.
	// Once any of the buttons are clicked, the value of the chosentile will change according to what tile was chosen. since each tile will represent a number, and we must also include the texture of these tiles.
	ImGui::Begin("Main Menu");

		/*if (ImGui::Button("Save"))
		{
		SaveLoad::Save("map.txt", map, 11, 16);
		}*/
		if (ImGui::Button("Level 1"))
		{
		SaveLoad::Load("map.txt", map, 176);
		scenemanager.Loadscene(1);
		}
		if (ImGui::Button("Level 2"))
		{
			SaveLoad::Load("map2.txt", map, 176);
			scenemanager.Loadscene(2);
		}
		if (ImGui::Button("Exit"))
		{
			m_running = false;
		}
		
	
	ImGui::End();


	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	sf::Vector2f offsetMousePosition = sf::Vector2f(mousePosition.x + -492, mousePosition.y + -184);// it was -500 and -210
	
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&

		
		// In here we are assigning what we can call the borders of the grid..To be able to draw tiles inside the grid and inside only. if we draw tiles outside. it may crash the software.
		mousePosition.x >= 499 && mousePosition.x <= 1399 &&
		mousePosition.y >= 180 && mousePosition.y <= 661)
	{		
		int mouseOnTileX = offsetMousePosition.x / 81.70;
		int mouseOnTileY = offsetMousePosition.y / 30;

		int i = mouseOnTileX + mouseOnTileY * 11;
	
		// In here we are assigning each ID to its own tile, 1 will be the Cyan tile, 2 will be red, etc..
		if(chosenTile == 1)
		{
			tiles[i].setTexture(*CtileTexture);
			map[i] = 1;
		}

		if (chosenTile == 2)
		{
			tiles[i].setTexture(*RtileTexture);
			map[i] = 2;
		}
		if (chosenTile == 3)
		{
			tiles[i].setTexture(*GtileTexture);
			map[i] = 3;
		}
		if (chosenTile == 4)
		{
			tiles[i].setTexture(*YtileTexture);
			map[i] = 4;
		}
	}

	/*for (size_t i = 0; i < 176; i++)
	{
		animatorTiles[i].Update();
	}*/

	scenemanager.update();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	//grid.Render(m_window);

	/*m_window.draw(Ctile);
	m_window.draw(Rtile);
	m_window.draw(Gtile);
	m_window.draw(Ytile);
	m_window.draw(BRtile);
	m_window.draw(GRtile);
	m_window.draw(BDRtile);
	m_window.draw(RDRtile);*/
	
	/*for (size_t i = 0; i < 176; i++)
	{
		//m_window.draw(tiles[i]);
		animatorTiles[i].Render(m_window);
	}*/
	scenemanager.Render(m_window);
	
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

