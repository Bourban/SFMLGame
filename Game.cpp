#include "Game.h"
#include <iostream>




Game::Game()
{
	
}

void Game::initialise()
{
	isGameOver = false;
	screenHeight = 720;
	screenWidth = 1280;
	appName = "Mantis Toboggan, M.D.";

	window.create(sf::VideoMode(screenWidth, screenHeight), appName);

	pls.setFillColor(sf::Color::Transparent);
	pls.setOutlineThickness(1);
	pls.setOutlineColor(sf::Color::Black);

}



void Game::runGameLoop()
{
	loadContent();
	initialise();


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsed = clock.restart();
		update(elapsed);
		
		render();

	}

	unloadContent();

}

void Game::render()
{
	window.clear(sf::Color::Color(40, 40, 100));

	//call each object's own render function here
	//if not add all objects to a list and draw all the list
	window.draw(player);
	window.draw(pls);

	window.display();
}

void Game::update(sf::Time delta)
{
	//call each object's own update function here
	player.update(delta);
	

	pls.setSize(sf::Vector2f(player.boundingBox.width, player.boundingBox.height));
	pls.setPosition(player.boundingBox.left, player.boundingBox.top);

	
}

void Game::loadContent()
{
	if (!playerTexture.loadFromFile("Assets/Sprites/shipWhite.png"))
	{
		// error...
	}

	player.setTexture(playerTexture);
}

void Game::unloadContent()
{
}

void Game::playerFiring()
{
	if (player.hasFiredLeft()) {

	}
	else if (player.hasFiredRight())
	{

	}
}

void Game::generatePickup()
{
	Pickup pickup = Pickup();
	pickups.push_back(pickup);


}



Game::~Game()
{
}


