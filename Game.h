#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Player.h"
#include "Pickup.h"
#include "Cannonball.h"
#include "PlayerControls.h"

class Game
{
public:
	Game();
	~Game();

	void runGameLoop();

	void render();
	void update(sf::Time delta);

	void initialise();
	void loadContent();
	void unloadContent();


private:
	const float TIME_PER_UPDATE = 0.016f;

	bool isGameOver;

	sf::Clock clock;
	sf::Time elapsed;

	//Other Entities (Pickups, items)
	std::vector<Pickup> pickups;
	std::vector<Cannonball> cannonballs;

	//Textures
	sf::Texture pickupTexture;
	sf::Texture playerTexture;
	sf::Texture CannonballTexture;

	//Player Stuff
	Player player;
	//handles instantiating cannonballs
	void playerFiring();

	
	sf::RectangleShape pls;

	//SFML Window Stuff
	sf::RenderWindow window;
	std::string appName;
	int screenHeight;
	int screenWidth;

	//Fucntions

	void generatePickup();


};

